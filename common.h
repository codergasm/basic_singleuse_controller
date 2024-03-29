/*
 * common.h
 *
 *  Created on: 29 mar 2024
 *      Author: dawid
 */

#ifndef COMMON_H_
#define COMMON_H_

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


#endif /* COMMON_H_ */
