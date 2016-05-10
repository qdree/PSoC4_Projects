#include "LiquidCrystal_I2C.h"


//Portado para PSoC por Šarūnas Straigis
//http://www.element14.com/community/people/sarunaszx/blog
//Portado y modificado para PSoC 4 y PSoC 5LP por Brayan Bermudez y Carlos Diaz
//http://digitalprojectsudistrital.blogspot.com.co/



// When the display powers up, it is configured as follows:
//
// 1. Display clear
// 2. Function set: 
//    DL = 1; 8-bit interface data 
//    N = 0; 1-line display 
//    F = 0; 5x8 dot character font 
// 3. Display on/off control: 
//    D = 0; Display off 
//    C = 0; Cursor off 
//    B = 0; Blinking off 
// 4. Entry mode set: 
//    I/D = 1; Increment by 1
//    S = 0; No shift 
//
// Note, however, that resetting the Arduino doesn't reset the LCD, so we
// can't assume that its in that state when a sketch starts (and the
// LiquidCrystal constructor is called).

uint8_t _addr;
uint8_t _displayfunction;
uint8_t _displaycontrol;
uint8_t _displaymode;
uint8_t _cols;
uint8_t _rows;
uint8_t _charsize;
uint8_t _backlightval;

void LiquidCrystal_I2C_init(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows, uint8_t charsize)
{
	_addr = lcd_addr;
	_cols = lcd_cols;
	_rows = lcd_rows;
	_charsize = charsize;
	_backlightval = LCD_BACKLIGHT;
    
    return;
}

void begin(void){
  
	_displayfunction = LCD_4BITMODE | LCD_1LINE | LCD_5x8DOTS;

	if (_rows > 1) {
		_displayfunction |= LCD_2LINE;
	}

	// for some 1 line displays you can select a 10 pixel high font
	if ((_charsize != 0) && (_rows == 1)) {
		_displayfunction |= LCD_5x10DOTS;
	}

	// SEE PAGE 45/46 FOR INITIALIZATION SPECIFICATION!
	// according to datasheet, we need at least 40ms after power rises above 2.7V
	// before sending commands. Arduino can turn on way befer 4.5V so we'll wait 50
	CyDelay(50); 

	// Now we pull both RS and R/W low to begin commands
	expanderWrite(_backlightval);	// reset expanderand turn backlight off (Bit 8 =1)
	CyDelay(1000);

	//put the LCD into 4 bit mode
	// this is according to the hitachi HD44780 datasheet
	// figure 24, pg 46

	// we start in 8bit mode, try to set 4 bit mode
	write4bits(0x03 << 4);
	CyDelayUs(4500); // wait min 4.1ms

	// second try
	write4bits(0x03 << 4);
	CyDelayUs(4500); // wait min 4.1ms

	// third go!
	write4bits(0x03 << 4); 
	CyDelayUs(150);

	// finally, set to 4-bit interface
	write4bits(0x02 << 4); 

	// set # lines, font size, etc.
	command(LCD_FUNCTIONSET | _displayfunction);  
	
	// turn the display on with no cursor or blinking default
	_displaycontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;
	display();
	
	// clear it off
	clear();
	
	// Initialize to default text direction (for roman languages)
	_displaymode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
	
	// set the entry mode
	command(LCD_ENTRYMODESET | _displaymode);
	
	home();
    
    return;
}

/********** high level commands, for the user! */
void clear(void){
    
	command(LCD_CLEARDISPLAY);// clear display, set cursor position to zero
	CyDelay(2);  // this command takes a long time!
    
    return;
}

void home(void){
	
    command(LCD_RETURNHOME);  // set cursor position to zero
	CyDelay(2);  // this command takes a long time!
    
    return;
}

void setCursor(uint8_t col, uint8_t row){
    
	int row_offsets[] = { 0x00, 0x40, 0x14, 0x54 };
	if (row > _rows) {
		row = _rows-1;    // we count rows starting w/0
	}
	command(LCD_SETDDRAMADDR | (col + row_offsets[row]));
    
    return;
}

// Turn the display on/off (quickly)
void noDisplay(void){
	
    _displaycontrol &= ~LCD_DISPLAYON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
    
    return;
}
void display(void){
    
	_displaycontrol |= LCD_DISPLAYON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
    
    return;
}

