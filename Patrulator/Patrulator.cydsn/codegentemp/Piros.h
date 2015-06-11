/*******************************************************************************
* File Name: Piros.h  
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

#if !defined(CY_PINS_Piros_H) /* Pins Piros_H */
#define CY_PINS_Piros_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Piros_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Piros_Write(uint8 value) ;
void    Piros_SetDriveMode(uint8 mode) ;
uint8   Piros_ReadDataReg(void) ;
uint8   Piros_Read(void) ;
uint8   Piros_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Piros_DRIVE_MODE_BITS        (3)
#define Piros_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Piros_DRIVE_MODE_BITS))

#define Piros_DM_ALG_HIZ         (0x00u)
#define Piros_DM_DIG_HIZ         (0x01u)
#define Piros_DM_RES_UP          (0x02u)
#define Piros_DM_RES_DWN         (0x03u)
#define Piros_DM_OD_LO           (0x04u)
#define Piros_DM_OD_HI           (0x05u)
#define Piros_DM_STRONG          (0x06u)
#define Piros_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Piros_MASK               Piros__MASK
#define Piros_SHIFT              Piros__SHIFT
#define Piros_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Piros_PS                     (* (reg32 *) Piros__PS)
/* Port Configuration */
#define Piros_PC                     (* (reg32 *) Piros__PC)
/* Data Register */
#define Piros_DR                     (* (reg32 *) Piros__DR)
/* Input Buffer Disable Override */
#define Piros_INP_DIS                (* (reg32 *) Piros__PC2)


#if defined(Piros__INTSTAT)  /* Interrupt Registers */

    #define Piros_INTSTAT                (* (reg32 *) Piros__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Piros_DRIVE_MODE_SHIFT       (0x00u)
#define Piros_DRIVE_MODE_MASK        (0x07u << Piros_DRIVE_MODE_SHIFT)


#endif /* End Pins Piros_H */


/* [] END OF FILE */
