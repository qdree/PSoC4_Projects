.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu_trm.inc"

/* red */
.set red__0__DM__MASK, 0x1C0000
.set red__0__DM__SHIFT, 18
.set red__0__DR, CYREG_PRT1_DR
.set red__0__HSIOM, CYREG_HSIOM_PORT_SEL1
.set red__0__HSIOM_MASK, 0x0F000000
.set red__0__HSIOM_SHIFT, 24
.set red__0__INTCFG, CYREG_PRT1_INTCFG
.set red__0__INTSTAT, CYREG_PRT1_INTSTAT
.set red__0__MASK, 0x40
.set red__0__PA__CFG0, CYREG_UDB_PA1_CFG0
.set red__0__PA__CFG1, CYREG_UDB_PA1_CFG1
.set red__0__PA__CFG10, CYREG_UDB_PA1_CFG10
.set red__0__PA__CFG11, CYREG_UDB_PA1_CFG11
.set red__0__PA__CFG12, CYREG_UDB_PA1_CFG12
.set red__0__PA__CFG13, CYREG_UDB_PA1_CFG13
.set red__0__PA__CFG14, CYREG_UDB_PA1_CFG14
.set red__0__PA__CFG2, CYREG_UDB_PA1_CFG2
.set red__0__PA__CFG3, CYREG_UDB_PA1_CFG3
.set red__0__PA__CFG4, CYREG_UDB_PA1_CFG4
.set red__0__PA__CFG5, CYREG_UDB_PA1_CFG5
.set red__0__PA__CFG6, CYREG_UDB_PA1_CFG6
.set red__0__PA__CFG7, CYREG_UDB_PA1_CFG7
.set red__0__PA__CFG8, CYREG_UDB_PA1_CFG8
.set red__0__PA__CFG9, CYREG_UDB_PA1_CFG9
.set red__0__PC, CYREG_PRT1_PC
.set red__0__PC2, CYREG_PRT1_PC2
.set red__0__PORT, 1
.set red__0__PS, CYREG_PRT1_PS
.set red__0__SHIFT, 6
.set red__DR, CYREG_PRT1_DR
.set red__INTCFG, CYREG_PRT1_INTCFG
.set red__INTSTAT, CYREG_PRT1_INTSTAT
.set red__MASK, 0x40
.set red__PA__CFG0, CYREG_UDB_PA1_CFG0
.set red__PA__CFG1, CYREG_UDB_PA1_CFG1
.set red__PA__CFG10, CYREG_UDB_PA1_CFG10
.set red__PA__CFG11, CYREG_UDB_PA1_CFG11
.set red__PA__CFG12, CYREG_UDB_PA1_CFG12
.set red__PA__CFG13, CYREG_UDB_PA1_CFG13
.set red__PA__CFG14, CYREG_UDB_PA1_CFG14
.set red__PA__CFG2, CYREG_UDB_PA1_CFG2
.set red__PA__CFG3, CYREG_UDB_PA1_CFG3
.set red__PA__CFG4, CYREG_UDB_PA1_CFG4
.set red__PA__CFG5, CYREG_UDB_PA1_CFG5
.set red__PA__CFG6, CYREG_UDB_PA1_CFG6
.set red__PA__CFG7, CYREG_UDB_PA1_CFG7
.set red__PA__CFG8, CYREG_UDB_PA1_CFG8
.set red__PA__CFG9, CYREG_UDB_PA1_CFG9
.set red__PC, CYREG_PRT1_PC
.set red__PC2, CYREG_PRT1_PC2
.set red__PORT, 1
.set red__PS, CYREG_PRT1_PS
.set red__SHIFT, 6

