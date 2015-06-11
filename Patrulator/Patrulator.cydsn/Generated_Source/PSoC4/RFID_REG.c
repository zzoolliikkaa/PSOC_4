/*******************************************************************************
* File Name: RFID_REG.c
* Version 2.30
*
* Description:
*  This file provides the API source code for the Shift Register component.
*
* Note: none
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "RFID_REG.h"

uint8 RFID_REG_initVar = 0u;


/*******************************************************************************
* Function Name: RFID_REG_Start
********************************************************************************
*
* Summary:
*  Starts the Shift Register.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  RFID_REG_initVar - used to check initial configuration, modified on
*  first function call.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void RFID_REG_Start(void) 
{
    if(0u == RFID_REG_initVar)
    {
        RFID_REG_Init();
        RFID_REG_initVar = 1u; /* Component initialized */
    }

    RFID_REG_Enable();
}


/*******************************************************************************
* Function Name: RFID_REG_Enable
********************************************************************************
*
* Summary:
*  Enables the Shift Register.
*
* Parameters:
*  void.
*
* Return:
*  void.
*
*******************************************************************************/
void RFID_REG_Enable(void) 
{
    /* Changing address in Datapath Control Store
       from NOP to component state machine commands space */
    RFID_REG_SR_CONTROL |= RFID_REG_CLK_EN;

    RFID_REG_EnableInt();
}


/*******************************************************************************
* Function Name: RFID_REG_Init
********************************************************************************
*
* Summary:
*  Initializes Tx and/or Rx interrupt sources with initial values.
*
* Parameters:
*  void.
*
* Return:
*  void.
*
*******************************************************************************/
void RFID_REG_Init(void) 
{
    RFID_REG_SetIntMode(RFID_REG_INT_SRC);
}


/*******************************************************************************
* Function Name: RFID_REG_Stop
********************************************************************************
*
* Summary:
*  Disables the Shift Register
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void RFID_REG_Stop(void) 
{
    /*changing Datapath Control Store address to NOP space*/
    RFID_REG_SR_CONTROL &= ((uint8) ~RFID_REG_CLK_EN);
    RFID_REG_DisableInt();
}


/*******************************************************************************
* Function Name: RFID_REG_EnableInt
********************************************************************************
*
* Summary:
*  Enables the Shift Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void RFID_REG_EnableInt(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    RFID_REG_SR_AUX_CONTROL |= RFID_REG_INTERRUPTS_ENABLE;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: RFID_REG_DisableInt
********************************************************************************
*
* Summary:
*  Disables the Shift Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void RFID_REG_DisableInt(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    RFID_REG_SR_AUX_CONTROL &= ((uint8) ~RFID_REG_INTERRUPTS_ENABLE);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: RFID_REG_GetFIFOStatus
********************************************************************************
*
* Summary:
*  Returns current status of input or output FIFO.
*
* Parameters:
*  fifoId.
*
* Return:
*  FIFO status.
*
*******************************************************************************/
uint8 RFID_REG_GetFIFOStatus(uint8 fifoId) 
{
    uint8 result;

    result = RFID_REG_RET_FIFO_NOT_DEFINED;

    #if(0u != RFID_REG_USE_INPUT_FIFO)
        if(RFID_REG_IN_FIFO == fifoId)
        {
            switch(RFID_REG_GET_IN_FIFO_STS)
            {
                case RFID_REG_IN_FIFO_FULL :
                    result = RFID_REG_RET_FIFO_FULL;
                    break;

                case RFID_REG_IN_FIFO_EMPTY :
                    result = RFID_REG_RET_FIFO_EMPTY;
                    break;

                case RFID_REG_IN_FIFO_PARTIAL:
                    result = RFID_REG_RET_FIFO_PARTIAL;
                    break;
                    
                default:
                    /* Initial result value, while 
                       IN_FIFO_EMPTY case is false 
                     */
                    result = RFID_REG_RET_FIFO_EMPTY;
                    break;
            }   
        }
    #endif /* (0u != RFID_REG_USE_INPUT_FIFO) */

    if(RFID_REG_OUT_FIFO == fifoId)
    {
        switch(RFID_REG_GET_OUT_FIFO_STS)
        {
            case RFID_REG_OUT_FIFO_FULL :
                result = RFID_REG_RET_FIFO_FULL;
                break;

            case RFID_REG_OUT_FIFO_EMPTY :
                result = RFID_REG_RET_FIFO_EMPTY;
                break;

            case RFID_REG_OUT_FIFO_PARTIAL :
                result = RFID_REG_RET_FIFO_PARTIAL;
                break;

            default:
                /* Initial result value, while 
                   OUT_FIFO_FULL case is false 
                 */
                result = RFID_REG_RET_FIFO_FULL;
                break;
        }
    }

    return(result);
}


