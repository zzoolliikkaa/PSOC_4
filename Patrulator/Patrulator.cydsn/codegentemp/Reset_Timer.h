/*******************************************************************************
* File Name: Reset_Timer.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the Reset_Timer
*  component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_TCPWM_Reset_Timer_H)
#define CY_TCPWM_Reset_Timer_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} Reset_Timer_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  Reset_Timer_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define Reset_Timer_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define Reset_Timer_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define Reset_Timer_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define Reset_Timer_QUAD_ENCODING_MODES            (0lu)

/* Signal modes */
#define Reset_Timer_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define Reset_Timer_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define Reset_Timer_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define Reset_Timer_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define Reset_Timer_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define Reset_Timer_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define Reset_Timer_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define Reset_Timer_TC_RUN_MODE                    (1lu)
#define Reset_Timer_TC_COUNTER_MODE                (1lu)
#define Reset_Timer_TC_COMP_CAP_MODE               (2lu)
#define Reset_Timer_TC_PRESCALER                   (0lu)

/* Signal modes */
#define Reset_Timer_TC_RELOAD_SIGNAL_MODE          (1lu)
#define Reset_Timer_TC_COUNT_SIGNAL_MODE           (3lu)
#define Reset_Timer_TC_START_SIGNAL_MODE           (1lu)
#define Reset_Timer_TC_STOP_SIGNAL_MODE            (0lu)
#define Reset_Timer_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define Reset_Timer_TC_RELOAD_SIGNAL_PRESENT       (1lu)
#define Reset_Timer_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define Reset_Timer_TC_START_SIGNAL_PRESENT        (1lu)
#define Reset_Timer_TC_STOP_SIGNAL_PRESENT         (1lu)
#define Reset_Timer_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define Reset_Timer_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define Reset_Timer_PWM_KILL_EVENT                 (0lu)
#define Reset_Timer_PWM_STOP_EVENT                 (0lu)
#define Reset_Timer_PWM_MODE                       (4lu)
#define Reset_Timer_PWM_OUT_N_INVERT               (0lu)
#define Reset_Timer_PWM_OUT_INVERT                 (0lu)
#define Reset_Timer_PWM_ALIGN                      (0lu)
#define Reset_Timer_PWM_RUN_MODE                   (0lu)
#define Reset_Timer_PWM_DEAD_TIME_CYCLE            (0lu)
#define Reset_Timer_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define Reset_Timer_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define Reset_Timer_PWM_COUNT_SIGNAL_MODE          (3lu)
#define Reset_Timer_PWM_START_SIGNAL_MODE          (0lu)
#define Reset_Timer_PWM_STOP_SIGNAL_MODE           (0lu)
#define Reset_Timer_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define Reset_Timer_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define Reset_Timer_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define Reset_Timer_PWM_START_SIGNAL_PRESENT       (0lu)
#define Reset_Timer_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define Reset_Timer_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define Reset_Timer_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define Reset_Timer_TC_PERIOD_VALUE                (24000lu)
#define Reset_Timer_TC_COMPARE_VALUE               (65535lu)
#define Reset_Timer_TC_COMPARE_BUF_VALUE           (65535lu)
#define Reset_Timer_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define Reset_Timer_PWM_PERIOD_VALUE               (65535lu)
#define Reset_Timer_PWM_PERIOD_BUF_VALUE           (65535lu)
#define Reset_Timer_PWM_PERIOD_SWAP                (0lu)
#define Reset_Timer_PWM_COMPARE_VALUE              (65535lu)
#define Reset_Timer_PWM_COMPARE_BUF_VALUE          (65535lu)
#define Reset_Timer_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define Reset_Timer__LEFT 0
#define Reset_Timer__RIGHT 1
#define Reset_Timer__CENTER 2
#define Reset_Timer__ASYMMETRIC 3

#define Reset_Timer__X1 0
#define Reset_Timer__X2 1
#define Reset_Timer__X4 2

#define Reset_Timer__PWM 4
#define Reset_Timer__PWM_DT 5
#define Reset_Timer__PWM_PR 6

