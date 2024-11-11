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
