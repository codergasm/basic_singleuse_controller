/*
 * main.c
 *
 *  Created on: 28 mar 2024
 *      Author: dawid
 */


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "show.h"
#include "led_status.h"
#include "buttons.h"
#include "outputs.h"

int main(void){

	led_status_init();
	buttons_init();
	outputs_init();
	show_init();

	sei();


	while(1){
		if(show_get_state() == stopped){
			led_status_loop();
			if(button_start_get_state() == pressed){
				show_start();
				led_status_on();
			}
		}
		show_execute();
	}
}
