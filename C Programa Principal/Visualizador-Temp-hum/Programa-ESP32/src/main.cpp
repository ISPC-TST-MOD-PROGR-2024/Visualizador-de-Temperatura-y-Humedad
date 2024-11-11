#include <Arduino.h>
#include "sensor_dht11.h"
#include "ws2812.h"

// Configuración del pin para el sensor DHT11 y el tipo de sensor
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);  // Inicializa el sensor DHT11

// Inicializa el LED WS2812 en el pin 13 con 1 LED
WS2812 led(13, 1);

void setup() {
  Serial.begin(115200);  // Inicia la comunicación serie
  dht.begin();  // Inicializa el sensor DHT11
  led.begin();  // Inicializa el LED WS2812
}

void loop() {
  // Lee los valores de temperatura y humedad
  float temperatura = leerTemperatura(dht);
  float humedad = leerHumedad(dht);

  // Verifica si las lecturas son válidas
  if (isnan(temperatura) || isnan(humedad)) {
    Serial.println("Error al leer el sensor DHT11");
    return;  // Sale de la función si hay un error
  }

  String color;

  // Cambia el color del LED según la temperatura
  if (temperatura > 30.0) {
    color = "rojo";
    led.cambiarColor(255, 0, 0);  // LED rojo si la temperatura es mayor a 30°C
  } else if (temperatura > 20.0) {
    color = "amarillo";
    led.cambiarColor(255, 255, 0);  // LED amarillo entre 20°C y 30°C
  } else {
    color = "verde";
    led.cambiarColor(0, 255, 0);  // LED verde si la temperatura es menor a 20°C
  }

  // Envía los datos al puerto serie
  Serial.print(temperatura);
  Serial.print(",");
  Serial.print(humedad);
  Serial.print(",");
  Serial.println(color);

  delay(2000);  // Espera 2 segundos antes de la próxima lectura
}
