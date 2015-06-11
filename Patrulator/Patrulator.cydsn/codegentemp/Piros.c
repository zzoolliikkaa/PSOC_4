/*******************************************************************************
* File Name: Piros.c  
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
#include "Piros.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Piros_PC =   (Piros_PC & \
                                (uint32)(~(uint32)(Piros_DRIVE_MODE_IND_MASK << (Piros_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Piros_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Piros_Write
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
void Piros_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Piros_DR & (uint8)(~Piros_MASK));
    drVal = (drVal | ((uint8)(value << Piros_SHIFT) & Piros_MASK));
    Piros_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Piros_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Piros_DM_STRONG     Strong Drive 
*  Piros_DM_OD_HI      Open Drain, Drives High 
*  Piros_DM_OD_LO      Open Drain, Drives Low 
*  Piros_DM_RES_UP     Resistive Pull Up 
*  Piros_DM_RES_DWN    Resistive Pull Down 
*  Piros_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Piros_DM_DIG_HIZ    High Impedance Digital 
*  Piros_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Piros_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Piros__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Piros_Read
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
*  Macro Piros_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Piros_Read(void) 
{
    return (uint8)((Piros_PS & Piros_MASK) >> Piros_SHIFT);
}


/*******************************************************************************
* Function Name: Piros_ReadDataReg
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
uint8 Piros_ReadDataReg(void) 
{
    return (uint8)((Piros_DR & Piros_MASK) >> Piros_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Piros_INTSTAT) 

    /*******************************************************************************
    * Function Name: Piros_ClearInterrupt
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
    uint8 Piros_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Piros_INTSTAT & Piros_MASK);
		Piros_INTSTAT = maskedStatus;
        return maskedStatus >> Piros_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
