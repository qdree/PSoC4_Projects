    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv_trm.inc

; isr_1
isr_1__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
isr_1__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
isr_1__INTC_MASK EQU 0x02
isr_1__INTC_NUMBER EQU 1
isr_1__INTC_PRIOR_MASK EQU 0xC000
isr_1__INTC_PRIOR_NUM EQU 3
isr_1__INTC_PRIOR_REG EQU CYREG_CM0_IPR0
isr_1__INTC_SET_EN_REG EQU CYREG_CM0_ISER
isr_1__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

; Pin_SW
Pin_SW__0__DM__MASK EQU 0xE00000
Pin_SW__0__DM__SHIFT EQU 21
Pin_SW__0__DR EQU CYREG_PRT0_DR
Pin_SW__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
Pin_SW__0__HSIOM_MASK EQU 0xF0000000
Pin_SW__0__HSIOM_SHIFT EQU 28
Pin_SW__0__INTCFG EQU CYREG_PRT0_INTCFG
Pin_SW__0__INTSTAT EQU CYREG_PRT0_INTSTAT
Pin_SW__0__MASK EQU 0x80
Pin_SW__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Pin_SW__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Pin_SW__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Pin_SW__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Pin_SW__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Pin_SW__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Pin_SW__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Pin_SW__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Pin_SW__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Pin_SW__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Pin_SW__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Pin_SW__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Pin_SW__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Pin_SW__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Pin_SW__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Pin_SW__0__PC EQU CYREG_PRT0_PC
Pin_SW__0__PC2 EQU CYREG_PRT0_PC2
Pin_SW__0__PORT EQU 0
Pin_SW__0__PS EQU CYREG_PRT0_PS
Pin_SW__0__SHIFT EQU 7
Pin_SW__DR EQU CYREG_PRT0_DR
Pin_SW__INTCFG EQU CYREG_PRT0_INTCFG
Pin_SW__INTSTAT EQU CYREG_PRT0_INTSTAT
Pin_SW__MASK EQU 0x80
Pin_SW__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Pin_SW__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Pin_SW__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Pin_SW__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Pin_SW__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Pin_SW__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Pin_SW__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Pin_SW__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Pin_SW__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Pin_SW__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Pin_SW__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Pin_SW__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Pin_SW__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Pin_SW__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Pin_SW__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Pin_SW__PC EQU CYREG_PRT0_PC
Pin_SW__PC2 EQU CYREG_PRT0_PC2
Pin_SW__PORT EQU 0
Pin_SW__PS EQU CYREG_PRT0_PS
Pin_SW__SHIFT EQU 7
Pin_SW__SNAP EQU CYREG_PRT0_INTSTAT

; SW_Int
SW_Int__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
SW_Int__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
SW_Int__INTC_MASK EQU 0x01
SW_Int__INTC_NUMBER EQU 0
SW_Int__INTC_PRIOR_MASK EQU 0xC0
SW_Int__INTC_PRIOR_NUM EQU 3
SW_Int__INTC_PRIOR_REG EQU CYREG_CM0_IPR0
SW_Int__INTC_SET_EN_REG EQU CYREG_CM0_ISER
SW_Int__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

; Red_LED
Red_LED__0__DM__MASK EQU 0x1C0000
Red_LED__0__DM__SHIFT EQU 18
Red_LED__0__DR EQU CYREG_PRT1_DR
Red_LED__0__HSIOM EQU CYREG_HSIOM_PORT_SEL1
Red_LED__0__HSIOM_MASK EQU 0x0F000000
Red_LED__0__HSIOM_SHIFT EQU 24
Red_LED__0__INTCFG EQU CYREG_PRT1_INTCFG
Red_LED__0__INTSTAT EQU CYREG_PRT1_INTSTAT
Red_LED__0__MASK EQU 0x40
Red_LED__0__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
Red_LED__0__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
Red_LED__0__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
Red_LED__0__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
Red_LED__0__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
Red_LED__0__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
Red_LED__0__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
Red_LED__0__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
Red_LED__0__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
Red_LED__0__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
Red_LED__0__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
Red_LED__0__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
Red_LED__0__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
Red_LED__0__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
Red_LED__0__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
Red_LED__0__PC EQU CYREG_PRT1_PC
Red_LED__0__PC2 EQU CYREG_PRT1_PC2
Red_LED__0__PORT EQU 1
Red_LED__0__PS EQU CYREG_PRT1_PS
Red_LED__0__SHIFT EQU 6
Red_LED__DR EQU CYREG_PRT1_DR
Red_LED__INTCFG EQU CYREG_PRT1_INTCFG
Red_LED__INTSTAT EQU CYREG_PRT1_INTSTAT
Red_LED__MASK EQU 0x40
Red_LED__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
Red_LED__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
Red_LED__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
Red_LED__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
Red_LED__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
Red_LED__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
Red_LED__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
Red_LED__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
Red_LED__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
Red_LED__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
Red_LED__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
Red_LED__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
Red_LED__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
Red_LED__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
Red_LED__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
Red_LED__PC EQU CYREG_PRT1_PC
Red_LED__PC2 EQU CYREG_PRT1_PC2
Red_LED__PORT EQU 1
Red_LED__PS EQU CYREG_PRT1_PS
Red_LED__SHIFT EQU 6