#define Reset_Timer__INVERSE 1
#define Reset_Timer__DIRECT 0

#define Reset_Timer__CAPTURE 2
#define Reset_Timer__COMPARE 0

#define Reset_Timer__TRIG_LEVEL 3
#define Reset_Timer__TRIG_RISING 0
#define Reset_Timer__TRIG_FALLING 1
#define Reset_Timer__TRIG_BOTH 2

#define Reset_Timer__INTR_MASK_TC 1
#define Reset_Timer__INTR_MASK_CC_MATCH 2
#define Reset_Timer__INTR_MASK_NONE 0
#define Reset_Timer__INTR_MASK_TC_CC 3

#define Reset_Timer__UNCONFIG 8
#define Reset_Timer__TIMER 1
#define Reset_Timer__QUAD 3
#define Reset_Timer__PWM_SEL 7

#define Reset_Timer__COUNT_UP 0
#define Reset_Timer__COUNT_DOWN 1
#define Reset_Timer__COUNT_UPDOWN0 2
#define Reset_Timer__COUNT_UPDOWN1 3


/* Prescaler */
#define Reset_Timer_PRESCALE_DIVBY1                ((uint32)(0u << Reset_Timer_PRESCALER_SHIFT))
#define Reset_Timer_PRESCALE_DIVBY2                ((uint32)(1u << Reset_Timer_PRESCALER_SHIFT))
#define Reset_Timer_PRESCALE_DIVBY4                ((uint32)(2u << Reset_Timer_PRESCALER_SHIFT))
#define Reset_Timer_PRESCALE_DIVBY8                ((uint32)(3u << Reset_Timer_PRESCALER_SHIFT))
#define Reset_Timer_PRESCALE_DIVBY16               ((uint32)(4u << Reset_Timer_PRESCALER_SHIFT))
#define Reset_Timer_PRESCALE_DIVBY32               ((uint32)(5u << Reset_Timer_PRESCALER_SHIFT))
#define Reset_Timer_PRESCALE_DIVBY64               ((uint32)(6u << Reset_Timer_PRESCALER_SHIFT))
#define Reset_Timer_PRESCALE_DIVBY128              ((uint32)(7u << Reset_Timer_PRESCALER_SHIFT))

/* TCPWM set modes */
#define Reset_Timer_MODE_TIMER_COMPARE             ((uint32)(Reset_Timer__COMPARE         <<  \
                                                                  Reset_Timer_MODE_SHIFT))
#define Reset_Timer_MODE_TIMER_CAPTURE             ((uint32)(Reset_Timer__CAPTURE         <<  \
                                                                  Reset_Timer_MODE_SHIFT))
#define Reset_Timer_MODE_QUAD                      ((uint32)(Reset_Timer__QUAD            <<  \
                                                                  Reset_Timer_MODE_SHIFT))
#define Reset_Timer_MODE_PWM                       ((uint32)(Reset_Timer__PWM             <<  \
                                                                  Reset_Timer_MODE_SHIFT))
#define Reset_Timer_MODE_PWM_DT                    ((uint32)(Reset_Timer__PWM_DT          <<  \
                                                                  Reset_Timer_MODE_SHIFT))
#define Reset_Timer_MODE_PWM_PR                    ((uint32)(Reset_Timer__PWM_PR          <<  \
                                                                  Reset_Timer_MODE_SHIFT))

/* Quad Modes */
#define Reset_Timer_MODE_X1                        ((uint32)(Reset_Timer__X1              <<  \
                                                                  Reset_Timer_QUAD_MODE_SHIFT))
#define Reset_Timer_MODE_X2                        ((uint32)(Reset_Timer__X2              <<  \
                                                                  Reset_Timer_QUAD_MODE_SHIFT))
#define Reset_Timer_MODE_X4                        ((uint32)(Reset_Timer__X4              <<  \
                                                                  Reset_Timer_QUAD_MODE_SHIFT))

