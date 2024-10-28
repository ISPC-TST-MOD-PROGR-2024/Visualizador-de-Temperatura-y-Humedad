#include <Arduino.h>
#include "sensor.h"

// Configuración de pines y otros parámetros
const int DHT_PIN = 15;       // Pin del sensor DHT11
const int DHT_TYPE = DHT11;  // Tipo de sensor
const int LED_PIN = 4;       // Pin del LED WS2812
const int NUM_PIXELS = 1;    // Número de LEDs

// Credenciales de la red WiFi y de la base de datos MySQL
const char* ssid = "Raul";          // Cambia esto por tu SSID
const char* password = "ni334233";  // Cambia esto por tu contraseña de WiFi
const char* db_user = "root";    // Cambia esto por tu usuario de MySQL
const char* db_password = "root"; // Cambia esto por tu contraseña de MySQL
const char* db_host = "localhost";       // Cambia esto por tu host de MySQL
const int db_port = 3306;               // Cambia esto por el puerto de MySQL si es necesario

// Crear objeto de la clase Sensor_DHT11
Sensor_DHT11 sensor(DHT_PIN, DHT_TYPE, LED_PIN, NUM_PIXELS);

void setup() {
    Serial.begin(115200);
    sensor.conectarWiFi(ssid, password);      // Conectar a WiFi
    sensor.conectarMySQL(db_user, db_password, db_host, db_port); // Conectar a MySQL
    sensor.begin();                            // Inicializar el sensor y el LED
}

void loop() {
    sensor.leerDatos();                       // Leer y enviar datos
    sensor.actualizarLED();                   // Actualizar el estado del LED
    delay(2000);                              // Esperar 2 segundos antes de la siguiente lectura
}