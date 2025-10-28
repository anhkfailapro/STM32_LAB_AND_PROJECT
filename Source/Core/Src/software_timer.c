/*
 * software_timer.c
 *
 *  Created on: Sep 4, 2025
 *      Author: Admin
 */


#include "software_timer.h"

int timer_counter[NUM_OF_TIMERS] = {0};
int timer_flag[NUM_OF_TIMERS] = {0};

void setTimer(int index, int duration){
	if(index >= 0 && index < NUM_OF_TIMERS){
		timer_counter[index] = duration;
		timer_flag[index] = 0;
	}
}

void timerRun(void){
	for(int i = 0; i < NUM_OF_TIMERS; i++){
		if(timer_counter[i] > 0){
			timer_counter[i]--;
			if(timer_counter[i] <= 0){
				timer_flag[i] = 1;
			}
		}
	}
}