/*******************************************************************************
* Function Name: RFID_REG_SetIntMode
********************************************************************************
*
* Summary:
*  Sets the Interrupt Source for the Shift Register interrupt. Multiple
*  sources may be ORed together
*
* Parameters:
*  interruptSource: Byte containing the constant for the selected interrupt
*  source/s.
*
* Return:
*  None.
*
*******************************************************************************/
void RFID_REG_SetIntMode(uint8 interruptSource) 
{
    RFID_REG_SR_STATUS_MASK &= ((uint8) ~RFID_REG_INTS_EN_MASK);          /* Clear existing int */
    RFID_REG_SR_STATUS_MASK |= (interruptSource & RFID_REG_INTS_EN_MASK); /* Set int */
}


/*******************************************************************************
* Function Name: RFID_REG_GetIntStatus
********************************************************************************
*
* Summary:
*  Gets the Shift Register Interrupt status.
*
* Parameters:
*  None.
*
* Return:
*  Byte containing the constant for the selected interrupt source/s.
*
*******************************************************************************/
uint8 RFID_REG_GetIntStatus(void) 
{
    return(RFID_REG_SR_STATUS & RFID_REG_INTS_EN_MASK);
}


/*******************************************************************************
* Function Name: RFID_REG_WriteRegValue
********************************************************************************
*
* Summary:
*  Send state directly to shift register
*
* Parameters:
*  shiftData: containing shift register state.
*
* Return:
*  None.
*
*******************************************************************************/
void RFID_REG_WriteRegValue(uint16 shiftData)
                                                                     
{
    CY_SET_REG16(RFID_REG_SHIFT_REG_LSB_PTR, shiftData);
}


#if(0u != RFID_REG_USE_INPUT_FIFO)
    /*******************************************************************************
    * Function Name: RFID_REG_WriteData
    ********************************************************************************
    *
    * Summary:
    *  Send state to FIFO for later transfer to shift register based on the Load
    *  input
    *
    * Parameters:
    *  shiftData: containing shift register state.
    *
    * Return:
    *  Indicates: successful execution of function
    *  when FIFO is empty; and error when FIFO is full.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    cystatus RFID_REG_WriteData(uint16 shiftData)
                                                                         
    {
        cystatus result;

        result = CYRET_INVALID_STATE;

        /* Writes data into the input FIFO if it is not FULL */
        if(RFID_REG_RET_FIFO_FULL != (RFID_REG_GetFIFOStatus(RFID_REG_IN_FIFO)))
        {
            CY_SET_REG16(RFID_REG_IN_FIFO_VAL_LSB_PTR, shiftData);
            result = CYRET_SUCCESS;
        }

        return(result);
    }
#endif /* (0u != RFID_REG_USE_INPUT_FIFO) */


#if(0u != RFID_REG_USE_OUTPUT_FIFO)
    /*******************************************************************************
    * Function Name: RFID_REG_ReadData
    ********************************************************************************
    *
    * Summary:
    *  Returns state in FIFO due to Store input.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Shift Register state
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    uint16 RFID_REG_ReadData(void) 
    {
        return(CY_GET_REG16(RFID_REG_OUT_FIFO_VAL_LSB_PTR));
    }
#endif /* (0u != RFID_REG_USE_OUTPUT_FIFO) */


/*******************************************************************************
* Function Name: RFID_REG_ReadRegValue
********************************************************************************
*
* Summary:
*  Directly returns current state in shift register, not data in FIFO due
*  to Store input.
*
* Parameters:
*  None.
*
* Return:
*  Shift Register state. Clears output FIFO.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint16 RFID_REG_ReadRegValue(void) 
{
    uint16 result;

    /* Clear FIFO before software capture */
    while(RFID_REG_RET_FIFO_EMPTY != RFID_REG_GetFIFOStatus(RFID_REG_OUT_FIFO))
    {
        (void) CY_GET_REG16(RFID_REG_OUT_FIFO_VAL_LSB_PTR);
    }

    /* Read of 8 bits from A1 causes capture to output FIFO */
    (void) CY_GET_REG8(RFID_REG_SHIFT_REG_CAPTURE_PTR);

    /* Read output FIFO */
    result  = CY_GET_REG16(RFID_REG_OUT_FIFO_VAL_LSB_PTR);
    
    #if(0u != (RFID_REG_SR_SIZE % 8u))
        result &= ((uint16) RFID_REG_SR_MASK);
    #endif /* (0u != (RFID_REG_SR_SIZE % 8u)) */
    
    return(result);
}


/* [] END OF FILE */
