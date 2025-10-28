/*
 * fsm_automatic.c
 *
 *  Created on: Sep 4, 2025
 *      Author: Admin
 */
#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status){
	case INIT:
		allOn();
		status = S0;
		setTimer(1, 300);
		counter = counter_green;
		break;

	case S0: // //NS_Green, EW_Red
		LED_RED_OFF();
		LED_YELLOW_OFF();
		LED_GREEN_ON();

		RED_ON();
		YELLOW_OFF();
		GREEN_OFF();

		if(timer_flag[1] == 1){
			status = S1;
			counter = counter_yellow;
			setTimer(1, 200);
		}

		if(isButtonPressed(1) == 1){
			status = SET_GREEN;
			temp = 0;
		}
		break;

	case S1: //NS_Yellow, EW_Red
		LED_RED_OFF();
		LED_YELLOW_ON();
		LED_GREEN_OFF();

		RED_ON();
		YELLOW_OFF();
		GREEN_OFF();

		display7SEG(counter);

		if(timer_flag[1] == 1){
			status = S2;
			counter = counter_red;
			setTimer(1, 300);
		}

		if(isButtonPressed(1) == 1){
			status = SET_GREEN;
			temp = 0;
		}
		break;

	case S2: //NS_Red, EW_Green
		LED_RED_ON();
		LED_YELLOW_OFF();
		LED_GREEN_OFF();

		RED_OFF();
		YELLOW_OFF();
		GREEN_ON();

		display7SEG(counter);

		if(timer_flag[1] == 1){
			status = S3;
			counter = counter_yellow;
			setTimer(1, 200);
		}

		if(isButtonPressed(1) == 1){
			status = SET_GREEN;
			temp = 0;
		}
		break;

	case S3: //NS_Red, EW_Yellow
		LED_RED_ON();
		LED_YELLOW_OFF();
		LED_GREEN_OFF();

		RED_OFF();
		YELLOW_ON();
		GREEN_OFF();

		display7SEG(counter);

		if(timer_flag[1] == 1){
			status = S0;
			counter = counter_green;
			setTimer(1, 300);
		}

		if(isButtonPressed(1) == 1){
			status = SET_GREEN;
			temp = 0;
		}
		break;

	default:
		break;
	}
}
