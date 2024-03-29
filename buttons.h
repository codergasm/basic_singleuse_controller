/*
 * buttons.h
 *
 *  Created on: 28 mar 2024
 *      Author: dawid
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

#include "common.h"

#define BTN_START_PORT B
#define BTN_START_PIN 7

#define BTN_MIN_PRESS_CNT 5 // mean 50ms

typedef enum button_state {released, pressed} BUTTON_STATE_t;

void buttons_init(void);
BUTTON_STATE_t button_start_get_state(void);

#endif /* BUTTONS_H_ */
