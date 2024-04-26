/*
 * show.h
 *
 *  Created on: 28 mar 2024
 *      Author: dawid
 */

#ifndef SHOW_H_
#define SHOW_H_

#define OUTPUT_ON_TIME 300  // ms

typedef enum SHOW_STATE {stopped, running} SHOW_STATE_t;

void show_init(void);
void show_start(void);
SHOW_STATE_t show_get_state(void);
void show_execute(void);

#endif /* SHOW_H_ */