/* blue */
.set blue__0__DM__MASK, 0xE00
.set blue__0__DM__SHIFT, 9
.set blue__0__DR, CYREG_PRT0_DR
.set blue__0__HSIOM, CYREG_HSIOM_PORT_SEL0
.set blue__0__HSIOM_MASK, 0x0000F000
.set blue__0__HSIOM_SHIFT, 12
.set blue__0__INTCFG, CYREG_PRT0_INTCFG
.set blue__0__INTSTAT, CYREG_PRT0_INTSTAT
.set blue__0__MASK, 0x08
.set blue__0__PA__CFG0, CYREG_UDB_PA0_CFG0
.set blue__0__PA__CFG1, CYREG_UDB_PA0_CFG1
.set blue__0__PA__CFG10, CYREG_UDB_PA0_CFG10
.set blue__0__PA__CFG11, CYREG_UDB_PA0_CFG11
.set blue__0__PA__CFG12, CYREG_UDB_PA0_CFG12
.set blue__0__PA__CFG13, CYREG_UDB_PA0_CFG13
.set blue__0__PA__CFG14, CYREG_UDB_PA0_CFG14
.set blue__0__PA__CFG2, CYREG_UDB_PA0_CFG2
.set blue__0__PA__CFG3, CYREG_UDB_PA0_CFG3
.set blue__0__PA__CFG4, CYREG_UDB_PA0_CFG4
.set blue__0__PA__CFG5, CYREG_UDB_PA0_CFG5
.set blue__0__PA__CFG6, CYREG_UDB_PA0_CFG6
.set blue__0__PA__CFG7, CYREG_UDB_PA0_CFG7
.set blue__0__PA__CFG8, CYREG_UDB_PA0_CFG8
.set blue__0__PA__CFG9, CYREG_UDB_PA0_CFG9
.set blue__0__PC, CYREG_PRT0_PC
.set blue__0__PC2, CYREG_PRT0_PC2
.set blue__0__PORT, 0
.set blue__0__PS, CYREG_PRT0_PS
.set blue__0__SHIFT, 3
.set blue__DR, CYREG_PRT0_DR
.set blue__INTCFG, CYREG_PRT0_INTCFG
.set blue__INTSTAT, CYREG_PRT0_INTSTAT
.set blue__MASK, 0x08
.set blue__PA__CFG0, CYREG_UDB_PA0_CFG0
.set blue__PA__CFG1, CYREG_UDB_PA0_CFG1
.set blue__PA__CFG10, CYREG_UDB_PA0_CFG10
.set blue__PA__CFG11, CYREG_UDB_PA0_CFG11
.set blue__PA__CFG12, CYREG_UDB_PA0_CFG12
.set blue__PA__CFG13, CYREG_UDB_PA0_CFG13
.set blue__PA__CFG14, CYREG_UDB_PA0_CFG14
.set blue__PA__CFG2, CYREG_UDB_PA0_CFG2
.set blue__PA__CFG3, CYREG_UDB_PA0_CFG3
.set blue__PA__CFG4, CYREG_UDB_PA0_CFG4
.set blue__PA__CFG5, CYREG_UDB_PA0_CFG5
.set blue__PA__CFG6, CYREG_UDB_PA0_CFG6
.set blue__PA__CFG7, CYREG_UDB_PA0_CFG7
.set blue__PA__CFG8, CYREG_UDB_PA0_CFG8
.set blue__PA__CFG9, CYREG_UDB_PA0_CFG9
.set blue__PC, CYREG_PRT0_PC
.set blue__PC2, CYREG_PRT0_PC2
.set blue__PORT, 0
.set blue__PS, CYREG_PRT0_PS
.set blue__SHIFT, 3