; Green_LED
Green_LED__0__DM__MASK EQU 0x1C0
Green_LED__0__DM__SHIFT EQU 6
Green_LED__0__DR EQU CYREG_PRT0_DR
Green_LED__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
Green_LED__0__HSIOM_MASK EQU 0x00000F00
Green_LED__0__HSIOM_SHIFT EQU 8
Green_LED__0__INTCFG EQU CYREG_PRT0_INTCFG
Green_LED__0__INTSTAT EQU CYREG_PRT0_INTSTAT
Green_LED__0__MASK EQU 0x04
Green_LED__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Green_LED__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Green_LED__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Green_LED__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Green_LED__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Green_LED__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Green_LED__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Green_LED__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Green_LED__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Green_LED__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Green_LED__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Green_LED__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Green_LED__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Green_LED__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Green_LED__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Green_LED__0__PC EQU CYREG_PRT0_PC
Green_LED__0__PC2 EQU CYREG_PRT0_PC2
Green_LED__0__PORT EQU 0
Green_LED__0__PS EQU CYREG_PRT0_PS
Green_LED__0__SHIFT EQU 2
Green_LED__DR EQU CYREG_PRT0_DR
Green_LED__INTCFG EQU CYREG_PRT0_INTCFG
Green_LED__INTSTAT EQU CYREG_PRT0_INTSTAT
Green_LED__MASK EQU 0x04
Green_LED__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Green_LED__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Green_LED__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Green_LED__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Green_LED__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Green_LED__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Green_LED__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Green_LED__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Green_LED__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Green_LED__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Green_LED__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Green_LED__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Green_LED__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Green_LED__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Green_LED__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Green_LED__PC EQU CYREG_PRT0_PC
Green_LED__PC2 EQU CYREG_PRT0_PC2
Green_LED__PORT EQU 0
Green_LED__PS EQU CYREG_PRT0_PS
Green_LED__SHIFT EQU 2

