#include "Globales.h"

void Task_Hardware(void *parameter) { 
  while (1) {
    int lecturaReferencia = random(20, 40); 

    if (xSemaphoreTake(xMutex, portMAX_DELAY)) {
      estados.valor = lecturaReferencia; 
      
      if (estados.estado) {
        Serial.println(">>> [SENSOR TASK] Estado Y es ON: Activando Actuador!");
      } else {
        Serial.println(">>> [SENSOR TASK] Estado Y es OFF: Desactivando Actuador.");
      }
      
      xSemaphoreGive(xMutex);
    }

    vTaskDelay(pdMS_TO_TICKS(2000)); 
  }
}