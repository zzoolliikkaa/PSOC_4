/*******************************************************************************
* File Name: Barna.h  
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

#if !defined(CY_PINS_Barna_H) /* Pins Barna_H */
#define CY_PINS_Barna_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Barna_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Barna_Write(uint8 value) ;
void    Barna_SetDriveMode(uint8 mode) ;
uint8   Barna_ReadDataReg(void) ;
uint8   Barna_Read(void) ;
uint8   Barna_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Barna_DRIVE_MODE_BITS        (3)
#define Barna_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Barna_DRIVE_MODE_BITS))

#define Barna_DM_ALG_HIZ         (0x00u)
#define Barna_DM_DIG_HIZ         (0x01u)
#define Barna_DM_RES_UP          (0x02u)
#define Barna_DM_RES_DWN         (0x03u)
#define Barna_DM_OD_LO           (0x04u)
#define Barna_DM_OD_HI           (0x05u)
#define Barna_DM_STRONG          (0x06u)
#define Barna_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Barna_MASK               Barna__MASK
#define Barna_SHIFT              Barna__SHIFT
#define Barna_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Barna_PS                     (* (reg32 *) Barna__PS)
/* Port Configuration */
#define Barna_PC                     (* (reg32 *) Barna__PC)
/* Data Register */
#define Barna_DR                     (* (reg32 *) Barna__DR)
/* Input Buffer Disable Override */
#define Barna_INP_DIS                (* (reg32 *) Barna__PC2)


#if defined(Barna__INTSTAT)  /* Interrupt Registers */

    #define Barna_INTSTAT                (* (reg32 *) Barna__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Barna_DRIVE_MODE_SHIFT       (0x00u)
#define Barna_DRIVE_MODE_MASK        (0x07u << Barna_DRIVE_MODE_SHIFT)


#endif /* End Pins Barna_H */


/* [] END OF FILE */
