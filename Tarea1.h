#include "Globales.h"

void Task_Software(void *parameter) { 
  while (1) {
    if (xSemaphoreTake(xMutex, portMAX_DELAY)) {
      Serial.printf("    [WIFI TASK] Enviando a la nube... Sensor X: %d\n", estados.valor);
      
      estados.estado = !estados.estado; 
      Serial.printf("    [WIFI TASK] Recibido de la nube... Nuevo Estado Y: %s\n", estados.estado ? "ON" : "OFF");

      xSemaphoreGive(xMutex);
    }

    vTaskDelay(pdMS_TO_TICKS(5000)); 
  }
}