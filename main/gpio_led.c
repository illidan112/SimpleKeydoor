/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"

#include "gpio_led.h"

static const char *TAG = "GPIO";

#define BLINK_GPIO 5

static uint8_t s_led_state = 0;


void set_port_level(uint8_t state)
{
    /* Set the GPIO level according to the state (LOW or HIGH)*/
    gpio_set_level(BLINK_GPIO, state);
}

static void configure_led(void)
{
    ESP_LOGI(TAG, "Configured to blink GPIO LED!");
    gpio_reset_pin(BLINK_GPIO);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
}

esp_err_t gpio_init(void)
{

    /* Configure the peripheral according to the LED type */
    configure_led();
    return ESP_OK;

}
