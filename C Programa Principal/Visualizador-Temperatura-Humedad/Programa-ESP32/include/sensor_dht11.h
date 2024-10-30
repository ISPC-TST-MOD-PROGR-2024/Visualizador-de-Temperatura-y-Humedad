#ifndef SENSOR_DHT11_H
#define SENSOR_DHT11_H

#include <DHT.h>

float leerTemperatura(DHT &dht);
float leerHumedad(DHT &dht);

#endif
