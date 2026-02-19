// Globales.h
#ifndef GLOBALES_H
#define GLOBALES_H

#include <Arduino.h>

struct SistemaEstado {
    int valor;
    bool estado;
};


extern SistemaEstado estados;
extern SemaphoreHandle_t xMutex;

#endif