#include <stdio.h>
#include "nvs_flash.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"

#include "wifi_sta.h"
#include "tcp_server.h"
#include "gpio_led.h"
#include "servo.h"

static const char *TAG = "Main";

void app_main(void)
{
  //Initialize NVS
  esp_err_t ret = nvs_flash_init();
  if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
    ESP_ERROR_CHECK(nvs_flash_erase());
    ret = nvs_flash_init();
  }
  ESP_ERROR_CHECK(ret);

  if (wifi_init_sta() != ESP_OK) {             //Connecting to wifi station
    ESP_LOGE(TAG, "WI-FI conneting failed");
    //  esp_restart();
  }else 
  if(tcpServer_create() != ESP_OK){         //Start TCP server for the first time
    ESP_LOGE(TAG, "TCP crearing failed");
    // esp_restart();
  }else
  if(gpio_init() != ESP_OK){
    ESP_LOGE(TAG, "GPIO crearing failed");
    // esp_restart();
  }else
  if(servo_init() != ESP_OK){         //Start TCP server for the first time
    ESP_LOGE(TAG, "SERVO crearing failed");
    // esp_restart();
  }else{
    ESP_LOGI(TAG, "Initialization was successful");
  }
  
    
}
