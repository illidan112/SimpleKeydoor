/*
 *  Created on: 01 04 2023
 *      Author: illidan
 */

#ifndef _TCP_H_
#define _TCP_H_

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

extern TaskHandle_t xTCPServerHandle;

/* Function responsible for configuring and starting the tcp_server service.
 * See tcp_server.c for implementation */
esp_err_t tcpServer_create();

#endif