/* Counter modes */
#define Reset_Timer_COUNT_UP                       ((uint32)(Reset_Timer__COUNT_UP        <<  \
                                                                  Reset_Timer_UPDOWN_SHIFT))
#define Reset_Timer_COUNT_DOWN                     ((uint32)(Reset_Timer__COUNT_DOWN      <<  \
                                                                  Reset_Timer_UPDOWN_SHIFT))
#define Reset_Timer_COUNT_UPDOWN0                  ((uint32)(Reset_Timer__COUNT_UPDOWN0   <<  \
                                                                  Reset_Timer_UPDOWN_SHIFT))
#define Reset_Timer_COUNT_UPDOWN1                  ((uint32)(Reset_Timer__COUNT_UPDOWN1   <<  \
                                                                  Reset_Timer_UPDOWN_SHIFT))

/* PWM output invert */
#define Reset_Timer_INVERT_LINE                    ((uint32)(Reset_Timer__INVERSE         <<  \
                                                                  Reset_Timer_INV_OUT_SHIFT))
#define Reset_Timer_INVERT_LINE_N                  ((uint32)(Reset_Timer__INVERSE         <<  \
                                                                  Reset_Timer_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define Reset_Timer_TRIG_RISING                    ((uint32)Reset_Timer__TRIG_RISING)
#define Reset_Timer_TRIG_FALLING                   ((uint32)Reset_Timer__TRIG_FALLING)
#define Reset_Timer_TRIG_BOTH                      ((uint32)Reset_Timer__TRIG_BOTH)
#define Reset_Timer_TRIG_LEVEL                     ((uint32)Reset_Timer__TRIG_LEVEL)

/* Interrupt mask */
#define Reset_Timer_INTR_MASK_TC                   ((uint32)Reset_Timer__INTR_MASK_TC)
#define Reset_Timer_INTR_MASK_CC_MATCH             ((uint32)Reset_Timer__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define Reset_Timer_CC_MATCH_SET                   (0x00u)
#define Reset_Timer_CC_MATCH_CLEAR                 (0x01u)
#define Reset_Timer_CC_MATCH_INVERT                (0x02u)
#define Reset_Timer_CC_MATCH_NO_CHANGE             (0x03u)
#define Reset_Timer_OVERLOW_SET                    (0x00u)
#define Reset_Timer_OVERLOW_CLEAR                  (0x04u)
#define Reset_Timer_OVERLOW_INVERT                 (0x08u)
#define Reset_Timer_OVERLOW_NO_CHANGE              (0x0Cu)
#define Reset_Timer_UNDERFLOW_SET                  (0x00u)
#define Reset_Timer_UNDERFLOW_CLEAR                (0x10u)
#define Reset_Timer_UNDERFLOW_INVERT               (0x20u)
#define Reset_Timer_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define Reset_Timer_PWM_MODE_LEFT                  (Reset_Timer_CC_MATCH_CLEAR        |   \
                                                         Reset_Timer_OVERLOW_SET           |   \
                                                         Reset_Timer_UNDERFLOW_NO_CHANGE)
#define Reset_Timer_PWM_MODE_RIGHT                 (Reset_Timer_CC_MATCH_SET          |   \
                                                         Reset_Timer_OVERLOW_NO_CHANGE     |   \
                                                         Reset_Timer_UNDERFLOW_CLEAR)
#define Reset_Timer_PWM_MODE_ASYM                  (Reset_Timer_CC_MATCH_INVERT       |   \
                                                         Reset_Timer_OVERLOW_SET           |   \
                                                         Reset_Timer_UNDERFLOW_CLEAR)

#if (Reset_Timer_CY_TCPWM_V2)
    #if(Reset_Timer_CY_TCPWM_4000)
        #define Reset_Timer_PWM_MODE_CENTER                (Reset_Timer_CC_MATCH_INVERT       |   \
                                                                 Reset_Timer_OVERLOW_NO_CHANGE     |   \
                                                                 Reset_Timer_UNDERFLOW_CLEAR)
    #else
        #define Reset_Timer_PWM_MODE_CENTER                (Reset_Timer_CC_MATCH_INVERT       |   \
                                                                 Reset_Timer_OVERLOW_SET           |   \
                                                                 Reset_Timer_UNDERFLOW_CLEAR)
    #endif /* (Reset_Timer_CY_TCPWM_4000) */
