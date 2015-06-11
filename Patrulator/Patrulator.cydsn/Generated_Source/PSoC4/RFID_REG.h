/*******************************************************************************
* File Name: RFID_REG.h
* Version 2.30
*
* Description:
*  This header file contains definitions associated with the Shift Register
*  component.
*
* Note: none
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/


#if !defined(CY_SHIFTREG_RFID_REG_H)
#define CY_SHIFTREG_RFID_REG_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component ShiftReg_v2_30 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define RFID_REG_FIFO_SIZE          (4u)
#define RFID_REG_USE_INPUT_FIFO     (0u)
#define RFID_REG_USE_OUTPUT_FIFO    (1u)
#define RFID_REG_SR_SIZE            (10u)


/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;

    uint16 saveSrA0Reg;
    uint16 saveSrA1Reg;

    #if(CY_UDB_V0)
        uint16 saveSrIntMask;
    #endif /* (CY_UDB_V0) */

} RFID_REG_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  RFID_REG_Start(void)                              ;
void  RFID_REG_Stop(void)                               ;
void  RFID_REG_Init(void)                               ;
void  RFID_REG_Enable(void)                             ;
void  RFID_REG_RestoreConfig(void)                      ;
void  RFID_REG_SaveConfig(void)                         ;
void  RFID_REG_Sleep(void)                              ;
void  RFID_REG_Wakeup(void)                             ;
void  RFID_REG_EnableInt(void)                          ;
void  RFID_REG_DisableInt(void)                         ;
void  RFID_REG_SetIntMode(uint8 interruptSource)        ;
uint8 RFID_REG_GetIntStatus(void)                       ;
void  RFID_REG_WriteRegValue(uint16 shiftData) \
                                                                ;
uint16 RFID_REG_ReadRegValue(void) ;
uint8    RFID_REG_GetFIFOStatus(uint8 fifoId)           ;

#if(0u != RFID_REG_USE_INPUT_FIFO)
    cystatus RFID_REG_WriteData(uint16 shiftData) \
                                                                ;
#endif /* (0u != RFID_REG_USE_INPUT_FIFO) */

#if(0u != RFID_REG_USE_OUTPUT_FIFO)
    uint16 RFID_REG_ReadData(void) ;
#endif /* (0u != RFID_REG_USE_OUTPUT_FIFO) */


/**********************************
*   Variable with external linkage
**********************************/

extern uint8 RFID_REG_initVar;


/***************************************
*           API Constants
***************************************/

#define RFID_REG_LOAD                   (0x01u)
#define RFID_REG_STORE                  (0x02u)
#define RFID_REG_RESET                  (0x04u)

#define RFID_REG_IN_FIFO                (0x01u)
#define RFID_REG_OUT_FIFO               (0x02u)

#define RFID_REG_RET_FIFO_FULL          (0x00u)

/* This define is obsolete */
#define RFID_REG_RET_FIFO_NOT_EMPTY     (0x01u)

#define RFID_REG_RET_FIFO_PARTIAL       (0x01u)
#define RFID_REG_RET_FIFO_EMPTY         (0x02u)
#define RFID_REG_RET_FIFO_NOT_DEFINED   (0xFEu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define RFID_REG__LEFT 0
#define RFID_REG__RIGHT 1



/***************************************
*    Initial Parameter Constants
***************************************/

#define RFID_REG_SR_MASK    (0x3FFu) /* Unsigned is added to parameter */
#define RFID_REG_INT_SRC    (2u)
#define RFID_REG_DIRECTION  (0u)


/***************************************
*             Registers
***************************************/

/* Control register */
#define RFID_REG_SR_CONTROL_REG (* (reg8 *) \
                                           RFID_REG_bSR_SyncCtl_CtrlReg__CONTROL_REG)
#define RFID_REG_SR_CONTROL_PTR (  (reg8 *) \
                                           RFID_REG_bSR_SyncCtl_CtrlReg__CONTROL_REG)

/* Status register */
#define RFID_REG_SR_STATUS_REG      (* (reg8 *) RFID_REG_bSR_StsReg__STATUS_REG)
#define RFID_REG_SR_STATUS_PTR      (  (reg8 *) RFID_REG_bSR_StsReg__STATUS_REG)

