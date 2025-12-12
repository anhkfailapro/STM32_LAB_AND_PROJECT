/*
 * fsm_man.c
 *
 *  Created on: Nov 1, 2025
 *      Author: Admin
 */

#include "fsm_man.h"

void  fsm_man(){
	switch (status) {
	case man_red:
		LED_RED_ON(); LED_GREEN_OFF(); LED_YELLOW_OFF();
		RED_OFF(); GREEN_ON(); YELLOW_OFF();
		SEG_Off();
		if(isButton4Pressed() == 1){
					status = man_green;
				}
		if(isButton1Pressed() == 1){
					status = S2;
				}
		break;
	case man_green:
		LED_RED_OFF(); LED_GREEN_ON(); LED_YELLOW_OFF();
		RED_ON(); GREEN_OFF(); YELLOW_OFF();

		SEG_Off();
		if(isButton4Pressed() == 1){
					status = man_red;
				}
		if(isButton1Pressed() == 1){
					status = S0;
				}
	default:
		break;
	}
}
