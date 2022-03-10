#include "stm32f4xx.h"                  // Device header
/*
RICHARD SIBANDA 
LEETON AUSTRALIA 
2022
USING USER PUSH BUTTON ON BOARD TO SWITCH ON ONBOARD GREEN LED 
USER PB ON PC13
USER LED ON PA5

*/

int main (void){

RCC->AHB1ENR |=(1U<<0); // ENABLE CLOCK ON PORT A
RCC ->AHB1ENR |= (1U<<2); // ENABLE CLOCK ON PORT C
GPIOA->MODER |= (1U<<10);  // SELECT MODE AS OUTPUT PA5
 while (1)
 {

if (GPIOC->IDR & (1U<<13))	{ 
GPIOA->ODR |= (1U<<5); // PC13 PULLED HIGH ON DEFAULT LED OFF WHEN  PRESSED 
}
 else if (!(GPIOC->IDR & (1U<<13))) {
 GPIOA->ODR   |= (0U<<21);
 }
 
}
}