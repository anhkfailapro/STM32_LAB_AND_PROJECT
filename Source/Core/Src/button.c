/*
 * button.c
 *
 *  Created on: Sep 4, 2025
 *      Author: Admin
 */

#include "button.h"

// ---------------- BUTTON 1 ----------------
int button1_flag = 0;
int KeyReg0_1 = NORMAL_STATE;
int KeyReg1_1 = NORMAL_STATE;
int KeyReg2_1 = NORMAL_STATE;
int KeyReg3_1 = NORMAL_STATE;
int timeForKeyPress1 = 200;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess1(){
	button1_flag = 1;
	// TODO: Xử lý sự kiện Button1 nhấn
}

void getKeyInput1(){
	KeyReg0_1 = KeyReg1_1;
	KeyReg1_1 = KeyReg2_1;
	KeyReg2_1 = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);

	if((KeyReg0_1 == KeyReg1_1) && (KeyReg1_1 == KeyReg2_1)){
		if(KeyReg3_1 != KeyReg2_1){
			KeyReg3_1 = KeyReg2_1;
			if(KeyReg2_1 == PRESSED_STATE){
				timeForKeyPress1 = 200;
				subKeyProcess1();
			}
		} else {
			timeForKeyPress1--;
			if(timeForKeyPress1 == 0){
				if(KeyReg2_1 == PRESSED_STATE){
					subKeyProcess1();
				}
				timeForKeyPress1 = 200;
			}
		}
	}
}

// ---------------- BUTTON 2 ----------------
int button2_flag = 0;
int KeyReg0_2 = NORMAL_STATE;
int KeyReg1_2 = NORMAL_STATE;
int KeyReg2_2 = NORMAL_STATE;
int KeyReg3_2 = NORMAL_STATE;
int timeForKeyPress2 = 200;

int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess2(){
	button2_flag = 1;
	// TODO: Xử lý sự kiện Button2 nhấn
}

void getKeyInput2(){
	KeyReg0_2 = KeyReg1_2;
	KeyReg1_2 = KeyReg2_2;
	KeyReg2_2 = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);

	if((KeyReg0_2 == KeyReg1_2) && (KeyReg1_2 == KeyReg2_2)){
		if(KeyReg3_2 != KeyReg2_2){
			KeyReg3_2 = KeyReg2_2;
			if(KeyReg2_2 == PRESSED_STATE){
				timeForKeyPress2 = 200;
				subKeyProcess2();
			}
		} else {
			timeForKeyPress2--;
			if(timeForKeyPress2 == 0){
				if(KeyReg2_2 == PRESSED_STATE){
					subKeyProcess2();
				}
				timeForKeyPress2 = 200;
			}
		}
	}
}

// ---------------- BUTTON 3 ----------------
int button3_flag = 0;
int KeyReg0_3 = NORMAL_STATE;
int KeyReg1_3 = NORMAL_STATE;
int KeyReg2_3 = NORMAL_STATE;
int KeyReg3_3 = NORMAL_STATE;
int timeForKeyPress3 = 200;

int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess3(){
	button3_flag = 1;
	// TODO: Xử lý sự kiện Button3 nhấn
}

void getKeyInput3(){
	KeyReg0_3 = KeyReg1_3;
	KeyReg1_3 = KeyReg2_3;
	KeyReg2_3 = HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);

	if((KeyReg0_3 == KeyReg1_3) && (KeyReg1_3 == KeyReg2_3)){
		if(KeyReg3_3 != KeyReg2_3){
			KeyReg3_3 = KeyReg2_3;
			if(KeyReg2_3 == PRESSED_STATE){
				timeForKeyPress3 = 200;
				subKeyProcess3();
			}
		} else {
			timeForKeyPress3--;
			if(timeForKeyPress3 == 0){
				if(KeyReg2_3 == PRESSED_STATE){
					subKeyProcess3();
				}
				timeForKeyPress3 = 200;
			}
		}
	}
}

// ---------------- BUTTON 4 ----------------
int button4_flag = 0;
int KeyReg0_4 = NORMAL_STATE;
int KeyReg1_4 = NORMAL_STATE;
int KeyReg2_4 = NORMAL_STATE;
int KeyReg3_4 = NORMAL_STATE;
int timeForKeyPress4 = 200;

int isButton4Pressed(){
	if(button4_flag == 1){
		button4_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess4(){
	button4_flag = 1;
	// TODO: Xử lý sự kiện Button4 nhấn (ví dụ: chuyển mode, reset, ...)
}

void getKeyInput4(){
	KeyReg0_4 = KeyReg1_4;
	KeyReg1_4 = KeyReg2_4;
	KeyReg2_4 = HAL_GPIO_ReadPin(Button4_GPIO_Port, Button4_Pin);

	if((KeyReg0_4 == KeyReg1_4) && (KeyReg1_4 == KeyReg2_4)){
		if(KeyReg3_4 != KeyReg2_4){
			KeyReg3_4 = KeyReg2_4;
			if(KeyReg2_4 == PRESSED_STATE){
				timeForKeyPress4 = 200;
				subKeyProcess4();
			}
		} else {
			if (timeForKeyPress4 > 0) timeForKeyPress4--;
			if(timeForKeyPress4 == 0){
				if(KeyReg2_4 == PRESSED_STATE){
					subKeyProcess4();
				}
				timeForKeyPress4 = 200;
			}
		}
	}
}


void getKeyInput(){
	getKeyInput1();
	getKeyInput2();
	getKeyInput3();
	getKeyInput4();
}
