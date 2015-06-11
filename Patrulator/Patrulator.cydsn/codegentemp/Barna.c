/*******************************************************************************
* File Name: Barna.c  
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
#include "Barna.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Barna_PC =   (Barna_PC & \
                                (uint32)(~(uint32)(Barna_DRIVE_MODE_IND_MASK << (Barna_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Barna_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Barna_Write
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
void Barna_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Barna_DR & (uint8)(~Barna_MASK));
    drVal = (drVal | ((uint8)(value << Barna_SHIFT) & Barna_MASK));
    Barna_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Barna_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Barna_DM_STRONG     Strong Drive 
*  Barna_DM_OD_HI      Open Drain, Drives High 
*  Barna_DM_OD_LO      Open Drain, Drives Low 
*  Barna_DM_RES_UP     Resistive Pull Up 
*  Barna_DM_RES_DWN    Resistive Pull Down 
*  Barna_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Barna_DM_DIG_HIZ    High Impedance Digital 
*  Barna_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Barna_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Barna__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Barna_Read
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
*  Macro Barna_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Barna_Read(void) 
{
    return (uint8)((Barna_PS & Barna_MASK) >> Barna_SHIFT);
}


/*******************************************************************************
* Function Name: Barna_ReadDataReg
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
uint8 Barna_ReadDataReg(void) 
{
    return (uint8)((Barna_DR & Barna_MASK) >> Barna_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Barna_INTSTAT) 

    /*******************************************************************************
    * Function Name: Barna_ClearInterrupt
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
    uint8 Barna_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Barna_INTSTAT & Barna_MASK);
		Barna_INTSTAT = maskedStatus;
        return maskedStatus >> Barna_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
