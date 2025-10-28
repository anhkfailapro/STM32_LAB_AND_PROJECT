/*
 * software_timer.h
 *
 *  Created on: Sep 4, 2025
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define NUM_OF_TIMERS 4

extern int timer_counter[NUM_OF_TIMERS];
extern int timer_flag[NUM_OF_TIMERS];

void setTimer(int index, int duration);
void timerRun(void);

#endif /* INC_SOFTWARE_TIMER_H_ */
