/*
 * fsm_SETual.c
 *
 *  Created on: Sep 4, 2025
 *      Author: Admin
 */
#include <fsm_setup.h>

void change_counter(int led){
	int sum = 0;
	int delta = 0;
	switch(led) {
	case Change_red:
	if(counter_red == 1) {
		counter_green = 1;
		counter_yellow = 1;
		counter_red = 2;
		break;
	}
    sum = counter_green + counter_yellow;
    delta = counter_red - sum;

    // Nếu delta >= 0 (tăng)
    if (delta >= 0) {
        counter_green += delta;

        if (counter_green > 99) {
            int excess = counter_green - 99;
            counter_green = 99;
            counter_yellow += excess;
            if (counter_yellow > 99) counter_yellow = 99;
        }
    }
    // Nếu delta < 0 (giảm)
    else {
        counter_green += delta;   // giảm green trước

        if (counter_green < 0) {
            int shortage = -counter_green;
            counter_green = 0;
            counter_yellow -= shortage;
            if (counter_yellow < 0) counter_yellow = 0;
        }
    }
    break;
	case Change_green:
	    counter_red = counter_green + counter_yellow;

	    // Nếu red vượt 99 → giảm yellow
	    if (counter_red > 99) {
	        int overflow = counter_red - 99;
	        counter_red = 99;
	        counter_yellow -= overflow;
	        if (counter_yellow < 0) counter_yellow = 0;
	    }

	    // Nếu green giảm → red giảm

	    break;
	case Change_yellow:
	    counter_red = counter_green + counter_yellow;

	    if (counter_red > 99) {
	        int overflow = counter_red - 99;
	        counter_red = 99;
	        counter_green -= overflow;
	        if (counter_green < 0) counter_green = 0;
	    }

	    break;
	 default:
	    break;
	}
}

void fsm_setup_run(){
	switch (status) {
	    case SET_RED:
	        // Đèn đỏ nhấp nháy 2Hz
	        if (timer2_flag == 1) {
	            setTimer2(100);
	            LED_RED_Toggle();
	            RED_Toggle();
	        }
	        LED_YELLOW_OFF();
	        LED_GREEN_OFF();
	        YELLOW_OFF();
	        GREEN_OFF();
	        updateLedBuffer_set();
	        if (isButton2Pressed() == 1) {
	            temp++;
	            if (temp > 99) temp = 1;
	            updateLedBuffer_set();
	        }

	        if (isButton1Pressed() == 1) {
	            status = SET_YELLOW;
	            temp = 1;
	        }

	        if (isButton3Pressed() == 1){
	            counter_red = temp;
	            change_counter(Change_red);
	        }
	        break;

	    case SET_GREEN:
	        // Đèn xanh nhấp nháy 2Hz
	        if (timer2_flag == 1) {
	            setTimer2(50);
	            LED_GREEN_Toggle();
	            GREEN_Toggle();
	        }
	        LED_RED_OFF();
	        LED_YELLOW_OFF();
	        RED_OFF();
	        YELLOW_OFF();
	        updateLedBuffer_set();
	        if (isButton2Pressed() == 1) {
	       	            temp++;
	       	            if (temp > 99) temp = 1;
	       	            updateLedBuffer_set();
	       	        }

	       	        if (isButton1Pressed() == 1) {
	       	            status = S0;
	       	        }

	       	        if (isButton3Pressed() == 1){
	       	            counter_green = temp;
	       	            change_counter(Change_red);
	       	        }
	        break;

	    case SET_YELLOW:
	        // Đèn vàng nhấp nháy 2Hz
	        if (timer2_flag == 1) {
	            setTimer2(50);
	            LED_YELLOW_Toggle();
	            YELLOW_Toggle();
	        }
	        LED_RED_OFF();
	        LED_GREEN_OFF();
	        RED_OFF();
	        GREEN_OFF();
	        updateLedBuffer_set();
	        if (isButton2Pressed() == 1) {
	       	            temp++;
	       	            if (temp > 99) temp = 1;
	       	            updateLedBuffer_set();
	       	        }

	       	        if (isButton1Pressed() == 1) {
	       	            status = SET_GREEN;
	       	            temp = 1;
	       	        }

	       	        if (isButton3Pressed() == 1){
	       	            counter_yellow = temp;
	       	            change_counter(Change_red);
	       	        }
	        break;

	    default:
	    	fsm_man();
	        break;
	    }
}
