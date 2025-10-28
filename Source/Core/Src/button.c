/*
 * button.c
 *
 *  Created on: Sep 4, 2025
 *      Author: Admin
 */

#include "button.h"

int button_flag[NUM_OF_BUTTONS] = {0};

int KeyReg0[NUM_OF_BUTTONS] = {NORMAL_STATE};
int KeyReg1[NUM_OF_BUTTONS] = {NORMAL_STATE};
int KeyReg2[NUM_OF_BUTTONS] = {NORMAL_STATE};
int KeyReg3[NUM_OF_BUTTONS] = {NORMAL_STATE};

int timeForKeyPress[NUM_OF_BUTTONS] = {200, 200, 200};

//================= HÀM KIỂM TRA NÚT =================
int isButtonPressed(int index){
	if(button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

//================= XỬ LÝ KHI NHẤN NÚT =================
void subKeyProcess(int index){
	button_flag[index] = 1;
	// TODO:
}

//================= HÀM ĐỌC TRẠNG THÁI NÚT =================
void getKeyInput(){
	// Nút 1
	KeyReg0[0] = KeyReg1[0];
	KeyReg1[0] = KeyReg2[0];
	KeyReg2[0] = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
	if ((KeyReg0[0] == KeyReg1[0]) && (KeyReg1[0] == KeyReg2[0])){
		if (KeyReg3[0] != KeyReg2[0]){
			KeyReg3[0] = KeyReg2[0];
			if (KeyReg2[0] == PRESSED_STATE){
				timeForKeyPress[0] = 200;
				subKeyProcess(0);
			}
		} else {
			timeForKeyPress[0]--;
			if (timeForKeyPress[0] == 0){
				if (KeyReg2[0] == PRESSED_STATE){
					subKeyProcess(0);
				}
				timeForKeyPress[0] = 200;
			}
		}
	}

	// Nút 2
	KeyReg0[1] = KeyReg1[1];
	KeyReg1[1] = KeyReg2[1];
	KeyReg2[1] = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
	if ((KeyReg0[1] == KeyReg1[1]) && (KeyReg1[1] == KeyReg2[1])){
		if (KeyReg3[1] != KeyReg2[1]){
			KeyReg3[1] = KeyReg2[1];
			if (KeyReg2[1] == PRESSED_STATE){
				timeForKeyPress[1] = 200;
				subKeyProcess(1);
			}
		} else {
			timeForKeyPress[1]--;
			if (timeForKeyPress[1] == 0){
				if (KeyReg2[1] == PRESSED_STATE){
					subKeyProcess(1);
				}
				timeForKeyPress[1] = 200;
			}
		}
	}

	// Nút 3
	KeyReg0[2] = KeyReg1[2];
	KeyReg1[2] = KeyReg2[2];
	KeyReg2[2] = HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);
	if ((KeyReg0[2] == KeyReg1[2]) && (KeyReg1[2] == KeyReg2[2])){
		if (KeyReg3[2] != KeyReg2[2]){
			KeyReg3[2] = KeyReg2[2];
			if (KeyReg2[2] == PRESSED_STATE){
				timeForKeyPress[2] = 200;
				subKeyProcess(2);
			}
		} else {
			timeForKeyPress[2]--;
			if (timeForKeyPress[2] == 0){
				if (KeyReg2[2] == PRESSED_STATE){
					subKeyProcess(2);
				}
				timeForKeyPress[2] = 200;
			}
		}
	}
}
