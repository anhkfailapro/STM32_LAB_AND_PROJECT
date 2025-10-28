/*
 * fsm_led.c
 *
 *  Created on: Oct 29, 2025
 *      Author: Admin
 */
#include "fsm_led.h"

void update7SEG(int index) {
    HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
    HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);

    switch(index) {
        case 0:
            HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
            display7SEG(led_buffer[0]);
            display7SEG2(led_buffer[1]);
            break;
        case 1:
            HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
            display7SEG(led_buffer[2]);
            display7SEG2(led_buffer[3]);
            break;
        default:
            break;
    }
}

void updateLedBuffer_auto(){ 	//chac khong can dung dau
	return;
}

void updateLedBuffer_set(){
	led_buffer[0] = temp % 10;
	led_buffer[1] = temp / 10;
	led_buffer[2] = status % 10;
	led_buffer[3] = 0;
}