/* Interrupt status register */
#define RFID_REG_SR_STATUS_MASK_REG (* (reg8 *) RFID_REG_bSR_StsReg__MASK_REG)
#define RFID_REG_SR_STATUS_MASK_PTR (  (reg8 *) RFID_REG_bSR_StsReg__MASK_REG)

/* Aux control register */
#define RFID_REG_SR_AUX_CONTROL_REG (* (reg8 *) RFID_REG_bSR_StsReg__STATUS_AUX_CTL_REG)
#define RFID_REG_SR_AUX_CONTROL_PTR (  (reg8 *) RFID_REG_bSR_StsReg__STATUS_AUX_CTL_REG)

/* A1 register: only used to implement capture function */
#define RFID_REG_SHIFT_REG_CAPTURE_PTR    ( (reg8 *) \
                                        RFID_REG_bSR_sC16_BShiftRegDp_u0__A1_REG )

#if(CY_PSOC3 || CY_PSOC5)
    #define RFID_REG_IN_FIFO_VAL_LSB_PTR        ( (reg16 *) \
                                        RFID_REG_bSR_sC16_BShiftRegDp_u0__F0_REG )

    #define RFID_REG_SHIFT_REG_LSB_PTR          ( (reg16 *) \
                                        RFID_REG_bSR_sC16_BShiftRegDp_u0__A0_REG )

    #define RFID_REG_SHIFT_REG_VALUE_LSB_PTR    ( (reg16 *) \
                                        RFID_REG_bSR_sC16_BShiftRegDp_u0__A1_REG )

    #define RFID_REG_OUT_FIFO_VAL_LSB_PTR       ( (reg16 *) \
                                        RFID_REG_bSR_sC16_BShiftRegDp_u0__F1_REG )

#else
    #if(RFID_REG_SR_SIZE <= 8u) /* 8bit - ShiftReg */
        #define RFID_REG_IN_FIFO_VAL_LSB_PTR        ( (reg8 *) \
                                        RFID_REG_bSR_sC16_BShiftRegDp_u0__F0_REG )

        #define RFID_REG_SHIFT_REG_LSB_PTR          ( (reg8 *) \
                                        RFID_REG_bSR_sC16_BShiftRegDp_u0__A0_REG )

        #define RFID_REG_SHIFT_REG_VALUE_LSB_PTR    ( (reg8 *) \
                                        RFID_REG_bSR_sC16_BShiftRegDp_u0__A1_REG )

        #define RFID_REG_OUT_FIFO_VAL_LSB_PTR       ( (reg8 *) \
                                        RFID_REG_bSR_sC16_BShiftRegDp_u0__F1_REG )

    #elif(RFID_REG_SR_SIZE <= 16u) /* 16bit - ShiftReg */
        #define RFID_REG_IN_FIFO_VAL_LSB_PTR        ( (reg16 *) \
                                  RFID_REG_bSR_sC16_BShiftRegDp_u0__16BIT_F0_REG )

        #define RFID_REG_SHIFT_REG_LSB_PTR          ( (reg16 *) \
                                  RFID_REG_bSR_sC16_BShiftRegDp_u0__16BIT_A0_REG )

        #define RFID_REG_SHIFT_REG_VALUE_LSB_PTR    ( (reg16 *) \
                                  RFID_REG_bSR_sC16_BShiftRegDp_u0__16BIT_A1_REG )

        #define RFID_REG_OUT_FIFO_VAL_LSB_PTR       ( (reg16 *) \
                                  RFID_REG_bSR_sC16_BShiftRegDp_u0__16BIT_F1_REG )


    #elif(RFID_REG_SR_SIZE <= 24u) /* 24bit - ShiftReg */
        #define RFID_REG_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                        RFID_REG_bSR_sC16_BShiftRegDp_u0__F0_REG )

        #define RFID_REG_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                        RFID_REG_bSR_sC16_BShiftRegDp_u0__A0_REG )

        #define RFID_REG_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                        RFID_REG_bSR_sC16_BShiftRegDp_u0__A1_REG )

        #define RFID_REG_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                        RFID_REG_bSR_sC16_BShiftRegDp_u0__F1_REG )

    #else /* 32bit - ShiftReg */
        #define RFID_REG_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                  RFID_REG_bSR_sC16_BShiftRegDp_u0__32BIT_F0_REG )

        #define RFID_REG_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                  RFID_REG_bSR_sC16_BShiftRegDp_u0__32BIT_A0_REG )

        #define RFID_REG_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                  RFID_REG_bSR_sC16_BShiftRegDp_u0__32BIT_A1_REG )

        #define RFID_REG_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                  RFID_REG_bSR_sC16_BShiftRegDp_u0__32BIT_F1_REG )

    #endif  /* (RFID_REG_SR_SIZE <= 8u) */
