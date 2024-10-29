#include <Arduino.h>  // Incluye la librería principal de Arduino
#include "sensor_dht11.h"  // Incluye la librería personalizada para manejar el sensor DHT11
#include "ws2812.h"  // Incluye la librería personalizada para manejar el LED WS2812

// Definición de pines y tipo de sensor DHT11
#define DHTPIN 4  // Pin donde está conectado el sensor DHT11
#define DHTTYPE DHT11  // Define el tipo de sensor DHT como DHT11
DHT dht(DHTPIN, DHTTYPE);  // Crea un objeto del tipo DHT para manejar el sensor

// Crea un objeto para manejar el LED WS2812 en el pin 13 con 1 LED
WS2812 led(13, 1);  // El primer parámetro es el pin, el segundo es la cantidad de LEDs

// Función que se ejecuta una vez al iniciar el programa
void setup() {
  Serial.begin(115200);  // Inicializa la comunicación serial a 115200 baudios
  dht.begin();  // Inicia el sensor DHT11
  led.begin();  // Inicia el LED WS2812
}

// Función principal que se ejecuta continuamente
void loop() {
  // Leer temperatura y humedad desde el sensor DHT11
  float temperatura = leerTemperatura(dht);  // Usa una función personalizada para leer la temperatura
  float humedad = leerHumedad(dht);  // Usa una función personalizada para leer la humedad
  String color;  // Variable para almacenar el color del LED

  // Lógica para cambiar el color del LED según la temperatura
  if (temperatura > 30.0) {
    color = "rojo";  // Si la temperatura es mayor a 30°C, el color es rojo
    led.cambiarColor(255, 0, 0);  // Cambia el color del LED a rojo (RGB: 255, 0, 0)
  } else if (temperatura > 20.0) {
    color = "amarillo";  // Si la temperatura está entre 20°C y 30°C, el color es amarillo
    led.cambiarColor(255, 255, 0);  // Cambia el color del LED a amarillo (RGB: 255, 255, 0)
  } else {
    color = "verde";  // Si la temperatura es menor o igual a 20°C, el color es verde
    led.cambiarColor(0, 255, 0);  // Cambia el color del LED a verde (RGB: 0, 255, 0)
  }

  // Enviar los datos de temperatura, humedad y color por el puerto serial
  Serial.print(temperatura);  // Envía la temperatura
  Serial.print(",");  // Envía una coma como separador
  Serial.print(humedad);  // Envía la humedad
  Serial.print(",");  // Envía una coma como separador
  Serial.println(color);  // Envía el color del LED y termina la línea

  delay(2000);  // Espera 2 segundos antes de volver a ejecutar el bucle
}