#else
    #define Reset_Timer_PWM_MODE_CENTER                (Reset_Timer_CC_MATCH_INVERT       |   \
                                                             Reset_Timer_OVERLOW_NO_CHANGE     |   \
                                                             Reset_Timer_UNDERFLOW_CLEAR)
#endif /* (Reset_Timer_CY_TCPWM_NEW) */

/* Command operations without condition */
#define Reset_Timer_CMD_CAPTURE                    (0u)
#define Reset_Timer_CMD_RELOAD                     (8u)
#define Reset_Timer_CMD_STOP                       (16u)
#define Reset_Timer_CMD_START                      (24u)

/* Status */
#define Reset_Timer_STATUS_DOWN                    (1u)
#define Reset_Timer_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   Reset_Timer_Init(void);
void   Reset_Timer_Enable(void);
void   Reset_Timer_Start(void);
void   Reset_Timer_Stop(void);

void   Reset_Timer_SetMode(uint32 mode);
void   Reset_Timer_SetCounterMode(uint32 counterMode);
void   Reset_Timer_SetPWMMode(uint32 modeMask);
void   Reset_Timer_SetQDMode(uint32 qdMode);

void   Reset_Timer_SetPrescaler(uint32 prescaler);
void   Reset_Timer_TriggerCommand(uint32 mask, uint32 command);
void   Reset_Timer_SetOneShot(uint32 oneShotEnable);
uint32 Reset_Timer_ReadStatus(void);

void   Reset_Timer_SetPWMSyncKill(uint32 syncKillEnable);
void   Reset_Timer_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   Reset_Timer_SetPWMDeadTime(uint32 deadTime);
void   Reset_Timer_SetPWMInvert(uint32 mask);

void   Reset_Timer_SetInterruptMode(uint32 interruptMask);
uint32 Reset_Timer_GetInterruptSourceMasked(void);
uint32 Reset_Timer_GetInterruptSource(void);
void   Reset_Timer_ClearInterrupt(uint32 interruptMask);
void   Reset_Timer_SetInterrupt(uint32 interruptMask);

void   Reset_Timer_WriteCounter(uint32 count);
uint32 Reset_Timer_ReadCounter(void);

uint32 Reset_Timer_ReadCapture(void);
uint32 Reset_Timer_ReadCaptureBuf(void);

void   Reset_Timer_WritePeriod(uint32 period);
uint32 Reset_Timer_ReadPeriod(void);
void   Reset_Timer_WritePeriodBuf(uint32 periodBuf);
uint32 Reset_Timer_ReadPeriodBuf(void);

void   Reset_Timer_WriteCompare(uint32 compare);
uint32 Reset_Timer_ReadCompare(void);
void   Reset_Timer_WriteCompareBuf(uint32 compareBuf);
uint32 Reset_Timer_ReadCompareBuf(void);

void   Reset_Timer_SetPeriodSwap(uint32 swapEnable);
void   Reset_Timer_SetCompareSwap(uint32 swapEnable);

void   Reset_Timer_SetCaptureMode(uint32 triggerMode);
void   Reset_Timer_SetReloadMode(uint32 triggerMode);
void   Reset_Timer_SetStartMode(uint32 triggerMode);
void   Reset_Timer_SetStopMode(uint32 triggerMode);
void   Reset_Timer_SetCountMode(uint32 triggerMode);