/* pir1 */
.set pir1__0__DM__MASK, 0x38000
.set pir1__0__DM__SHIFT, 15
.set pir1__0__DR, CYREG_PRT2_DR
.set pir1__0__HSIOM, CYREG_HSIOM_PORT_SEL2
.set pir1__0__HSIOM_MASK, 0x00F00000
.set pir1__0__HSIOM_SHIFT, 20
.set pir1__0__INTCFG, CYREG_PRT2_INTCFG
.set pir1__0__INTSTAT, CYREG_PRT2_INTSTAT
.set pir1__0__MASK, 0x20
.set pir1__0__PA__CFG0, CYREG_UDB_PA2_CFG0
.set pir1__0__PA__CFG1, CYREG_UDB_PA2_CFG1
.set pir1__0__PA__CFG10, CYREG_UDB_PA2_CFG10
.set pir1__0__PA__CFG11, CYREG_UDB_PA2_CFG11
.set pir1__0__PA__CFG12, CYREG_UDB_PA2_CFG12
.set pir1__0__PA__CFG13, CYREG_UDB_PA2_CFG13
.set pir1__0__PA__CFG14, CYREG_UDB_PA2_CFG14
.set pir1__0__PA__CFG2, CYREG_UDB_PA2_CFG2
.set pir1__0__PA__CFG3, CYREG_UDB_PA2_CFG3
.set pir1__0__PA__CFG4, CYREG_UDB_PA2_CFG4
.set pir1__0__PA__CFG5, CYREG_UDB_PA2_CFG5
.set pir1__0__PA__CFG6, CYREG_UDB_PA2_CFG6
.set pir1__0__PA__CFG7, CYREG_UDB_PA2_CFG7
.set pir1__0__PA__CFG8, CYREG_UDB_PA2_CFG8
.set pir1__0__PA__CFG9, CYREG_UDB_PA2_CFG9
.set pir1__0__PC, CYREG_PRT2_PC
.set pir1__0__PC2, CYREG_PRT2_PC2
.set pir1__0__PORT, 2
.set pir1__0__PS, CYREG_PRT2_PS
.set pir1__0__SHIFT, 5
.set pir1__DR, CYREG_PRT2_DR
.set pir1__INTCFG, CYREG_PRT2_INTCFG
.set pir1__INTSTAT, CYREG_PRT2_INTSTAT
.set pir1__MASK, 0x20
.set pir1__PA__CFG0, CYREG_UDB_PA2_CFG0
.set pir1__PA__CFG1, CYREG_UDB_PA2_CFG1
.set pir1__PA__CFG10, CYREG_UDB_PA2_CFG10
.set pir1__PA__CFG11, CYREG_UDB_PA2_CFG11
.set pir1__PA__CFG12, CYREG_UDB_PA2_CFG12
.set pir1__PA__CFG13, CYREG_UDB_PA2_CFG13
.set pir1__PA__CFG14, CYREG_UDB_PA2_CFG14
.set pir1__PA__CFG2, CYREG_UDB_PA2_CFG2
.set pir1__PA__CFG3, CYREG_UDB_PA2_CFG3
.set pir1__PA__CFG4, CYREG_UDB_PA2_CFG4
.set pir1__PA__CFG5, CYREG_UDB_PA2_CFG5
.set pir1__PA__CFG6, CYREG_UDB_PA2_CFG6
.set pir1__PA__CFG7, CYREG_UDB_PA2_CFG7
.set pir1__PA__CFG8, CYREG_UDB_PA2_CFG8
.set pir1__PA__CFG9, CYREG_UDB_PA2_CFG9
.set pir1__PC, CYREG_PRT2_PC
.set pir1__PC2, CYREG_PRT2_PC2
.set pir1__PORT, 2
.set pir1__PS, CYREG_PRT2_PS
.set pir1__SHIFT, 5

/* pir2 */
.set pir2__0__DM__MASK, 0x7000
.set pir2__0__DM__SHIFT, 12
.set pir2__0__DR, CYREG_PRT2_DR
.set pir2__0__HSIOM, CYREG_HSIOM_PORT_SEL2
.set pir2__0__HSIOM_MASK, 0x000F0000
.set pir2__0__HSIOM_SHIFT, 16
.set pir2__0__INTCFG, CYREG_PRT2_INTCFG
.set pir2__0__INTSTAT, CYREG_PRT2_INTSTAT
.set pir2__0__MASK, 0x10
.set pir2__0__PA__CFG0, CYREG_UDB_PA2_CFG0
.set pir2__0__PA__CFG1, CYREG_UDB_PA2_CFG1
.set pir2__0__PA__CFG10, CYREG_UDB_PA2_CFG10
.set pir2__0__PA__CFG11, CYREG_UDB_PA2_CFG11
.set pir2__0__PA__CFG12, CYREG_UDB_PA2_CFG12
.set pir2__0__PA__CFG13, CYREG_UDB_PA2_CFG13
.set pir2__0__PA__CFG14, CYREG_UDB_PA2_CFG14
.set pir2__0__PA__CFG2, CYREG_UDB_PA2_CFG2
.set pir2__0__PA__CFG3, CYREG_UDB_PA2_CFG3
.set pir2__0__PA__CFG4, CYREG_UDB_PA2_CFG4
.set pir2__0__PA__CFG5, CYREG_UDB_PA2_CFG5
.set pir2__0__PA__CFG6, CYREG_UDB_PA2_CFG6
.set pir2__0__PA__CFG7, CYREG_UDB_PA2_CFG7
.set pir2__0__PA__CFG8, CYREG_UDB_PA2_CFG8
.set pir2__0__PA__CFG9, CYREG_UDB_PA2_CFG9
.set pir2__0__PC, CYREG_PRT2_PC
.set pir2__0__PC2, CYREG_PRT2_PC2
.set pir2__0__PORT, 2
.set pir2__0__PS, CYREG_PRT2_PS
.set pir2__0__SHIFT, 4
.set pir2__DR, CYREG_PRT2_DR
.set pir2__INTCFG, CYREG_PRT2_INTCFG
.set pir2__INTSTAT, CYREG_PRT2_INTSTAT
.set pir2__MASK, 0x10
.set pir2__PA__CFG0, CYREG_UDB_PA2_CFG0
.set pir2__PA__CFG1, CYREG_UDB_PA2_CFG1
.set pir2__PA__CFG10, CYREG_UDB_PA2_CFG10
.set pir2__PA__CFG11, CYREG_UDB_PA2_CFG11
.set pir2__PA__CFG12, CYREG_UDB_PA2_CFG12
.set pir2__PA__CFG13, CYREG_UDB_PA2_CFG13
.set pir2__PA__CFG14, CYREG_UDB_PA2_CFG14
.set pir2__PA__CFG2, CYREG_UDB_PA2_CFG2
.set pir2__PA__CFG3, CYREG_UDB_PA2_CFG3
.set pir2__PA__CFG4, CYREG_UDB_PA2_CFG4
.set pir2__PA__CFG5, CYREG_UDB_PA2_CFG5
.set pir2__PA__CFG6, CYREG_UDB_PA2_CFG6
.set pir2__PA__CFG7, CYREG_UDB_PA2_CFG7
.set pir2__PA__CFG8, CYREG_UDB_PA2_CFG8
.set pir2__PA__CFG9, CYREG_UDB_PA2_CFG9
.set pir2__PC, CYREG_PRT2_PC
.set pir2__PC2, CYREG_PRT2_PC2
.set pir2__PORT, 2
.set pir2__PS, CYREG_PRT2_PS
.set pir2__SHIFT, 4

