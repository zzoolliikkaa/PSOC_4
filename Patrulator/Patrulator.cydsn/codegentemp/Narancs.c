/*******************************************************************************
* File Name: Narancs.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Narancs.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Narancs_PC =   (Narancs_PC & \
                                (uint32)(~(uint32)(Narancs_DRIVE_MODE_IND_MASK << (Narancs_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Narancs_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Narancs_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void Narancs_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Narancs_DR & (uint8)(~Narancs_MASK));
    drVal = (drVal | ((uint8)(value << Narancs_SHIFT) & Narancs_MASK));
    Narancs_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Narancs_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Narancs_DM_STRONG     Strong Drive 
*  Narancs_DM_OD_HI      Open Drain, Drives High 
*  Narancs_DM_OD_LO      Open Drain, Drives Low 
*  Narancs_DM_RES_UP     Resistive Pull Up 
*  Narancs_DM_RES_DWN    Resistive Pull Down 
*  Narancs_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Narancs_DM_DIG_HIZ    High Impedance Digital 
*  Narancs_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Narancs_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Narancs__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Narancs_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Narancs_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Narancs_Read(void) 
{
    return (uint8)((Narancs_PS & Narancs_MASK) >> Narancs_SHIFT);
}


/*******************************************************************************
* Function Name: Narancs_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Narancs_ReadDataReg(void) 
{
    return (uint8)((Narancs_DR & Narancs_MASK) >> Narancs_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Narancs_INTSTAT) 

    /*******************************************************************************
    * Function Name: Narancs_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Narancs_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Narancs_INTSTAT & Narancs_MASK);
		Narancs_INTSTAT = maskedStatus;
        return maskedStatus >> Narancs_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