; Timer_Green_TimerUDB
Timer_Green_TimerUDB_rstSts_stsreg__0__MASK EQU 0x01
Timer_Green_TimerUDB_rstSts_stsreg__0__POS EQU 0
Timer_Green_TimerUDB_rstSts_stsreg__2__MASK EQU 0x04
Timer_Green_TimerUDB_rstSts_stsreg__2__POS EQU 2
Timer_Green_TimerUDB_rstSts_stsreg__3__MASK EQU 0x08
Timer_Green_TimerUDB_rstSts_stsreg__3__POS EQU 3
Timer_Green_TimerUDB_rstSts_stsreg__MASK EQU 0x0D
Timer_Green_TimerUDB_rstSts_stsreg__MASK_REG EQU CYREG_UDB_W8_MSK_03
Timer_Green_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL_03
Timer_Green_TimerUDB_rstSts_stsreg__STATUS_REG EQU CYREG_UDB_W8_ST_03
Timer_Green_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL_01
Timer_Green_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_CONTROL_REG EQU CYREG_UDB_W16_CTL_01
Timer_Green_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_COUNT_REG EQU CYREG_UDB_W16_CTL_01
Timer_Green_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_CONTROL_REG EQU CYREG_UDB_W16_CTL_01
Timer_Green_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_COUNT_REG EQU CYREG_UDB_W16_CTL_01
Timer_Green_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_MASK_REG EQU CYREG_UDB_W16_MSK_01
Timer_Green_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_PERIOD_REG EQU CYREG_UDB_W16_MSK_01
Timer_Green_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_MASK_REG EQU CYREG_UDB_W16_MSK_01
Timer_Green_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_PERIOD_REG EQU CYREG_UDB_W16_MSK_01
Timer_Green_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__MASK EQU 0x80
Timer_Green_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__POS EQU 7
Timer_Green_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL_01
Timer_Green_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG EQU CYREG_UDB_W8_CTL_01
Timer_Green_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_ST_REG EQU CYREG_UDB_CAT16_CTL_ST_01
Timer_Green_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_REG EQU CYREG_UDB_W8_CTL_01
Timer_Green_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_ST_REG EQU CYREG_UDB_CAT16_CTL_ST_01
Timer_Green_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK EQU 0x80
Timer_Green_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK_CTL_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK_01
Timer_Green_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PER_CTL_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK_01
Timer_Green_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PERIOD_REG EQU CYREG_UDB_W8_MSK_01
Timer_Green_TimerUDB_sT32_timerdp_u0__16BIT_A0_REG EQU CYREG_UDB_W16_A0_00
Timer_Green_TimerUDB_sT32_timerdp_u0__16BIT_A1_REG EQU CYREG_UDB_W16_A1_00
Timer_Green_TimerUDB_sT32_timerdp_u0__16BIT_D0_REG EQU CYREG_UDB_W16_D0_00
Timer_Green_TimerUDB_sT32_timerdp_u0__16BIT_D1_REG EQU CYREG_UDB_W16_D1_00
Timer_Green_TimerUDB_sT32_timerdp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL_00
Timer_Green_TimerUDB_sT32_timerdp_u0__16BIT_F0_REG EQU CYREG_UDB_W16_F0_00
Timer_Green_TimerUDB_sT32_timerdp_u0__16BIT_F1_REG EQU CYREG_UDB_W16_F1_00
Timer_Green_TimerUDB_sT32_timerdp_u0__32BIT_A0_REG EQU CYREG_UDB_W32_A0_00
Timer_Green_TimerUDB_sT32_timerdp_u0__32BIT_A1_REG EQU CYREG_UDB_W32_A1_00
Timer_Green_TimerUDB_sT32_timerdp_u0__32BIT_D0_REG EQU CYREG_UDB_W32_D0_00
Timer_Green_TimerUDB_sT32_timerdp_u0__32BIT_D1_REG EQU CYREG_UDB_W32_D1_00
Timer_Green_TimerUDB_sT32_timerdp_u0__32BIT_DP_AUX_CTL_REG EQU CYREG_UDB_W32_ACTL_00
Timer_Green_TimerUDB_sT32_timerdp_u0__32BIT_F0_REG EQU CYREG_UDB_W32_F0_00
Timer_Green_TimerUDB_sT32_timerdp_u0__32BIT_F1_REG EQU CYREG_UDB_W32_F1_00
Timer_Green_TimerUDB_sT32_timerdp_u0__A0_A1_REG EQU CYREG_UDB_CAT16_A_00
Timer_Green_TimerUDB_sT32_timerdp_u0__A0_REG EQU CYREG_UDB_W8_A0_00
Timer_Green_TimerUDB_sT32_timerdp_u0__A1_REG EQU CYREG_UDB_W8_A1_00
Timer_Green_TimerUDB_sT32_timerdp_u0__D0_D1_REG EQU CYREG_UDB_CAT16_D_00
Timer_Green_TimerUDB_sT32_timerdp_u0__D0_REG EQU CYREG_UDB_W8_D0_00
Timer_Green_TimerUDB_sT32_timerdp_u0__D1_REG EQU CYREG_UDB_W8_D1_00
Timer_Green_TimerUDB_sT32_timerdp_u0__DP_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL_00
Timer_Green_TimerUDB_sT32_timerdp_u0__F0_F1_REG EQU CYREG_UDB_CAT16_F_00
Timer_Green_TimerUDB_sT32_timerdp_u0__F0_REG EQU CYREG_UDB_W8_F0_00
Timer_Green_TimerUDB_sT32_timerdp_u0__F1_REG EQU CYREG_UDB_W8_F1_00
Timer_Green_TimerUDB_sT32_timerdp_u1__16BIT_A0_REG EQU CYREG_UDB_W16_A0_01
Timer_Green_TimerUDB_sT32_timerdp_u1__16BIT_A1_REG EQU CYREG_UDB_W16_A1_01
Timer_Green_TimerUDB_sT32_timerdp_u1__16BIT_D0_REG EQU CYREG_UDB_W16_D0_01
Timer_Green_TimerUDB_sT32_timerdp_u1__16BIT_D1_REG EQU CYREG_UDB_W16_D1_01
Timer_Green_TimerUDB_sT32_timerdp_u1__16BIT_DP_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL_01
Timer_Green_TimerUDB_sT32_timerdp_u1__16BIT_F0_REG EQU CYREG_UDB_W16_F0_01
Timer_Green_TimerUDB_sT32_timerdp_u1__16BIT_F1_REG EQU CYREG_UDB_W16_F1_01
Timer_Green_TimerUDB_sT32_timerdp_u1__A0_A1_REG EQU CYREG_UDB_CAT16_A_01
Timer_Green_TimerUDB_sT32_timerdp_u1__A0_REG EQU CYREG_UDB_W8_A0_01
Timer_Green_TimerUDB_sT32_timerdp_u1__A1_REG EQU CYREG_UDB_W8_A1_01
Timer_Green_TimerUDB_sT32_timerdp_u1__D0_D1_REG EQU CYREG_UDB_CAT16_D_01
Timer_Green_TimerUDB_sT32_timerdp_u1__D0_REG EQU CYREG_UDB_W8_D0_01
Timer_Green_TimerUDB_sT32_timerdp_u1__D1_REG EQU CYREG_UDB_W8_D1_01
Timer_Green_TimerUDB_sT32_timerdp_u1__DP_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL_01
Timer_Green_TimerUDB_sT32_timerdp_u1__F0_F1_REG EQU CYREG_UDB_CAT16_F_01
Timer_Green_TimerUDB_sT32_timerdp_u1__F0_REG EQU CYREG_UDB_W8_F0_01
Timer_Green_TimerUDB_sT32_timerdp_u1__F1_REG EQU CYREG_UDB_W8_F1_01
Timer_Green_TimerUDB_sT32_timerdp_u1__MSK_DP_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK_01
Timer_Green_TimerUDB_sT32_timerdp_u1__PER_DP_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK_01
Timer_Green_TimerUDB_sT32_timerdp_u2__16BIT_A0_REG EQU CYREG_UDB_W16_A0_02
Timer_Green_TimerUDB_sT32_timerdp_u2__16BIT_A1_REG EQU CYREG_UDB_W16_A1_02
Timer_Green_TimerUDB_sT32_timerdp_u2__16BIT_D0_REG EQU CYREG_UDB_W16_D0_02
Timer_Green_TimerUDB_sT32_timerdp_u2__16BIT_D1_REG EQU CYREG_UDB_W16_D1_02
Timer_Green_TimerUDB_sT32_timerdp_u2__16BIT_DP_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL_02
Timer_Green_TimerUDB_sT32_timerdp_u2__16BIT_F0_REG EQU CYREG_UDB_W16_F0_02
Timer_Green_TimerUDB_sT32_timerdp_u2__16BIT_F1_REG EQU CYREG_UDB_W16_F1_02
Timer_Green_TimerUDB_sT32_timerdp_u2__A0_A1_REG EQU CYREG_UDB_CAT16_A_02
Timer_Green_TimerUDB_sT32_timerdp_u2__A0_REG EQU CYREG_UDB_W8_A0_02
Timer_Green_TimerUDB_sT32_timerdp_u2__A1_REG EQU CYREG_UDB_W8_A1_02
Timer_Green_TimerUDB_sT32_timerdp_u2__D0_D1_REG EQU CYREG_UDB_CAT16_D_02
Timer_Green_TimerUDB_sT32_timerdp_u2__D0_REG EQU CYREG_UDB_W8_D0_02
Timer_Green_TimerUDB_sT32_timerdp_u2__D1_REG EQU CYREG_UDB_W8_D1_02
Timer_Green_TimerUDB_sT32_timerdp_u2__DP_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL_02
Timer_Green_TimerUDB_sT32_timerdp_u2__F0_F1_REG EQU CYREG_UDB_CAT16_F_02
Timer_Green_TimerUDB_sT32_timerdp_u2__F0_REG EQU CYREG_UDB_W8_F0_02
Timer_Green_TimerUDB_sT32_timerdp_u2__F1_REG EQU CYREG_UDB_W8_F1_02
Timer_Green_TimerUDB_sT32_timerdp_u3__A0_A1_REG EQU CYREG_UDB_CAT16_A_03
Timer_Green_TimerUDB_sT32_timerdp_u3__A0_REG EQU CYREG_UDB_W8_A0_03
Timer_Green_TimerUDB_sT32_timerdp_u3__A1_REG EQU CYREG_UDB_W8_A1_03
Timer_Green_TimerUDB_sT32_timerdp_u3__D0_D1_REG EQU CYREG_UDB_CAT16_D_03
Timer_Green_TimerUDB_sT32_timerdp_u3__D0_REG EQU CYREG_UDB_W8_D0_03
Timer_Green_TimerUDB_sT32_timerdp_u3__D1_REG EQU CYREG_UDB_W8_D1_03
Timer_Green_TimerUDB_sT32_timerdp_u3__DP_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL_03
Timer_Green_TimerUDB_sT32_timerdp_u3__F0_F1_REG EQU CYREG_UDB_CAT16_F_03
Timer_Green_TimerUDB_sT32_timerdp_u3__F0_REG EQU CYREG_UDB_W8_F0_03
Timer_Green_TimerUDB_sT32_timerdp_u3__F1_REG EQU CYREG_UDB_W8_F1_03

