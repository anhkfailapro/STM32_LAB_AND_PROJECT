/*
 * button.h
 *
 *  Created on: Sep 4, 2025
 *      Author: Admin
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NUM_OF_BUTTONS 3

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int button_flag[NUM_OF_BUTTONS];

int isButtonPressed(int index);
void getKeyInput(void);
void subKeyProcess(int index);

#endif /* INC_BUTTON_H_ */
