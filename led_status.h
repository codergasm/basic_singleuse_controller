/*
 * led_status.h
 *
 *  Created on: 28 mar 2024
 *      Author: dawid
 */

#ifndef LED_STATUS_H_
#define LED_STATUS_H_

#include "common.h"

#define LED_PORT B
#define LED_PIN 6

void led_status_init(void);
void led_status_on(void);
void led_status_off(void);
void led_status_toggle(void);
void led_status_loop(void);

#endif /* LED_STATUS_H_ */
