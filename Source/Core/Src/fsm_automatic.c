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
		setTimer1(counter_green * 100);
		setTimer2(50);
		setTimer3(100);
		counter = counter_green;
		break;

	case S0: // //NS_Green, EW_Red
		LED_RED_OFF();
		LED_YELLOW_OFF();
		LED_GREEN_ON();

		RED_ON();
		YELLOW_OFF();
		GREEN_OFF();

		led_buffer[0] = counter % 10;
		led_buffer[1] = counter / 10;
		led_buffer[2] = (counter + counter_yellow) % 10;
		led_buffer[3] = (counter + counter_yellow) / 10;

		if(timer1_flag == 1){
			status = S1;
			counter = counter_yellow;
			setTimer1(counter_yellow * 100);
		}

		if(isButton1Pressed() == 1){
			status = SET_RED;
			temp = 1;
		}
		break;

	case S1: //NS_Yellow, EW_Red
		LED_RED_OFF();
		LED_YELLOW_ON();
		LED_GREEN_OFF();

		RED_ON();
		YELLOW_OFF();
		GREEN_OFF();

		led_buffer[0] = counter % 10;
		led_buffer[1] = counter / 10;
		led_buffer[2] = counter % 10;
		led_buffer[3] = counter / 10;

		if(timer1_flag == 1){
			status = S2;
			counter = counter_red;
			setTimer1(counter_green * 100);
		}

		if(isButton1Pressed() == 1){
			status = SET_RED;
			temp = 1;
		}
		break;

	case S2: //NS_Red, EW_Green
		LED_RED_ON();
		LED_YELLOW_OFF();
		LED_GREEN_OFF();

		RED_OFF();
		YELLOW_OFF();
		GREEN_ON();

		led_buffer[0] = counter % 10;
		led_buffer[1] = counter / 10;
		led_buffer[2] = (counter - counter_yellow) % 10;
		led_buffer[3] = (counter - counter_yellow) / 10;

		if(timer1_flag == 1){
			status = S3;
			counter = counter_yellow;
			setTimer1(counter_yellow * 100);
		}

		if(isButton1Pressed() == 1){
			status = SET_RED;
			temp = 1;
		}
		break;

	case S3: //NS_Red, EW_Yellow
		LED_RED_ON();
		LED_YELLOW_OFF();
		LED_GREEN_OFF();

		RED_OFF();
		YELLOW_ON();
		GREEN_OFF();

		led_buffer[0] = counter % 10;
		led_buffer[1] = counter / 10;
		led_buffer[2] = counter % 10;
		led_buffer[3] = counter / 10;

		if(timer1_flag == 1){
			status = S0;
			counter = counter_green;
			setTimer1(counter_green * 100);
		}

		if(isButton1Pressed() == 1){
			status = SET_RED;
			temp = 1;
		}
		break;

	default:
		fsm_setup_run();
		break;
	}
}