; Miscellaneous
CYDEV_BCLK__HFCLK__HZ EQU 24000000
CYDEV_BCLK__HFCLK__KHZ EQU 24000
CYDEV_BCLK__HFCLK__MHZ EQU 24
CYDEV_BCLK__SYSCLK__HZ EQU 24000000
CYDEV_BCLK__SYSCLK__KHZ EQU 24000
CYDEV_BCLK__SYSCLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PANTHER EQU 18
CYDEV_CHIP_DIE_PSOC4A EQU 10
CYDEV_CHIP_DIE_PSOC5LP EQU 17
CYDEV_CHIP_DIE_TMA4 EQU 2
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC4
CYDEV_CHIP_JTAG_ID EQU 0x04C81193
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 10
CYDEV_CHIP_MEMBER_4C EQU 15
CYDEV_CHIP_MEMBER_4D EQU 6
CYDEV_CHIP_MEMBER_4E EQU 4
CYDEV_CHIP_MEMBER_4F EQU 11
CYDEV_CHIP_MEMBER_4G EQU 2
CYDEV_CHIP_MEMBER_4H EQU 9
CYDEV_CHIP_MEMBER_4I EQU 14
CYDEV_CHIP_MEMBER_4J EQU 7
CYDEV_CHIP_MEMBER_4K EQU 8
CYDEV_CHIP_MEMBER_4L EQU 13
CYDEV_CHIP_MEMBER_4M EQU 12
CYDEV_CHIP_MEMBER_4N EQU 5
CYDEV_CHIP_MEMBER_4U EQU 3
CYDEV_CHIP_MEMBER_5A EQU 17
CYDEV_CHIP_MEMBER_5B EQU 16
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_4A
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PANTHER_ES0 EQU 0
CYDEV_CHIP_REV_PANTHER_ES1 EQU 1
CYDEV_CHIP_REV_PANTHER_PRODUCTION EQU 1
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4C_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_4A_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_READ_ACCELERATOR EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_PROTECT_KILL EQU 4
CYDEV_DEBUG_PROTECT_OPEN EQU 1
CYDEV_DEBUG_PROTECT EQU CYDEV_DEBUG_PROTECT_OPEN
CYDEV_DEBUG_PROTECT_PROTECTED EQU 2
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DFT_SELECT_CLK0 EQU 1
CYDEV_DFT_SELECT_CLK1 EQU 2
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_IMO_TRIMMED_BY_USB EQU 0
CYDEV_IMO_TRIMMED_BY_WCO EQU 0
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_STACK_SIZE EQU 0x0400
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 1
CYDEV_VDDA_MV EQU 3300
CYDEV_VDDD_MV EQU 3300
CYDEV_WDT_GENERATE_ISR EQU 1
CYIPBLOCK_M0S8_CTBM_VERSION EQU 0
CYIPBLOCK_m0s8cpuss_VERSION EQU 0
CYIPBLOCK_m0s8csd_VERSION EQU 0
CYIPBLOCK_m0s8gpio2_VERSION EQU 0
CYIPBLOCK_m0s8hsiom4a_VERSION EQU 0
CYIPBLOCK_m0s8lcd_VERSION EQU 0
CYIPBLOCK_m0s8lpcomp_VERSION EQU 0
CYIPBLOCK_m0s8pclk_VERSION EQU 0
CYIPBLOCK_m0s8sar_VERSION EQU 0
CYIPBLOCK_m0s8scb_VERSION EQU 0
CYIPBLOCK_m0s8srssv2_VERSION EQU 1
CYIPBLOCK_m0s8tcpwm_VERSION EQU 0
CYIPBLOCK_m0s8udbif_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 2
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END