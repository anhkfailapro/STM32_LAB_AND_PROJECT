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
	switch (led) {
	case Change_red:
		sum = counter_green + counter_yellow;
		delta = counter_red - sum;
		    counter_green += delta;
		if (counter_green > 99) {
			int excess = counter_green - 99;
		    counter_green = 99;
		    counter_yellow += excess;
		    if (counter_yellow > 99) counter_yellow = 99;
		}
		    break;

	    case Change_green:
	    counter_red = counter_green + counter_yellow;
	    if (counter_red > 99) {
	        int overflow = counter_red - 99;
	        counter_red = 99;
	        counter_yellow -= overflow;
	        if (counter_yellow < 0) counter_yellow = 0;
	    }
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
	        if (timer_flag[2] == 1) {
	            setTimer(2, 50); // 50 * 10ms = 500ms
	            LED_RED_Toggle();
	        }
	        LED_YELLOW_OFF();
	        LED_GREEN_OFF();

	        // Bật chỉ báo trạng thái setup
	        RED_OFF();
	        YELLOW_OFF();
	        GREEN_ON();

	        // Hiển thị giá trị temp lên 7 đoạn
	        display7SEG(temp);

	        // Nhấn button2 để tăng temp
	        if (isButtonPressed(2) == 1) {
	            temp++;
	            if (temp > 99) temp = 0;
	        }

	        // Nhấn button1 để lưu và chuyển trạng thái
	        if (isButtonPressed(1) == 1) {
	            counter_red = temp;
	            change_counter(Change_red);
	            status = SET_GREEN;
	        }
	        break;

	    case SET_GREEN:
	        // Đèn xanh nhấp nháy 2Hz
	        if (timer_flag[2] == 1) {
	            setTimer(2, 50);
	            LED_GREEN_Toggle();
	        }
	        LED_RED_OFF();
	        LED_YELLOW_OFF();

	        RED_ON();
	        YELLOW_OFF();
	        GREEN_OFF();

	        display7SEG(temp);

	        if (isButtonPressed(2) == 1) {
	            temp++;
	            if (temp > 99) temp = 0;
	        }

	        if (isButtonPressed(1) == 1) {
	            counter_green = temp;
	            change_counter(Change_green);
	            status = SET_YELLOW;
	        }
	        break;

	    case SET_YELLOW:
	        // Đèn vàng nhấp nháy 2Hz
	        if (timer_flag[2] == 1) {
	            setTimer(2, 50);
	            LED_YELLOW_Toggle();
	        }
	        LED_RED_OFF();
	        LED_GREEN_OFF();

	        RED_ON();
	        YELLOW_OFF();
	        GREEN_OFF();

	        display7SEG(temp);

	        if (isButtonPressed(2) == 1) {
	            temp++;
	            if (temp > 99) temp = 0;
	        }

	        if (isButtonPressed(1) == 1) {
	            counter_yellow = temp;
	            change_counter(Change_yellow);
	            status = INIT;
	        }
	        break;

	    default:
	        break;
	    }
}
