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
#include "config.h"


uint32_t show_output_milliseconds[OUTPUTS_CNT] = {
		100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000
};

// to disable output set corresponding value to -1
int8_t show_output[OUTPUTS_CNT] = {
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19
};

volatile uint32_t show_time;
SHOW_STATE_t show_state = stopped;

#if FIRMWARE_TEST == 1

uint32_t show_time_end;

static uint32_t show_get_time_end(void){
	uint32_t max = 0;
	for(uint8_t out_idx=0; out_idx < OUTPUTS_CNT; out_idx++){
		if(show_output_milliseconds[out_idx] > max) {
			max = show_output_milliseconds[out_idx];
		}
	}
	max = max + OUTPUT_ON_TIME;
	return max;
}

static uint8_t show_end_check(void){
	return show_time > show_time_end;
}

#endif

void show_init(void){
	TCCR2A |= (1 << WGM21);  // CTC
	TCCR2B |= (1 << CS21);  // prescaler 8
	OCR2A = 125; // 1ms

#if FIRMWARE_TEST == 1
	show_time_end = show_get_time_end();
#endif
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
#if FIRMWARE_TEST == 1
	if(show_end_check()) show_state = stopped;
#endif

	for(uint8_t out_idx=0; out_idx < OUTPUTS_CNT; out_idx++){
		ms = show_output_milliseconds[out_idx];
		out = show_output[out_idx];
		if((out < 0) || (out >= OUTPUTS_CNT)) continue;
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
