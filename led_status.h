/*
 * led_status.h
 *
 *  Created on: 28 mar 2024
 *      Author: dawid
 */

#ifndef LED_STATUS_H_
#define LED_STATUS_H_

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


#define LED_PORT B
#define LED_PIN 6

void led_status_init(void);
void led_status_on(void);
void led_status_off(void);
void led_status_toggle(void);

#endif /* LED_STATUS_H_ */
