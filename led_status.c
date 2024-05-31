/*
 * led_status.c
 *
 *  Created on: 28 mar 2024
 *      Author: dawid
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#include "led_status.h"

uint8_t led_state = 0;

void led_status_init(void){
	DDR(LED_PORT) |= (1 << LED_PIN);
	led_status_off();

	TCCR1B |= (1 << WGM12) | (1 << CS11) | (1 << CS10);
	TIMSK1 |= (1 << OCIE1A);
	OCR1A = 5208;
}

void led_status_on(void){
	PORT(LED_PORT) &= ~(1 << LED_PIN);
}

void led_status_off(void){
	PORT(LED_PORT) |= (1 << LED_PIN);
}

void led_status_toggle(void){
	PORT(LED_PORT) ^= (1 << LED_PIN);
}

void led_status_loop(void){
	if(led_state) led_status_on();
	else led_status_off();
}


ISR(TIMER1_COMPA_vect){
	led_state = !led_state;
}
