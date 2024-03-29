/*
 * buttons.c
 *
 *  Created on: 28 mar 2024
 *      Author: dawid
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#include "buttons.h"

BUTTON_STATE_t button_start_state = released;


static uint8_t button_start_check_state(void){
	return !(PIN(BTN_START_PORT) & (1 << BTN_START_PIN));
}

void buttons_init(void){
	PORT(BTN_START_PORT) |= (1 << BTN_START_PIN);

	TCCR0A |= (1 << WGM01);  // CTC
	TCCR0B |= (1 << CS02);  // prescaler 256
	OCR0A = 38;  // 10ms
	TIMSK0 |= (1 << OCIE0A);
}

BUTTON_STATE_t button_start_get_state(void){
	return button_start_state;
}

ISR(TIMER0_COMPA_vect){
	static uint8_t button_start_hold_cnt = 0;

	if(button_start_check_state()){
		button_start_hold_cnt++;
		if(button_start_hold_cnt >= BTN_MIN_PRESS_CNT){
			button_start_state = pressed;
		}
	}
	else{
		button_start_hold_cnt = 0;
		button_start_state = released;
	}

}