/* pir3 */
.set pir3__0__DM__MASK, 0xE00
.set pir3__0__DM__SHIFT, 9
.set pir3__0__DR, CYREG_PRT2_DR
.set pir3__0__HSIOM, CYREG_HSIOM_PORT_SEL2
.set pir3__0__HSIOM_MASK, 0x0000F000
.set pir3__0__HSIOM_SHIFT, 12
.set pir3__0__INTCFG, CYREG_PRT2_INTCFG
.set pir3__0__INTSTAT, CYREG_PRT2_INTSTAT
.set pir3__0__MASK, 0x08
.set pir3__0__PA__CFG0, CYREG_UDB_PA2_CFG0
.set pir3__0__PA__CFG1, CYREG_UDB_PA2_CFG1
.set pir3__0__PA__CFG10, CYREG_UDB_PA2_CFG10
.set pir3__0__PA__CFG11, CYREG_UDB_PA2_CFG11
.set pir3__0__PA__CFG12, CYREG_UDB_PA2_CFG12
.set pir3__0__PA__CFG13, CYREG_UDB_PA2_CFG13
.set pir3__0__PA__CFG14, CYREG_UDB_PA2_CFG14
.set pir3__0__PA__CFG2, CYREG_UDB_PA2_CFG2
.set pir3__0__PA__CFG3, CYREG_UDB_PA2_CFG3
.set pir3__0__PA__CFG4, CYREG_UDB_PA2_CFG4
.set pir3__0__PA__CFG5, CYREG_UDB_PA2_CFG5
.set pir3__0__PA__CFG6, CYREG_UDB_PA2_CFG6
.set pir3__0__PA__CFG7, CYREG_UDB_PA2_CFG7
.set pir3__0__PA__CFG8, CYREG_UDB_PA2_CFG8
.set pir3__0__PA__CFG9, CYREG_UDB_PA2_CFG9
.set pir3__0__PC, CYREG_PRT2_PC
.set pir3__0__PC2, CYREG_PRT2_PC2
.set pir3__0__PORT, 2
.set pir3__0__PS, CYREG_PRT2_PS
.set pir3__0__SHIFT, 3
.set pir3__DR, CYREG_PRT2_DR
.set pir3__INTCFG, CYREG_PRT2_INTCFG
.set pir3__INTSTAT, CYREG_PRT2_INTSTAT
.set pir3__MASK, 0x08
.set pir3__PA__CFG0, CYREG_UDB_PA2_CFG0
.set pir3__PA__CFG1, CYREG_UDB_PA2_CFG1
.set pir3__PA__CFG10, CYREG_UDB_PA2_CFG10
.set pir3__PA__CFG11, CYREG_UDB_PA2_CFG11
.set pir3__PA__CFG12, CYREG_UDB_PA2_CFG12
.set pir3__PA__CFG13, CYREG_UDB_PA2_CFG13
.set pir3__PA__CFG14, CYREG_UDB_PA2_CFG14
.set pir3__PA__CFG2, CYREG_UDB_PA2_CFG2
.set pir3__PA__CFG3, CYREG_UDB_PA2_CFG3
.set pir3__PA__CFG4, CYREG_UDB_PA2_CFG4
.set pir3__PA__CFG5, CYREG_UDB_PA2_CFG5
.set pir3__PA__CFG6, CYREG_UDB_PA2_CFG6
.set pir3__PA__CFG7, CYREG_UDB_PA2_CFG7
.set pir3__PA__CFG8, CYREG_UDB_PA2_CFG8
.set pir3__PA__CFG9, CYREG_UDB_PA2_CFG9
.set pir3__PC, CYREG_PRT2_PC
.set pir3__PC2, CYREG_PRT2_PC2
.set pir3__PORT, 2
.set pir3__PS, CYREG_PRT2_PS
.set pir3__SHIFT, 3