void   Reset_Timer_SaveConfig(void);
void   Reset_Timer_RestoreConfig(void);
void   Reset_Timer_Sleep(void);
void   Reset_Timer_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define Reset_Timer_BLOCK_CONTROL_REG              (*(reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Reset_Timer_BLOCK_CONTROL_PTR              ( (reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Reset_Timer_COMMAND_REG                    (*(reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Reset_Timer_COMMAND_PTR                    ( (reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Reset_Timer_INTRRUPT_CAUSE_REG             (*(reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Reset_Timer_INTRRUPT_CAUSE_PTR             ( (reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Reset_Timer_CONTROL_REG                    (*(reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__CTRL )
#define Reset_Timer_CONTROL_PTR                    ( (reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__CTRL )
#define Reset_Timer_STATUS_REG                     (*(reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__STATUS )
#define Reset_Timer_STATUS_PTR                     ( (reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__STATUS )
#define Reset_Timer_COUNTER_REG                    (*(reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__COUNTER )
#define Reset_Timer_COUNTER_PTR                    ( (reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__COUNTER )
#define Reset_Timer_COMP_CAP_REG                   (*(reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__CC )
#define Reset_Timer_COMP_CAP_PTR                   ( (reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__CC )
#define Reset_Timer_COMP_CAP_BUF_REG               (*(reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__CC_BUFF )
#define Reset_Timer_COMP_CAP_BUF_PTR               ( (reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__CC_BUFF )
#define Reset_Timer_PERIOD_REG                     (*(reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__PERIOD )
#define Reset_Timer_PERIOD_PTR                     ( (reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__PERIOD )
#define Reset_Timer_PERIOD_BUF_REG                 (*(reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Reset_Timer_PERIOD_BUF_PTR                 ( (reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Reset_Timer_TRIG_CONTROL0_REG              (*(reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Reset_Timer_TRIG_CONTROL0_PTR              ( (reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Reset_Timer_TRIG_CONTROL1_REG              (*(reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Reset_Timer_TRIG_CONTROL1_PTR              ( (reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Reset_Timer_TRIG_CONTROL2_REG              (*(reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Reset_Timer_TRIG_CONTROL2_PTR              ( (reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Reset_Timer_INTERRUPT_REQ_REG              (*(reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__INTR )
#define Reset_Timer_INTERRUPT_REQ_PTR              ( (reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__INTR )
#define Reset_Timer_INTERRUPT_SET_REG              (*(reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__INTR_SET )
#define Reset_Timer_INTERRUPT_SET_PTR              ( (reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__INTR_SET )
#define Reset_Timer_INTERRUPT_MASK_REG             (*(reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__INTR_MASK )
#define Reset_Timer_INTERRUPT_MASK_PTR             ( (reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__INTR_MASK )
#define Reset_Timer_INTERRUPT_MASKED_REG           (*(reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__INTR_MASKED )
#define Reset_Timer_INTERRUPT_MASKED_PTR           ( (reg32 *) Reset_Timer_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define Reset_Timer_MASK                           ((uint32)Reset_Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define Reset_Timer_RELOAD_CC_SHIFT                (0u)
#define Reset_Timer_RELOAD_PERIOD_SHIFT            (1u)
#define Reset_Timer_PWM_SYNC_KILL_SHIFT            (2u)
#define Reset_Timer_PWM_STOP_KILL_SHIFT            (3u)
#define Reset_Timer_PRESCALER_SHIFT                (8u)
#define Reset_Timer_UPDOWN_SHIFT                   (16u)
#define Reset_Timer_ONESHOT_SHIFT                  (18u)
#define Reset_Timer_QUAD_MODE_SHIFT                (20u)
#define Reset_Timer_INV_OUT_SHIFT                  (20u)
#define Reset_Timer_INV_COMPL_OUT_SHIFT            (21u)
#define Reset_Timer_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define Reset_Timer_RELOAD_CC_MASK                 ((uint32)(Reset_Timer_1BIT_MASK        <<  \
                                                                            Reset_Timer_RELOAD_CC_SHIFT))
#define Reset_Timer_RELOAD_PERIOD_MASK             ((uint32)(Reset_Timer_1BIT_MASK        <<  \
                                                                            Reset_Timer_RELOAD_PERIOD_SHIFT))
#define Reset_Timer_PWM_SYNC_KILL_MASK             ((uint32)(Reset_Timer_1BIT_MASK        <<  \
                                                                            Reset_Timer_PWM_SYNC_KILL_SHIFT))
#define Reset_Timer_PWM_STOP_KILL_MASK             ((uint32)(Reset_Timer_1BIT_MASK        <<  \
                                                                            Reset_Timer_PWM_STOP_KILL_SHIFT))
#define Reset_Timer_PRESCALER_MASK                 ((uint32)(Reset_Timer_8BIT_MASK        <<  \
                                                                            Reset_Timer_PRESCALER_SHIFT))
#define Reset_Timer_UPDOWN_MASK                    ((uint32)(Reset_Timer_2BIT_MASK        <<  \
                                                                            Reset_Timer_UPDOWN_SHIFT))
#define Reset_Timer_ONESHOT_MASK                   ((uint32)(Reset_Timer_1BIT_MASK        <<  \
                                                                            Reset_Timer_ONESHOT_SHIFT))
