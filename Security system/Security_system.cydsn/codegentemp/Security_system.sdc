# THIS FILE IS AUTOMATICALLY GENERATED
# Project: E:\744\Education\Git\PSoC4_Projects\Security system\Security_system.cydsn\Security_system.cyprj
# Date: Tue, 24 May 2016 20:10:18 GMT
#set_units -time ns
create_clock -name {UART_SCBCLK(FFB)} -period 8666.6666666666661 -waveform {0 4333.33333333333} [list [get_pins {ClockBlock/ff_div_2}]]
create_clock -name {I2C_SCBCLK(FFB)} -period 875 -waveform {0 437.5} [list [get_pins {ClockBlock/ff_div_3}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {UART_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 209 417} -nominal_period 8666.6666666666661 [list]
create_generated_clock -name {I2C_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 21 43} [list]


# Component constraints for E:\744\Education\Git\PSoC4_Projects\Security system\Security_system.cydsn\TopDesign\TopDesign.cysch
# Project: E:\744\Education\Git\PSoC4_Projects\Security system\Security_system.cydsn\Security_system.cyprj
# Date: Tue, 24 May 2016 20:10:16 GMT