/* pir4 */
.set pir4__0__DM__MASK, 0x1C0
.set pir4__0__DM__SHIFT, 6
.set pir4__0__DR, CYREG_PRT2_DR
.set pir4__0__HSIOM, CYREG_HSIOM_PORT_SEL2
.set pir4__0__HSIOM_MASK, 0x00000F00
.set pir4__0__HSIOM_SHIFT, 8
.set pir4__0__INTCFG, CYREG_PRT2_INTCFG
.set pir4__0__INTSTAT, CYREG_PRT2_INTSTAT
.set pir4__0__MASK, 0x04
.set pir4__0__PA__CFG0, CYREG_UDB_PA2_CFG0
.set pir4__0__PA__CFG1, CYREG_UDB_PA2_CFG1
.set pir4__0__PA__CFG10, CYREG_UDB_PA2_CFG10
.set pir4__0__PA__CFG11, CYREG_UDB_PA2_CFG11
.set pir4__0__PA__CFG12, CYREG_UDB_PA2_CFG12
.set pir4__0__PA__CFG13, CYREG_UDB_PA2_CFG13
.set pir4__0__PA__CFG14, CYREG_UDB_PA2_CFG14
.set pir4__0__PA__CFG2, CYREG_UDB_PA2_CFG2
.set pir4__0__PA__CFG3, CYREG_UDB_PA2_CFG3
.set pir4__0__PA__CFG4, CYREG_UDB_PA2_CFG4
.set pir4__0__PA__CFG5, CYREG_UDB_PA2_CFG5
.set pir4__0__PA__CFG6, CYREG_UDB_PA2_CFG6
.set pir4__0__PA__CFG7, CYREG_UDB_PA2_CFG7
.set pir4__0__PA__CFG8, CYREG_UDB_PA2_CFG8
.set pir4__0__PA__CFG9, CYREG_UDB_PA2_CFG9
.set pir4__0__PC, CYREG_PRT2_PC
.set pir4__0__PC2, CYREG_PRT2_PC2
.set pir4__0__PORT, 2
.set pir4__0__PS, CYREG_PRT2_PS
.set pir4__0__SHIFT, 2
.set pir4__DR, CYREG_PRT2_DR
.set pir4__INTCFG, CYREG_PRT2_INTCFG
.set pir4__INTSTAT, CYREG_PRT2_INTSTAT
.set pir4__MASK, 0x04
.set pir4__PA__CFG0, CYREG_UDB_PA2_CFG0
.set pir4__PA__CFG1, CYREG_UDB_PA2_CFG1
.set pir4__PA__CFG10, CYREG_UDB_PA2_CFG10
.set pir4__PA__CFG11, CYREG_UDB_PA2_CFG11
.set pir4__PA__CFG12, CYREG_UDB_PA2_CFG12
.set pir4__PA__CFG13, CYREG_UDB_PA2_CFG13
.set pir4__PA__CFG14, CYREG_UDB_PA2_CFG14
.set pir4__PA__CFG2, CYREG_UDB_PA2_CFG2
.set pir4__PA__CFG3, CYREG_UDB_PA2_CFG3
.set pir4__PA__CFG4, CYREG_UDB_PA2_CFG4
.set pir4__PA__CFG5, CYREG_UDB_PA2_CFG5
.set pir4__PA__CFG6, CYREG_UDB_PA2_CFG6
.set pir4__PA__CFG7, CYREG_UDB_PA2_CFG7
.set pir4__PA__CFG8, CYREG_UDB_PA2_CFG8
.set pir4__PA__CFG9, CYREG_UDB_PA2_CFG9
.set pir4__PC, CYREG_PRT2_PC
.set pir4__PC2, CYREG_PRT2_PC2
.set pir4__PORT, 2
.set pir4__PS, CYREG_PRT2_PS
.set pir4__SHIFT, 2

