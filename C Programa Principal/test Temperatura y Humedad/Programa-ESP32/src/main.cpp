#include <Arduino.h>
#include "sensor_dht11.h"
#include "ws2812.h"

#define DHTPIN 4        // Pin donde está conectado el DHT11
#define DHTTYPE DHT11   // Definir el tipo de sensor DHT

DHT dht(DHTPIN, DHTTYPE); // Crear una instancia del sensor DHT
WS2812 led(13, 1);        // Crear una instancia del LED WS2812 en el pin 13

void setup() {
  Serial.begin(115200);  // Iniciar comunicación serial
  dht.begin();           // Iniciar sensor DHT11
  led.begin();           // Iniciar el LED WS2812
  Serial.println("Sistema inicializado.");
}

void loop() {
  // Leer los datos de temperatura y humedad
  float temperatura = leerTemperatura(dht);
  float humedad = leerHumedad(dht);

  // Mostrar los datos por serial
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" ºC");

  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.println(" %");

  // Controlar el LED según los niveles de temperatura
  if (temperatura > 30.0) {
    led.cambiarColor(255, 0, 0);  // Rojo si la temperatura es alta
  } else if (temperatura > 20.0) {
    led.cambiarColor(255, 255, 0);  // Amarillo si la temperatura es moderada
  } else {
    led.cambiarColor(0, 255, 0);  // Verde si la temperatura es baja
  }

  delay(2000);  // Esperar 2 segundos antes de la siguiente lectura
}
