/*******************************************************************************
* File Name: Sarga.h  
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

#if !defined(CY_PINS_Sarga_H) /* Pins Sarga_H */
#define CY_PINS_Sarga_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Sarga_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Sarga_Write(uint8 value) ;
void    Sarga_SetDriveMode(uint8 mode) ;
uint8   Sarga_ReadDataReg(void) ;
uint8   Sarga_Read(void) ;
uint8   Sarga_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Sarga_DRIVE_MODE_BITS        (3)
#define Sarga_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Sarga_DRIVE_MODE_BITS))

#define Sarga_DM_ALG_HIZ         (0x00u)
#define Sarga_DM_DIG_HIZ         (0x01u)
#define Sarga_DM_RES_UP          (0x02u)
#define Sarga_DM_RES_DWN         (0x03u)
#define Sarga_DM_OD_LO           (0x04u)
#define Sarga_DM_OD_HI           (0x05u)
#define Sarga_DM_STRONG          (0x06u)
#define Sarga_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Sarga_MASK               Sarga__MASK
#define Sarga_SHIFT              Sarga__SHIFT
#define Sarga_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Sarga_PS                     (* (reg32 *) Sarga__PS)
/* Port Configuration */
#define Sarga_PC                     (* (reg32 *) Sarga__PC)
/* Data Register */
#define Sarga_DR                     (* (reg32 *) Sarga__DR)
/* Input Buffer Disable Override */
#define Sarga_INP_DIS                (* (reg32 *) Sarga__PC2)


#if defined(Sarga__INTSTAT)  /* Interrupt Registers */

    #define Sarga_INTSTAT                (* (reg32 *) Sarga__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Sarga_DRIVE_MODE_SHIFT       (0x00u)
#define Sarga_DRIVE_MODE_MASK        (0x07u << Sarga_DRIVE_MODE_SHIFT)


#endif /* End Pins Sarga_H */


/* [] END OF FILE */
