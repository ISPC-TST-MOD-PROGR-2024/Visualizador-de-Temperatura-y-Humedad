#include <Arduino.h>
#include "sensor_dht11.h"
#include "ws2812.h"
#include <WiFi.h>

#define DHTPIN 15
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
WS2812 led(4, 1);

const char* ssid = "Raul";          // Cambia esto por tu SSID
const char* password = "ni334233";  // Cambia esto por tu contraseña de WiFi
void setup() {
  Serial.begin(115200);
  dht.begin();
  led.begin();
}

void loop() {
  float temperatura = leerTemperatura(dht);
  float humedad = leerHumedad(dht);
  String color;

  if (temperatura > 30.0) {
    color = "rojo";
    led.cambiarColor(255, 0, 0);
  } else if (temperatura > 20.0) {
    color = "amarillo";
    led.cambiarColor(255, 255, 0);
  } else {
    color = "verde";
    led.cambiarColor(0, 255, 0);
  }

  // Enviar datos por el puerto serial
  Serial.print(temperatura);
  Serial.print(",");
  Serial.print(humedad);
  Serial.print(",");
  Serial.println(color);

  delay(2000);
}

