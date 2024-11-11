#include "sensor_dht11.h"

// Lee la temperatura del sensor DHT11
float leerTemperatura(DHT &dht) {
  float t = dht.readTemperature();
  if (isnan(t)) {  // Verifica si la lectura es válida
    Serial.println("Error al leer la temperatura");
    return 0.0;  // Retorna 0 en caso de error
  }
  return t;  // Retorna la temperatura
}

// Lee la humedad del sensor DHT11
float leerHumedad(DHT &dht) {
  float h = dht.readHumidity();
  if (isnan(h)) {  // Verifica si la lectura es válida
    Serial.println("Error al leer la humedad");
    return 0.0;  // Retorna 0 en caso de error
  }
  return h;  // Retorna la humedad
}
