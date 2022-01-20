#include "stm32f10x.h"                  // Device header
#include "led.h"
#include "delay.h"
#include "usart.h"
#include "motor.h"

int main() {
	LED_Init();
	Delay_Init();
	Motor_Init();
	USART_init(9600);
	
	while(1) {
//		Go();
		uint8_t RX_Data;
		
		while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);
		RX_Data = USART_ReceiveData(USART1);
		if(RX_Data == '1') {
			Go();
			printf("Go");
		} else if(RX_Data == '2') {
			Back();
			printf("Back");
		} else if(RX_Data == '3') {
			Left();
			printf("Left");
		} else if(RX_Data == '4') {
			Right();
			printf("Right");
		} else {
			Stop();
			printf("Stop");
		}
	}
}
