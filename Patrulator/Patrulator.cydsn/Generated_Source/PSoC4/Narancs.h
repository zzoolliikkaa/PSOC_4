/*******************************************************************************
* File Name: Narancs.h  
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

#if !defined(CY_PINS_Narancs_H) /* Pins Narancs_H */
#define CY_PINS_Narancs_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Narancs_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Narancs_Write(uint8 value) ;
void    Narancs_SetDriveMode(uint8 mode) ;
uint8   Narancs_ReadDataReg(void) ;
uint8   Narancs_Read(void) ;
uint8   Narancs_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Narancs_DRIVE_MODE_BITS        (3)
#define Narancs_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Narancs_DRIVE_MODE_BITS))

#define Narancs_DM_ALG_HIZ         (0x00u)
#define Narancs_DM_DIG_HIZ         (0x01u)
#define Narancs_DM_RES_UP          (0x02u)
#define Narancs_DM_RES_DWN         (0x03u)
#define Narancs_DM_OD_LO           (0x04u)
#define Narancs_DM_OD_HI           (0x05u)
#define Narancs_DM_STRONG          (0x06u)
#define Narancs_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Narancs_MASK               Narancs__MASK
#define Narancs_SHIFT              Narancs__SHIFT
#define Narancs_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Narancs_PS                     (* (reg32 *) Narancs__PS)
/* Port Configuration */
#define Narancs_PC                     (* (reg32 *) Narancs__PC)
/* Data Register */
#define Narancs_DR                     (* (reg32 *) Narancs__DR)
/* Input Buffer Disable Override */
#define Narancs_INP_DIS                (* (reg32 *) Narancs__PC2)


#if defined(Narancs__INTSTAT)  /* Interrupt Registers */

    #define Narancs_INTSTAT                (* (reg32 *) Narancs__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Narancs_DRIVE_MODE_SHIFT       (0x00u)
#define Narancs_DRIVE_MODE_MASK        (0x07u << Narancs_DRIVE_MODE_SHIFT)


#endif /* End Pins Narancs_H */


/* [] END OF FILE */
