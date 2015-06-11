/*******************************************************************************
* File Name: Count_Bits_PM.c
* Version 1.0
*
* Description:
*  This file provides Low power mode APIs for Count7 component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Count_Bits.h"


Count_Bits_BACKUP_STRUCT Count_Bits_backup;


/*******************************************************************************
* Function Name: Count_Bits_SaveConfig
********************************************************************************
*
* Summary:
*  This function saves the component configuration and non-retention registers.
*  This function is called by the Count7_Sleep() function.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  Count_Bits_backup - used to save component configuration and non-
*  retention registers before enter sleep mode.
*
*******************************************************************************/
void Count_Bits_SaveConfig(void) 
{
    Count_Bits_backup.count = Count_Bits_COUNT_REG;
}


/*******************************************************************************
* Function Name: Count_Bits_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred API to prepare the component for low power mode
*  operation. The Count7_Sleep() API saves the current component state using
*  Count7_SaveConfig() and disables the counter.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Count_Bits_Sleep(void) 
{
    if(0u != (Count_Bits_AUX_CONTROL_REG & Count_Bits_COUNTER_START))
    {
        Count_Bits_backup.enableState = 1u;
        Count_Bits_Stop();
    }
    else
    {
        Count_Bits_backup.enableState = 0u;
    }

    Count_Bits_SaveConfig();
}


/*******************************************************************************
* Function Name: Count_Bits_RestoreConfig
********************************************************************************
*
* Summary:
*  This function restores the component configuration and non-retention
*  registers. This function is called by the Count7_Wakeup() function.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  Count_Bits_backup - used to save component configuration and
*  non-retention registers before exit sleep mode.
*
*******************************************************************************/
void Count_Bits_RestoreConfig(void) 
{
    Count_Bits_COUNT_REG = Count_Bits_backup.count;
}


/*******************************************************************************
* Function Name: Count_Bits_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred API to restore the component to the state when
*  Count7_Sleep() was called. The Count7_Wakeup() function calls the
*  Count7_RestoreConfig() function to restore the configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Count_Bits_Wakeup(void) 
{
    Count_Bits_RestoreConfig();

    /* Restore enable state */
    if (Count_Bits_backup.enableState != 0u)
    {
        Count_Bits_Enable();
    }
}


/* [] END OF FILE */
