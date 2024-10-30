#include "sensor_dht11.h"

// Función para leer la temperatura del sensor DHT11
float leerTemperatura(DHT &dht) {
  float t = dht.readTemperature();
  if (isnan(t)) {
    Serial.println("Error al leer la temperatura");
    return 0.0;
  }
  return t;
}

// Función para leer la humedad del sensor DHT11
float leerHumedad(DHT &dht) {
  float h = dht.readHumidity();
  if (isnan(h)) {
    Serial.println("Error al leer la humedad");
    return 0.0;
  }
  return h;
}
