/*
 * ports.c
 *
 *  Created on: 28 mar 2024
 *      Author: dawid
 */

#include "outputs.h"

OUTPUT_t outputs[OUTPUTS_CNT];

void outputs_init(void){
	outputs[0].ddr = &DDR(OUT_01_PORT);
	outputs[0].port = &PORT(OUT_01_PORT);
	outputs[0].pin = OUT_01_PIN;

	outputs[1].ddr = &DDR(OUT_02_PORT);
	outputs[1].port = &PORT(OUT_02_PORT);
	outputs[1].pin = OUT_02_PIN;

	outputs[2].ddr = &DDR(OUT_03_PORT);
	outputs[2].port = &PORT(OUT_03_PORT);
	outputs[2].pin = OUT_03_PIN;

	outputs[3].ddr = &DDR(OUT_04_PORT);
	outputs[3].port = &PORT(OUT_04_PORT);
	outputs[3].pin = OUT_04_PIN;

	outputs[4].ddr = &DDR(OUT_05_PORT);
	outputs[4].port = &PORT(OUT_05_PORT);
	outputs[4].pin = OUT_05_PIN;

	outputs[5].ddr = &DDR(OUT_06_PORT);
	outputs[5].port = &PORT(OUT_06_PORT);
	outputs[5].pin = OUT_06_PIN;

	outputs[6].ddr = &DDR(OUT_07_PORT);
	outputs[6].port = &PORT(OUT_07_PORT);
	outputs[6].pin = OUT_07_PIN;

	outputs[7].ddr = &DDR(OUT_08_PORT);
	outputs[7].port = &PORT(OUT_08_PORT);
	outputs[7].pin = OUT_08_PIN;

	outputs[8].ddr = &DDR(OUT_09_PORT);
	outputs[8].port = &PORT(OUT_09_PORT);
	outputs[8].pin = OUT_09_PIN;

	outputs[9].ddr = &DDR(OUT_10_PORT);
	outputs[9].port = &PORT(OUT_10_PORT);
	outputs[9].pin = OUT_10_PIN;

	outputs[10].ddr = &DDR(OUT_11_PORT);
	outputs[10].port = &PORT(OUT_11_PORT);
	outputs[10].pin = OUT_11_PIN;

	outputs[11].ddr = &DDR(OUT_12_PORT);
	outputs[11].port = &PORT(OUT_12_PORT);
	outputs[11].pin = OUT_12_PIN;

	outputs[12].ddr = &DDR(OUT_13_PORT);
	outputs[12].port = &PORT(OUT_13_PORT);
	outputs[12].pin = OUT_13_PIN;

	outputs[13].ddr = &DDR(OUT_14_PORT);
	outputs[13].port = &PORT(OUT_14_PORT);
	outputs[13].pin = OUT_14_PIN;

	outputs[14].ddr = &DDR(OUT_15_PORT);
	outputs[14].port = &PORT(OUT_15_PORT);
	outputs[14].pin = OUT_15_PIN;

	outputs[15].ddr = &DDR(OUT_16_PORT);
	outputs[15].port = &PORT(OUT_16_PORT);
	outputs[15].pin = OUT_16_PIN;

	outputs[16].ddr = &DDR(OUT_17_PORT);
	outputs[16].port = &PORT(OUT_17_PORT);
	outputs[16].pin = OUT_17_PIN;

	outputs[17].ddr = &DDR(OUT_18_PORT);
	outputs[17].port = &PORT(OUT_18_PORT);
	outputs[17].pin = OUT_18_PIN;

	outputs[18].ddr = &DDR(OUT_19_PORT);
	outputs[18].port = &PORT(OUT_19_PORT);
	outputs[18].pin = OUT_19_PIN;

	outputs[19].ddr = &DDR(OUT_20_PORT);
	outputs[19].port = &PORT(OUT_20_PORT);
	outputs[19].pin = OUT_20_PIN;

	for(uint8_t out_idx=0; out_idx < OUTPUTS_CNT; out_idx++){
		*outputs[out_idx].ddr |= (1 << outputs[out_idx].pin);
	}

}

void output_set_state(uint8_t out_idx, uint8_t state){
	if(state) output_set(out_idx);
	else output_clr(out_idx);
}

void output_set(uint8_t out_idx){
	*outputs[out_idx].port |= (1 << outputs[out_idx].pin);
}

void output_clr(uint8_t out_idx){
	*outputs[out_idx].port &= ~(1 << outputs[out_idx].pin);
}
