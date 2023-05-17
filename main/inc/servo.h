/*
 *  Created on: 30 04 2023
 *      Author: illidan
 */
#ifndef _SERVO_H_
#define _SERVO_H_

#include "driver/mcpwm_prelude.h"

#define FIRST_DOOR 1
#define SECOND_DOOR 2

esp_err_t servo_init(void);
void opener(bool on_off, uint8_t door_num);

void init_servo(uint8_t grp_id, uint8_t gpio_servo, mcpwm_cmpr_handle_t *comparator);

#endif