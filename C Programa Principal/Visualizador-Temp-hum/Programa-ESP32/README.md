# Sensor DHT11 y LED WS2812 con ESP32
**Este progrma utiliza un ESP32 para leer la temperatura y humedad de un sensor DHT11 y controlar un LED WS2812. Según la temperatura medida, el LED cambiará de color: rojo para temperaturas altas, amarillo para temperaturas moderadas y verde para temperaturas bajas.**

```cpp
1. sensor_dht11.h
Este archivo contiene las declaraciones de las funciones necesarias para leer los valores de temperatura y humedad desde el sensor DHT11.

#ifndef SENSOR_DHT11_H
#define SENSOR_DHT11_H

#include <DHT.h>

// Función para leer la temperatura desde el sensor DHT11
float leerTemperatura(DHT &dht);

// Función para leer la humedad desde el sensor DHT11
float leerHumedad(DHT &dht);

#endif



2. ws2812.h
Este archivo contiene la declaración de la clase WS2812, que maneja el control del LED WS2812. Incluye métodos para inicializar y cambiar el color del LED.

#ifndef WS2812_H
#define WS2812_H

#include <Adafruit_NeoPixel.h>

class WS2812 {
  public:
    WS2812(int pin, int numPixeles); // Constructor
    void begin();                     // Inicializa el LED
    void cambiarColor(uint8_t r, uint8_t g, uint8_t b); // Cambia el color del LED

  private:
    Adafruit_NeoPixel strip;
};

#endif




3. sensor_dht11.cpp
Este archivo implementa las funciones declaradas en sensor_dht11.h para leer los valores de temperatura y humedad desde el sensor DHT11.

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




4. ws2812.cpp
Este archivo implementa la clase WS2812 para controlar el LED WS2812.

#include "ws2812.h"

// Constructor de la clase WS2812
WS2812::WS2812(int pin, int numPixeles) : strip(numPixeles, pin, NEO_GRB + NEO_KHZ800) {}

// Inicializa el LED
void WS2812::begin() {
  strip.begin();
  strip.show();  // Inicializa todos los LEDs apagados
}

// Cambia el color del LED
void WS2812::cambiarColor(uint8_t r, uint8_t g, uint8_t b) {
  strip.setPixelColor(0, strip.Color(r, g, b));  // Cambiar el color del primer pixel
  strip.show();
}



5. main.cpp
Este archivo contiene el código principal que inicializa el sensor DHT11 y el LED WS2812. Lee la temperatura y humedad y cambia el color del LED basado en la temperatura.

#include <Arduino.h>
#include "sensor_dht11.h"
#include "ws2812.h"

// Definición de pines y tipo de sensor DHT11
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Crea un objeto para manejar el LED WS2812 en el pin 13 con 1 LED
WS2812 led(13, 1);

void setup() {
  Serial.begin(115200);
  dht.begin();
  led.begin();
}

void loop() {
  // Leer temperatura y humedad desde el sensor DHT11
  float temperatura = leerTemperatura(dht);
  float humedad = leerHumedad(dht);

  // Verificar si la lectura del sensor es correcta
  if (isnan(temperatura) || isnan(humedad)) {
    Serial.println("Error al leer el sensor DHT11");
    return;  // Si hay un error, sale de la función
  }

  String color;

  // Lógica para cambiar el color del LED según la temperatura
  if (temperatura > 30.0) {
    color = "rojo";
    led.cambiarColor(255, 0, 0);  // Cambia el color del LED a rojo
  } else if (temperatura > 20.0) {
    color = "amarillo";
    led.cambiarColor(255, 255, 0);  // Cambia el color del LED a amarillo
  } else {
    color = "verde";
    led.cambiarColor(0, 255, 0);  // Cambia el color del LED a verde
  }

  // Enviar los datos de temperatura, humedad y color por el puerto serial
  Serial.print(temperatura);
  Serial.print(",");
  Serial.print(humedad);
  Serial.print(",");
  Serial.println(color);

  delay(2000);  // Espera 2 segundos antes de volver a ejecutar el bucle
}

```
## Funcionamiento general


### Inicialización:

- El sensor DHT11 se inicializa para leer los valores de temperatura y humedad.
- El LED WS2812 se inicializa y se apaga por defecto.
- Ciclo de operación (loop):

- Se leen los valores de temperatura y humedad del DHT11.
- Se determina el color del LED WS2812 según la temperatura:
- Rojo: temperatura > 30°C
- Amarillo: temperatura entre 20°C y 30°C
- Verde: temperatura < 20°C
- Los valores de temperatura, humedad y el color actual del LED se imprimen en el puerto serial.
- El ciclo se repite cada 2 segundos.