/* green */
.set green__0__DM__MASK, 0x1C0
.set green__0__DM__SHIFT, 6
.set green__0__DR, CYREG_PRT0_DR
.set green__0__HSIOM, CYREG_HSIOM_PORT_SEL0
.set green__0__HSIOM_MASK, 0x00000F00
.set green__0__HSIOM_SHIFT, 8
.set green__0__INTCFG, CYREG_PRT0_INTCFG
.set green__0__INTSTAT, CYREG_PRT0_INTSTAT
.set green__0__MASK, 0x04
.set green__0__PA__CFG0, CYREG_UDB_PA0_CFG0
.set green__0__PA__CFG1, CYREG_UDB_PA0_CFG1
.set green__0__PA__CFG10, CYREG_UDB_PA0_CFG10
.set green__0__PA__CFG11, CYREG_UDB_PA0_CFG11
.set green__0__PA__CFG12, CYREG_UDB_PA0_CFG12
.set green__0__PA__CFG13, CYREG_UDB_PA0_CFG13
.set green__0__PA__CFG14, CYREG_UDB_PA0_CFG14
.set green__0__PA__CFG2, CYREG_UDB_PA0_CFG2
.set green__0__PA__CFG3, CYREG_UDB_PA0_CFG3
.set green__0__PA__CFG4, CYREG_UDB_PA0_CFG4
.set green__0__PA__CFG5, CYREG_UDB_PA0_CFG5
.set green__0__PA__CFG6, CYREG_UDB_PA0_CFG6
.set green__0__PA__CFG7, CYREG_UDB_PA0_CFG7
.set green__0__PA__CFG8, CYREG_UDB_PA0_CFG8
.set green__0__PA__CFG9, CYREG_UDB_PA0_CFG9
.set green__0__PC, CYREG_PRT0_PC
.set green__0__PC2, CYREG_PRT0_PC2
.set green__0__PORT, 0
.set green__0__PS, CYREG_PRT0_PS
.set green__0__SHIFT, 2
.set green__DR, CYREG_PRT0_DR
.set green__INTCFG, CYREG_PRT0_INTCFG
.set green__INTSTAT, CYREG_PRT0_INTSTAT
.set green__MASK, 0x04
.set green__PA__CFG0, CYREG_UDB_PA0_CFG0
.set green__PA__CFG1, CYREG_UDB_PA0_CFG1
.set green__PA__CFG10, CYREG_UDB_PA0_CFG10
.set green__PA__CFG11, CYREG_UDB_PA0_CFG11
.set green__PA__CFG12, CYREG_UDB_PA0_CFG12
.set green__PA__CFG13, CYREG_UDB_PA0_CFG13
.set green__PA__CFG14, CYREG_UDB_PA0_CFG14
.set green__PA__CFG2, CYREG_UDB_PA0_CFG2
.set green__PA__CFG3, CYREG_UDB_PA0_CFG3
.set green__PA__CFG4, CYREG_UDB_PA0_CFG4
.set green__PA__CFG5, CYREG_UDB_PA0_CFG5
.set green__PA__CFG6, CYREG_UDB_PA0_CFG6
.set green__PA__CFG7, CYREG_UDB_PA0_CFG7
.set green__PA__CFG8, CYREG_UDB_PA0_CFG8
.set green__PA__CFG9, CYREG_UDB_PA0_CFG9
.set green__PC, CYREG_PRT0_PC
.set green__PC2, CYREG_PRT0_PC2
.set green__PORT, 0
.set green__PS, CYREG_PRT0_PS
.set green__SHIFT, 2

