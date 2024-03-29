/*
 * ports.h
 *
 *  Created on: 28 mar 2024
 *      Author: dawid
 */

#ifndef OUTPUTS_H_
#define OUTPUTS_H_

// Makra upraszczające dostęp do portów
// *** PORT
#define PORT(x) SPORT(x)
#define SPORT(x) (PORT##x)
// *** PIN
#define PIN(x) SPIN(x)
#define SPIN(x) (PIN##x)
// *** DDR
#define DDR(x) SDDR(x)
#define SDDR(x) (DDR##x)

#define OUTPUTS_CNT 20

#define OUT_01_PORT D
#define OUT_02_PORT D
#define OUT_03_PORT D
#define OUT_04_PORT D
#define OUT_05_PORT D
#define OUT_06_PORT C
#define OUT_07_PORT C
#define OUT_08_PORT C
#define OUT_09_PORT C
#define OUT_10_PORT C
#define OUT_11_PORT C
#define OUT_12_PORT B
#define OUT_13_PORT B
#define OUT_14_PORT B
#define OUT_15_PORT B
#define OUT_16_PORT B
#define OUT_17_PORT B
#define OUT_18_PORT D
#define OUT_19_PORT D
#define OUT_20_PORT D


#define OUT_01_PIN 4
#define OUT_02_PIN 3
#define OUT_03_PIN 2
#define OUT_04_PIN 1
#define OUT_05_PIN 0
#define OUT_06_PIN 5
#define OUT_07_PIN 4
#define OUT_08_PIN 3
#define OUT_09_PIN 2
#define OUT_10_PIN 1
#define OUT_11_PIN 0
#define OUT_12_PIN 5
#define OUT_13_PIN 4
#define OUT_14_PIN 3
#define OUT_15_PIN 2
#define OUT_16_PIN 1
#define OUT_17_PIN 0
#define OUT_18_PIN 7
#define OUT_19_PIN 6
#define OUT_20_PIN 5

#include <avr/io.h>

typedef struct {
	volatile uint8_t *ddr;
	volatile uint8_t *port;
	uint8_t pin;
}OUTPUT_t;

void outputs_init(void);
void output_set_state(uint8_t out_idx, uint8_t state);
void output_set(uint8_t out_idx);
void output_clr(uint8_t out_idx);


#endif /* OUTPUTS_H_ */
