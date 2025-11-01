/*
 * button.h
 *
 *  Created on: Sep 4, 2025
 *      Author: Admin
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

// Button 1
extern int button1_flag;
int isButton1Pressed(void);
void getKeyInput1(void);

// Button 2
extern int button2_flag;
int isButton2Pressed(void);
void getKeyInput2(void);

// Button 3
extern int button3_flag;
int isButton3Pressed(void);
void getKeyInput3(void);

// Button 4
extern int button4_flag;
int isButton4Pressed(void);
void getKeyInput4(void);

void getKeyInput(void);

#endif /* INC_BUTTON_H_ */
