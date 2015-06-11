/*******************************************************************************
* File Name: RFID_REG_PM.c
* Version 2.30
*
* Description:
*  This file provides the API source code for sleep mode support for Shift
*  Register component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "RFID_REG.h"

static RFID_REG_BACKUP_STRUCT RFID_REG_backup =
{
    RFID_REG_DISABLED,

    ((uint16) RFID_REG_DEFAULT_A0),
    ((uint16) RFID_REG_DEFAULT_A1),

    #if(CY_UDB_V0)
        ((uint16) RFID_REG_INT_SRC),
    #endif /* (CY_UDB_V0) */
};


/*******************************************************************************
* Function Name: RFID_REG_SaveConfig
********************************************************************************
*
* Summary:
*  Saves Shift Register configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void RFID_REG_SaveConfig(void) 
{
    /* Store working registers A0 and A1 */
    RFID_REG_backup.saveSrA0Reg   = CY_GET_REG16(RFID_REG_SHIFT_REG_LSB_PTR);
    RFID_REG_backup.saveSrA1Reg   = CY_GET_REG16(RFID_REG_SHIFT_REG_VALUE_LSB_PTR);

    #if(CY_UDB_V0)
        RFID_REG_backup.saveSrIntMask = RFID_REG_SR_STATUS_MASK;
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: RFID_REG_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores Shift Register configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void RFID_REG_RestoreConfig(void) 
{
    /* Restore working registers A0 and A1 */
    CY_SET_REG16(RFID_REG_SHIFT_REG_LSB_PTR, RFID_REG_backup.saveSrA0Reg);
    CY_SET_REG16(RFID_REG_SHIFT_REG_VALUE_LSB_PTR, RFID_REG_backup.saveSrA1Reg);

    #if(CY_UDB_V0)
        RFID_REG_SR_STATUS_MASK = ((uint8) RFID_REG_backup.saveSrIntMask);
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: RFID_REG_Sleep
********************************************************************************
*
* Summary:
*  Prepare the component to enter a Sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void RFID_REG_Sleep(void) 
{
    RFID_REG_backup.enableState = ((uint8) RFID_REG_IS_ENABLED);

    RFID_REG_Stop();
    RFID_REG_SaveConfig();
}


/*******************************************************************************
* Function Name: RFID_REG_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void RFID_REG_Wakeup(void) 
{
    RFID_REG_RestoreConfig();

    if(0u != RFID_REG_backup.enableState)
    {
        RFID_REG_Enable();
    }
}


/* [] END OF FILE */