// Turns the underline cursor on/off
void noCursor(void){
	
    _displaycontrol &= ~LCD_CURSORON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
    
    return;
}
void cursor(void){
	
    _displaycontrol |= LCD_CURSORON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
    
    return;
}

// Turn on and off the blinking cursor
void noBlink(void){
	
    _displaycontrol &= ~LCD_BLINKON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
    
    return;
}
void blink(void){
    
	_displaycontrol |= LCD_BLINKON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
    
    return;
}

// These commands scroll the display without changing the RAM
void scrollDisplayLeft(void){
    
	command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVELEFT);
    
    return;
}
void scrollDisplayRight(void){
	
    command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVERIGHT);
    
    return;
}

// This is for text that flows Left to Right
void leftToRight(void){
    
	_displaymode |= LCD_ENTRYLEFT;
	command(LCD_ENTRYMODESET | _displaymode);
    
    return;
}

// This is for text that flows Right to Left
void rightToLeft(void){
    
	_displaymode &= ~LCD_ENTRYLEFT;
	command(LCD_ENTRYMODESET | _displaymode);
    
    return;
}

// This will 'right justify' text from the cursor
void autoscroll(void){
	
    _displaymode |= LCD_ENTRYSHIFTINCREMENT;
	command(LCD_ENTRYMODESET | _displaymode);
    
    return;
}

// This will 'left justify' text from the cursor
void noAutoscroll(void){
	
    _displaymode &= ~LCD_ENTRYSHIFTINCREMENT;
	command(LCD_ENTRYMODESET | _displaymode);
    
    return;
}

// Allows us to fill the first 8 CGRAM locations
// with custom characters
void createChar(uint8_t location, uint8_t charmap[]){ uint32_t i = 0;
	
    location &= 0x7; // we only have 8 locations 0-7
	command(LCD_SETCGRAMADDR | (location << 3));
	for (i=0; i<8; i++) {
		write(charmap[i]);
	}
    
    return;
}

// Turn the (optional) backlight off/on
void noBacklight(void) {
	
    _backlightval=LCD_NOBACKLIGHT;
	expanderWrite(0);
    
    return;
}

void backlight(void){
    
	_backlightval=LCD_BACKLIGHT;
	expanderWrite(0);
    
    return;
}

/*********** mid level commands, for sending data/cmds */

void command(uint8_t value){
	
    send(value, 0);
    
    return;
}

 void write(uint8_t value){
    
	send(value, Rs);
    
    return;
}


/************ low level data pushing commands **********/

// write either command or data
void send(uint8_t value, uint8_t mode){
    
	uint8_t highnib=value&0xf0;
	uint8_t lownib=(value<<4)&0xf0;
	write4bits((highnib)|mode);
	write4bits((lownib)|mode); 
    
    return;
}

void write4bits(uint8_t value) {
    
	expanderWrite(value);
	pulseEnable(value);
    
    return;
}

void expanderWrite(uint8_t _data){     
    
	I2C_M_write_byte(_addr,_data | _backlightval);	   
    
    return;
}

void pulseEnable(uint8_t _data){
    
	expanderWrite(_data | En);	// En high
	CyDelayUs(1);		// enable pulse must be >450ns
	expanderWrite(_data & ~En);	// En low
	CyDelayUs(50);		// commands need > 37us to settle
    
    return;
}

void load_custom_character(uint8_t char_num, uint8_t *rows){
	
    createChar(char_num, rows);
    
    return;
}

void setBacklight(uint8_t new_val){
    
	if (new_val) {
		backlight();		// turn backlight on
	} else {
		noBacklight();		// turn backlight off
	}
    
    return;
}

void LCD_print(char word[]){ 
    
    uint32_t i = 0;
    
    uint8_t size = strlen(word);
    
    for (i = 0; i < size; i++){
        write(word[i]);
    }

    return;
}

void I2C_M_write_byte(uint8_t addr,uint8_t data){ 

#if CY_PSOC5
    I2C_MasterSendStart(addr, 0);
    I2C_MasterWriteByte(data);
    I2C_MasterSendStop();
#elif CY_PSOC4
    I2C_I2CMasterSendStart(addr, 0);
    I2C_I2CMasterWriteByte(data);
    I2C_I2CMasterSendStop();
#endif
    
    return;
}
