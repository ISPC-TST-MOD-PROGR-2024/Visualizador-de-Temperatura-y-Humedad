#ifndef SENSOR_DHT11_H
#define SENSOR_DHT11_H

#include <DHT.h>

// Declaración de la función para leer la temperatura del sensor
float leerTemperatura(DHT &dht);


// Declaración de la función para leer la humedad del sensor
float leerHumedad(DHT &dht);

#endif
