/*******************************************************************************
* File Name: RFID_RX.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_RFID_RX_H) /* Pins RFID_RX_H */
#define CY_PINS_RFID_RX_H

#include "cytypes.h"
#include "cyfitter.h"
#include "RFID_RX_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    RFID_RX_Write(uint8 value) ;
void    RFID_RX_SetDriveMode(uint8 mode) ;
uint8   RFID_RX_ReadDataReg(void) ;
uint8   RFID_RX_Read(void) ;
uint8   RFID_RX_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RFID_RX_DRIVE_MODE_BITS        (3)
#define RFID_RX_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - RFID_RX_DRIVE_MODE_BITS))

#define RFID_RX_DM_ALG_HIZ         (0x00u)
#define RFID_RX_DM_DIG_HIZ         (0x01u)
#define RFID_RX_DM_RES_UP          (0x02u)
#define RFID_RX_DM_RES_DWN         (0x03u)
#define RFID_RX_DM_OD_LO           (0x04u)
#define RFID_RX_DM_OD_HI           (0x05u)
#define RFID_RX_DM_STRONG          (0x06u)
#define RFID_RX_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define RFID_RX_MASK               RFID_RX__MASK
#define RFID_RX_SHIFT              RFID_RX__SHIFT
#define RFID_RX_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RFID_RX_PS                     (* (reg32 *) RFID_RX__PS)
/* Port Configuration */
#define RFID_RX_PC                     (* (reg32 *) RFID_RX__PC)
/* Data Register */
#define RFID_RX_DR                     (* (reg32 *) RFID_RX__DR)
/* Input Buffer Disable Override */
#define RFID_RX_INP_DIS                (* (reg32 *) RFID_RX__PC2)


#if defined(RFID_RX__INTSTAT)  /* Interrupt Registers */

    #define RFID_RX_INTSTAT                (* (reg32 *) RFID_RX__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define RFID_RX_DRIVE_MODE_SHIFT       (0x00u)
#define RFID_RX_DRIVE_MODE_MASK        (0x07u << RFID_RX_DRIVE_MODE_SHIFT)


#endif /* End Pins RFID_RX_H */


/* [] END OF FILE */
