/*
 * show.c
 *
 *  Created on: 28 mar 2024
 *      Author: dawid
 */

#include <avr/io.h>
#include <string.h>
#include <avr/interrupt.h>

#include "show.h"
#include "led_status.h"
#include "outputs.h"

uint32_t show_output_miliseconds[OUTPUTS_CNT] = {
		100, 200, 300, 400, 500, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
		1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000
};

// to disable output set corresponding value to -1
int8_t show_output[OUTPUTS_CNT] = {
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19
};

volatile uint32_t show_time;
SHOW_STATE_t show_state = stopped;

void show_init(void){
	TCCR2A |= (1 << WGM21);  // CTC
	TCCR2B |= (1 << CS21);  // prescaler 8
	OCR2A = 124; // 1ms
}

void show_start(void){
	show_time = 0;
	TCNT2 = 0;
	TIMSK2 |= (1 << OCIE2A);
	show_state = running;
}

SHOW_STATE_t show_get_state(void){
	return show_state;
}

void show_execute(void){
	uint32_t ms;
	if(show_state == running){
		for(uint8_t out_idx=0; out_idx < OUTPUTS_CNT; out_idx++){
			ms = show_output_miliseconds[out_idx];
			if(show_time >= ms && (show_time <= (ms + OUTPUT_ON_TIME))){
				output_set(out_idx);
			}
			else{
				output_clr(out_idx);
			}
		}
	}
}

ISR(TIMER2_COMPA_vect){
	show_time++;
}