/* Front_door */
.set Front_door__0__DM__MASK, 0x7000
.set Front_door__0__DM__SHIFT, 12
.set Front_door__0__DR, CYREG_PRT1_DR
.set Front_door__0__HSIOM, CYREG_HSIOM_PORT_SEL1
.set Front_door__0__HSIOM_MASK, 0x000F0000
.set Front_door__0__HSIOM_SHIFT, 16
.set Front_door__0__INTCFG, CYREG_PRT1_INTCFG
.set Front_door__0__INTSTAT, CYREG_PRT1_INTSTAT
.set Front_door__0__MASK, 0x10
.set Front_door__0__PA__CFG0, CYREG_UDB_PA1_CFG0
.set Front_door__0__PA__CFG1, CYREG_UDB_PA1_CFG1
.set Front_door__0__PA__CFG10, CYREG_UDB_PA1_CFG10
.set Front_door__0__PA__CFG11, CYREG_UDB_PA1_CFG11
.set Front_door__0__PA__CFG12, CYREG_UDB_PA1_CFG12
.set Front_door__0__PA__CFG13, CYREG_UDB_PA1_CFG13
.set Front_door__0__PA__CFG14, CYREG_UDB_PA1_CFG14
.set Front_door__0__PA__CFG2, CYREG_UDB_PA1_CFG2
.set Front_door__0__PA__CFG3, CYREG_UDB_PA1_CFG3
.set Front_door__0__PA__CFG4, CYREG_UDB_PA1_CFG4
.set Front_door__0__PA__CFG5, CYREG_UDB_PA1_CFG5
.set Front_door__0__PA__CFG6, CYREG_UDB_PA1_CFG6
.set Front_door__0__PA__CFG7, CYREG_UDB_PA1_CFG7
.set Front_door__0__PA__CFG8, CYREG_UDB_PA1_CFG8
.set Front_door__0__PA__CFG9, CYREG_UDB_PA1_CFG9
.set Front_door__0__PC, CYREG_PRT1_PC
.set Front_door__0__PC2, CYREG_PRT1_PC2
.set Front_door__0__PORT, 1
.set Front_door__0__PS, CYREG_PRT1_PS
.set Front_door__0__SHIFT, 4
.set Front_door__DR, CYREG_PRT1_DR
.set Front_door__INTCFG, CYREG_PRT1_INTCFG
.set Front_door__INTSTAT, CYREG_PRT1_INTSTAT
.set Front_door__MASK, 0x10
.set Front_door__PA__CFG0, CYREG_UDB_PA1_CFG0
.set Front_door__PA__CFG1, CYREG_UDB_PA1_CFG1
.set Front_door__PA__CFG10, CYREG_UDB_PA1_CFG10
.set Front_door__PA__CFG11, CYREG_UDB_PA1_CFG11
.set Front_door__PA__CFG12, CYREG_UDB_PA1_CFG12
.set Front_door__PA__CFG13, CYREG_UDB_PA1_CFG13
.set Front_door__PA__CFG14, CYREG_UDB_PA1_CFG14
.set Front_door__PA__CFG2, CYREG_UDB_PA1_CFG2
.set Front_door__PA__CFG3, CYREG_UDB_PA1_CFG3
.set Front_door__PA__CFG4, CYREG_UDB_PA1_CFG4
.set Front_door__PA__CFG5, CYREG_UDB_PA1_CFG5
.set Front_door__PA__CFG6, CYREG_UDB_PA1_CFG6
.set Front_door__PA__CFG7, CYREG_UDB_PA1_CFG7
.set Front_door__PA__CFG8, CYREG_UDB_PA1_CFG8
.set Front_door__PA__CFG9, CYREG_UDB_PA1_CFG9
.set Front_door__PC, CYREG_PRT1_PC
.set Front_door__PC2, CYREG_PRT1_PC2
.set Front_door__PORT, 1
.set Front_door__PS, CYREG_PRT1_PS
.set Front_door__SHIFT, 4