#define Reset_Timer_QUAD_MODE_MASK                 ((uint32)(Reset_Timer_3BIT_MASK        <<  \
                                                                            Reset_Timer_QUAD_MODE_SHIFT))
#define Reset_Timer_INV_OUT_MASK                   ((uint32)(Reset_Timer_2BIT_MASK        <<  \
                                                                            Reset_Timer_INV_OUT_SHIFT))
#define Reset_Timer_MODE_MASK                      ((uint32)(Reset_Timer_3BIT_MASK        <<  \
                                                                            Reset_Timer_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define Reset_Timer_CAPTURE_SHIFT                  (0u)
#define Reset_Timer_COUNT_SHIFT                    (2u)
#define Reset_Timer_RELOAD_SHIFT                   (4u)
#define Reset_Timer_STOP_SHIFT                     (6u)
#define Reset_Timer_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define Reset_Timer_CAPTURE_MASK                   ((uint32)(Reset_Timer_2BIT_MASK        <<  \
                                                                  Reset_Timer_CAPTURE_SHIFT))
#define Reset_Timer_COUNT_MASK                     ((uint32)(Reset_Timer_2BIT_MASK        <<  \
                                                                  Reset_Timer_COUNT_SHIFT))
#define Reset_Timer_RELOAD_MASK                    ((uint32)(Reset_Timer_2BIT_MASK        <<  \
                                                                  Reset_Timer_RELOAD_SHIFT))
#define Reset_Timer_STOP_MASK                      ((uint32)(Reset_Timer_2BIT_MASK        <<  \
                                                                  Reset_Timer_STOP_SHIFT))
#define Reset_Timer_START_MASK                     ((uint32)(Reset_Timer_2BIT_MASK        <<  \
                                                                  Reset_Timer_START_SHIFT))

/* MASK */
#define Reset_Timer_1BIT_MASK                      ((uint32)0x01u)
#define Reset_Timer_2BIT_MASK                      ((uint32)0x03u)
#define Reset_Timer_3BIT_MASK                      ((uint32)0x07u)
#define Reset_Timer_6BIT_MASK                      ((uint32)0x3Fu)
#define Reset_Timer_8BIT_MASK                      ((uint32)0xFFu)
#define Reset_Timer_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define Reset_Timer_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define Reset_Timer_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(Reset_Timer_QUAD_ENCODING_MODES     << Reset_Timer_QUAD_MODE_SHIFT))       |\
         ((uint32)(Reset_Timer_CONFIG                  << Reset_Timer_MODE_SHIFT)))

#define Reset_Timer_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(Reset_Timer_PWM_STOP_EVENT          << Reset_Timer_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(Reset_Timer_PWM_OUT_INVERT          << Reset_Timer_INV_OUT_SHIFT))         |\
         ((uint32)(Reset_Timer_PWM_OUT_N_INVERT        << Reset_Timer_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(Reset_Timer_PWM_MODE                << Reset_Timer_MODE_SHIFT)))

#define Reset_Timer_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(Reset_Timer_PWM_RUN_MODE         << Reset_Timer_ONESHOT_SHIFT))
            
#define Reset_Timer_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(Reset_Timer_PWM_ALIGN            << Reset_Timer_UPDOWN_SHIFT))