#endif      /* (CY_PSOC3 || CY_PSOC5) */


/***************************************
*       Register Constants
***************************************/

#define RFID_REG_INTERRUPTS_ENABLE      (0x10u)
#define RFID_REG_LOAD_INT_EN            (0x01u)
#define RFID_REG_STORE_INT_EN           (0x02u)
#define RFID_REG_RESET_INT_EN           (0x04u)
#define RFID_REG_CLK_EN                 (0x01u)

#define RFID_REG_RESET_INT_EN_MASK      (0xFBu)
#define RFID_REG_LOAD_INT_EN_MASK       (0xFEu)
#define RFID_REG_STORE_INT_EN_MASK      (0xFDu)
#define RFID_REG_INTS_EN_MASK           (0x07u)

#define RFID_REG_OUT_FIFO_CLR_BIT       (0x02u)

#if(0u != RFID_REG_USE_INPUT_FIFO)

    #define RFID_REG_IN_FIFO_MASK       (0x18u)

    #define RFID_REG_IN_FIFO_FULL       (0x00u)
    #define RFID_REG_IN_FIFO_EMPTY      (0x01u)
    #define RFID_REG_IN_FIFO_PARTIAL    (0x02u)
    
    /* This define is obsolete */
    #define RFID_REG_IN_FIFO_NOT_EMPTY  (0x02u)
    
#endif /* (0u != RFID_REG_USE_INPUT_FIFO) */

#define RFID_REG_OUT_FIFO_MASK          (0x60u)

#define RFID_REG_OUT_FIFO_EMPTY         (0x00u)
#define RFID_REG_OUT_FIFO_FULL          (0x01u)
#define RFID_REG_OUT_FIFO_PARTIAL       (0x02u)

/* This define is obsolete */
#define RFID_REG_OUT_FIFO_NOT_EMPTY     (0x02u)

#define RFID_REG_IN_FIFO_SHIFT_MASK     (0x03u)
#define RFID_REG_OUT_FIFO_SHIFT_MASK    (0x05u)

#define RFID_REG_DISABLED               (0u)
#define RFID_REG_DEFAULT_A0             (0u)
#define RFID_REG_DEFAULT_A1             (0u)


/***************************************
*       Macros
***************************************/

#define RFID_REG_IS_ENABLED         (0u != (RFID_REG_SR_CONTROL & RFID_REG_CLK_EN))

#define RFID_REG_GET_OUT_FIFO_STS   ((RFID_REG_SR_STATUS & RFID_REG_OUT_FIFO_MASK) >> \
                                              RFID_REG_OUT_FIFO_SHIFT_MASK)

#define RFID_REG_GET_IN_FIFO_STS    ((RFID_REG_SR_STATUS & RFID_REG_IN_FIFO_MASK)  >> \
                                              RFID_REG_IN_FIFO_SHIFT_MASK)


/***************************************
*       Obsolete
***************************************/

/* Following code are OBSOLETE and must not be used 
 * starting from ShiftReg 2.20 
 */

#define RFID_REG_SR_CONTROL     (RFID_REG_SR_CONTROL_REG)
#define RFID_REG_SR_STATUS      (RFID_REG_SR_STATUS_REG)
#define RFID_REG_SR_STATUS_MASK (RFID_REG_SR_STATUS_MASK_REG)
#define RFID_REG_SR_AUX_CONTROL (RFID_REG_SR_AUX_CONTROL_REG)

#define RFID_REG_IN_FIFO_SHFT_MASK  (RFID_REG_IN_FIFO_SHIFT_MASK)
#define RFID_REG_OUT_FIFO_SHFT_MASK (RFID_REG_OUT_FIFO_SHFIT_MASK)

#define RFID_REG_RET_FIFO_BAD_PARAM (0xFFu)

#endif /* (CY_SHIFTREG_RFID_REG_H) */


/* [] END OF FILE */