/* Miscellaneous */
.set CYDEV_BCLK__HFCLK__HZ, 24000000
.set CYDEV_BCLK__HFCLK__KHZ, 24000
.set CYDEV_BCLK__HFCLK__MHZ, 24
.set CYDEV_BCLK__SYSCLK__HZ, 24000000
.set CYDEV_BCLK__SYSCLK__KHZ, 24000
.set CYDEV_BCLK__SYSCLK__MHZ, 24
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PANTHER, 18
.set CYDEV_CHIP_DIE_PSOC4A, 10
.set CYDEV_CHIP_DIE_PSOC5LP, 17
.set CYDEV_CHIP_DIE_TMA4, 2
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC4
.set CYDEV_CHIP_JTAG_ID, 0x04C81193
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_4A, 10
.set CYDEV_CHIP_MEMBER_4C, 15
.set CYDEV_CHIP_MEMBER_4D, 6
.set CYDEV_CHIP_MEMBER_4E, 4
.set CYDEV_CHIP_MEMBER_4F, 11
.set CYDEV_CHIP_MEMBER_4G, 2
.set CYDEV_CHIP_MEMBER_4H, 9
.set CYDEV_CHIP_MEMBER_4I, 14
.set CYDEV_CHIP_MEMBER_4J, 7
.set CYDEV_CHIP_MEMBER_4K, 8
.set CYDEV_CHIP_MEMBER_4L, 13
.set CYDEV_CHIP_MEMBER_4M, 12
.set CYDEV_CHIP_MEMBER_4N, 5
.set CYDEV_CHIP_MEMBER_4U, 3
.set CYDEV_CHIP_MEMBER_5A, 17
.set CYDEV_CHIP_MEMBER_5B, 16
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_4A
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_MEMBER_USED
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PANTHER_ES0, 0
.set CYDEV_CHIP_REV_PANTHER_ES1, 1
.set CYDEV_CHIP_REV_PANTHER_PRODUCTION, 1
.set CYDEV_CHIP_REV_PSOC4A_ES0, 17
.set CYDEV_CHIP_REV_PSOC4A_PRODUCTION, 17
.set CYDEV_CHIP_REV_PSOC5LP_ES0, 0
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CHIP_REV_TMA4_ES, 17
.set CYDEV_CHIP_REV_TMA4_ES2, 33
.set CYDEV_CHIP_REV_TMA4_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_4A_ES0, 17
.set CYDEV_CHIP_REVISION_4A_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4C_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4D_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4E_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256K, 0
.set CYDEV_CHIP_REVISION_4G_ES, 17
.set CYDEV_CHIP_REVISION_4G_ES2, 33
.set CYDEV_CHIP_REVISION_4G_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4H_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4I_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4J_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4K_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4L_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4M_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4N_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4U_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES0, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_4A_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REVISION_USED
.set CYDEV_CONFIG_READ_ACCELERATOR, 1
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_AllowButWarn
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_DEBUG_PROTECT_KILL, 4
.set CYDEV_DEBUG_PROTECT_OPEN, 1
.set CYDEV_DEBUG_PROTECT, CYDEV_DEBUG_PROTECT_OPEN
.set CYDEV_DEBUG_PROTECT_PROTECTED, 2
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_DFT_SELECT_CLK0, 1
.set CYDEV_DFT_SELECT_CLK1, 2
.set CYDEV_HEAP_SIZE, 0x80
.set CYDEV_IMO_TRIMMED_BY_USB, 0
.set CYDEV_IMO_TRIMMED_BY_WCO, 0
.set CYDEV_IS_EXPORTING_CODE, 0
.set CYDEV_IS_IMPORTING_CODE, 0
.set CYDEV_PROJ_TYPE, 0
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LAUNCHER, 5
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER, 4
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_STACK_SIZE, 0x0400
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 1
.set CYDEV_VDDA_MV, 3300
.set CYDEV_VDDD_MV, 3300
.set CYDEV_WDT_GENERATE_ISR, 1
.set CYIPBLOCK_M0S8_CTBM_VERSION, 0
.set CYIPBLOCK_m0s8cpuss_VERSION, 0
.set CYIPBLOCK_m0s8csd_VERSION, 0
.set CYIPBLOCK_m0s8gpio2_VERSION, 0
.set CYIPBLOCK_m0s8hsiom4a_VERSION, 0
.set CYIPBLOCK_m0s8lcd_VERSION, 0
.set CYIPBLOCK_m0s8lpcomp_VERSION, 0
.set CYIPBLOCK_m0s8pclk_VERSION, 0
.set CYIPBLOCK_m0s8sar_VERSION, 0
.set CYIPBLOCK_m0s8scb_VERSION, 0
.set CYIPBLOCK_m0s8srssv2_VERSION, 1
.set CYIPBLOCK_m0s8tcpwm_VERSION, 0
.set CYIPBLOCK_m0s8udbif_VERSION, 0
.set CYIPBLOCK_S8_GPIO_VERSION, 2
.set CYDEV_BOOTLOADER_ENABLE, 0
.endif
