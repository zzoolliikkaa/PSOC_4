/*******************************************************************************
* File Name: Count_Bits.h
* Version 1.0
*
* Description:
*  This header file contains registers and constants associated with the
*  Count7 component.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_COUNT7_Count_Bits_H)
#define CY_COUNT7_Count_Bits_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
* Function Prototypes
***************************************/
void  Count_Bits_Init(void) ;
void  Count_Bits_Enable(void) ;
void  Count_Bits_Start(void) ;
void  Count_Bits_Stop(void) ;
void  Count_Bits_WriteCounter(uint8 count) ;
uint8 Count_Bits_ReadCounter(void) ;
void  Count_Bits_WritePeriod(uint8 period) ;
uint8 Count_Bits_ReadPeriod(void) ;
void  Count_Bits_SaveConfig(void) ;
void  Count_Bits_RestoreConfig(void) ;
void  Count_Bits_Sleep(void) ;
void  Count_Bits_Wakeup(void) ;


/***************************************
*     Data Struct Definitions
***************************************/
/* Structure to save registers before go to sleep */
typedef struct
{
    uint8 enableState;
    uint8 count;
} Count_Bits_BACKUP_STRUCT;


/***************************************
*           Global Variables
***************************************/
extern Count_Bits_BACKUP_STRUCT Count_Bits_backup;
extern uint8 Count_Bits_initVar;


/***************************************
* Initial Parameter
***************************************/
#define Count_Bits_INITIAL_PERIOD               (0u)


/***************************************
* Registers
***************************************/
#define Count_Bits_COUNT_REG                    (*(reg8 *) Count_Bits_Counter7__COUNT_REG)
#define Count_Bits_COUNT_PTR                    ( (reg8 *) Count_Bits_Counter7__COUNT_REG)
#define Count_Bits_PERIOD_REG                   (*(reg8 *) Count_Bits_Counter7__PERIOD_REG)
#define Count_Bits_PERIOD_PTR                   ( (reg8 *) Count_Bits_Counter7__PERIOD_REG)
#define Count_Bits_AUX_CONTROL_REG              (*(reg8 *) Count_Bits_Counter7__CONTROL_AUX_CTL_REG)
#define Count_Bits_AUX_CONTROL_PTR              ( (reg8 *) Count_Bits_Counter7__CONTROL_AUX_CTL_REG)


/***************************************
* Register Constants
***************************************/
#define Count_Bits_COUNTER_START                (0x20u)

/* This constant is used to mask the TC bit (bit#7) in the Count register */
#define Count_Bits_COUNT_7BIT_MASK              (0x7Fu)


#endif /* CY_COUNT7_Count_Bits_H */


/* [] END OF FILE */
