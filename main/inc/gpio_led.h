/*
 *  Created on: 01 04 2023
 *      Author: illidan
 */
#ifndef _GPIO_H_
#define _GPIO_H_

#include "esp_err.h"

/* Function responsible for configuring and starting the GPIO.
 * See gpio.c for implementation */
esp_err_t gpio_init(void);
void set_port_level(uint8_t);

#endif