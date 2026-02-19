#include "Import.h"
#include "Globales.h"
SistemaEstado estados = {0, false};
SemaphoreHandle_t xMutex;

void setup() {
  Serial.begin(115200);
  while (!Serial);

  xSerialSemaphore = xSemaphoreCreateMutex();
  xWiFiSemaphore = xSemaphoreCreateMutex();
  xMutex = xSemaphoreCreateMutex();
  InitLed();
  Serial.println("Led inicializado");
  ChangeColorLed(0, 255, 0, 0); 
  
  ConnectedWifi(120, 10);

  ChangeColorLed(0, 255, 125, 0);

  xTaskCreatePinnedToCore(
        Task_Software,     // Función de la tarea
        "Task_Software",  // Nombre
        8192,          // Stack size
        NULL,          // Parámetros
        1,             // Prioridad
        NULL,          // Task handle
        0              // Núcleo (0 o 1)
    );
    
    xTaskCreatePinnedToCore(
        Task_Hardware,     // Función de la tarea
        "Task_Hardware",  // Nombre
        8192,          // Stack size
        NULL,          // Parámetros
        1,             // Prioridad
        NULL,          // Task handle
        1              // Núcleo (0 o 1)
    );
    
  ChangeColorLed(0, 120, 255, 0);
  
  Serial.println("Sistema ESP32-S3 inicializado - Dual Core activado");

}




void loop() {
  // put your main code here, to run repeatedly:

}

