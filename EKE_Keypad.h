/*
 * EKE_Keypad.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-safi
 */

#ifndef EKE_KEYPAD_H_
#define EKE_KEYPAD_H_

#include "EKE_KeypadConfig.h"

                   /** API FUNCTIONS  **/

void EKE_keypad_init(void);
/*********************************************************************
* Function    : void EKE_keypad_init();
*
* DESCRIPTION : This function used to Initialize keypad
*
* PARAMETERS  : Void.
*
*
* Return Value: Void.
*********************************************************************/

U16_t EKE_getKey(void);

/*********************************************************************
* Function    : U16_t EKE_getKey(void);
*
* DESCRIPTION : This function used to scan the input if it existed
*
* PARAMETERS  : void
*
*
* Return Value: U16_t : Return number from (0 to 9) and Symbols
*   [1|2|3|A]
*  	[4|5|6|B]
* 	[7|8|9|C]
*   [*|0|#|D]
*
***********************************************************************/
#endif /* EKE_KEYPAD_H_ */
