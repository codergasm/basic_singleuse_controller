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

uint32_t show_output_milliseconds[OUTPUTS_CNT] = {
		3500, 7000, 10500, 14000, 17500, 21000, 24500, 28000, 31500, 35000, 38500, 42000, 45500, 49000, 52500, 56000, 59500, 63000, 66500, 70000
};

// to disable output set corresponding value to -1
int8_t show_output[OUTPUTS_CNT] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

volatile uint32_t show_time;
SHOW_STATE_t show_state = stopped;

void show_init(void){
	TCCR2A |= (1 << WGM21);  // CTC
	TCCR2B |= (1 << CS21);  // prescaler 8
	OCR2A = 125; // 1ms
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
	uint8_t out;
	if(show_state != running) return;

	for(uint8_t out_idx=0; out_idx < OUTPUTS_CNT; out_idx++){
		ms = show_output_milliseconds[out_idx];
		out = show_output[out_idx];
		if(out < 0) continue;
		if(show_time >= ms && (show_time <= (ms + OUTPUT_ON_TIME))){
			output_set(out);
		}
		else{
			output_clr(out);
		}
	}
}

ISR(TIMER2_COMPA_vect){
	show_time++;
}