#define Reset_Timer_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(Reset_Timer_PWM_KILL_EVENT      << Reset_Timer_PWM_SYNC_KILL_SHIFT))

#define Reset_Timer_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(Reset_Timer_PWM_DEAD_TIME_CYCLE  << Reset_Timer_PRESCALER_SHIFT))

#define Reset_Timer_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(Reset_Timer_PWM_PRESCALER        << Reset_Timer_PRESCALER_SHIFT))

#define Reset_Timer_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(Reset_Timer_TC_PRESCALER            << Reset_Timer_PRESCALER_SHIFT))       |\
         ((uint32)(Reset_Timer_TC_COUNTER_MODE         << Reset_Timer_UPDOWN_SHIFT))          |\
         ((uint32)(Reset_Timer_TC_RUN_MODE             << Reset_Timer_ONESHOT_SHIFT))         |\
         ((uint32)(Reset_Timer_TC_COMP_CAP_MODE        << Reset_Timer_MODE_SHIFT)))
        
#define Reset_Timer_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(Reset_Timer_QUAD_PHIA_SIGNAL_MODE   << Reset_Timer_COUNT_SHIFT))           |\
         ((uint32)(Reset_Timer_QUAD_INDEX_SIGNAL_MODE  << Reset_Timer_RELOAD_SHIFT))          |\
         ((uint32)(Reset_Timer_QUAD_STOP_SIGNAL_MODE   << Reset_Timer_STOP_SHIFT))            |\
         ((uint32)(Reset_Timer_QUAD_PHIB_SIGNAL_MODE   << Reset_Timer_START_SHIFT)))

#define Reset_Timer_PWM_SIGNALS_MODES                                                              \
        (((uint32)(Reset_Timer_PWM_SWITCH_SIGNAL_MODE  << Reset_Timer_CAPTURE_SHIFT))         |\
         ((uint32)(Reset_Timer_PWM_COUNT_SIGNAL_MODE   << Reset_Timer_COUNT_SHIFT))           |\
         ((uint32)(Reset_Timer_PWM_RELOAD_SIGNAL_MODE  << Reset_Timer_RELOAD_SHIFT))          |\
         ((uint32)(Reset_Timer_PWM_STOP_SIGNAL_MODE    << Reset_Timer_STOP_SHIFT))            |\
         ((uint32)(Reset_Timer_PWM_START_SIGNAL_MODE   << Reset_Timer_START_SHIFT)))

#define Reset_Timer_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(Reset_Timer_TC_CAPTURE_SIGNAL_MODE  << Reset_Timer_CAPTURE_SHIFT))         |\
         ((uint32)(Reset_Timer_TC_COUNT_SIGNAL_MODE    << Reset_Timer_COUNT_SHIFT))           |\
         ((uint32)(Reset_Timer_TC_RELOAD_SIGNAL_MODE   << Reset_Timer_RELOAD_SHIFT))          |\
         ((uint32)(Reset_Timer_TC_STOP_SIGNAL_MODE     << Reset_Timer_STOP_SHIFT))            |\
         ((uint32)(Reset_Timer_TC_START_SIGNAL_MODE    << Reset_Timer_START_SHIFT)))
        
#define Reset_Timer_TIMER_UPDOWN_CNT_USED                                                          \
                ((Reset_Timer__COUNT_UPDOWN0 == Reset_Timer_TC_COUNTER_MODE)                  ||\
                 (Reset_Timer__COUNT_UPDOWN1 == Reset_Timer_TC_COUNTER_MODE))

#define Reset_Timer_PWM_UPDOWN_CNT_USED                                                            \
                ((Reset_Timer__CENTER == Reset_Timer_PWM_ALIGN)                               ||\
                 (Reset_Timer__ASYMMETRIC == Reset_Timer_PWM_ALIGN))               
        
#define Reset_Timer_PWM_PR_INIT_VALUE              (1u)
#define Reset_Timer_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_Reset_Timer_H */

/* [] END OF FILE */
