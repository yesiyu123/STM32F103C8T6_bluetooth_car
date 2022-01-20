#include "stm32f10x.h"                  // Device header

void Motor_Init(void) {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2 | GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2);
}

void Go() {
	GPIO_SetBits(GPIOA, GPIO_Pin_2);
	GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
	GPIO_ResetBits(GPIOA, GPIO_Pin_3);
}

void Back() {
	GPIO_SetBits(GPIOA, GPIO_Pin_1);
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	GPIO_SetBits(GPIOA, GPIO_Pin_3);
	GPIO_ResetBits(GPIOA, GPIO_Pin_4);
}

void Left() {
	GPIO_SetBits(GPIOA, GPIO_Pin_1);
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
	GPIO_ResetBits(GPIOA, GPIO_Pin_3);
}

void Right() {
	GPIO_SetBits(GPIOA, GPIO_Pin_2);
	GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	GPIO_SetBits(GPIOA, GPIO_Pin_3);
	GPIO_ResetBits(GPIOA, GPIO_Pin_4);
}

void Stop() {
	GPIO_SetBits(GPIOA, GPIO_Pin_1);
	GPIO_SetBits(GPIOA, GPIO_Pin_2);
	GPIO_SetBits(GPIOA, GPIO_Pin_3);
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
}
