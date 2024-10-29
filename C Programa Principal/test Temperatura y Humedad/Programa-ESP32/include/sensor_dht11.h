#ifndef SENSOR_DHT11_H
#define SENSOR_DHT11_H
#include <WiFi.h>

#include <DHT.h>

float leerTemperatura(DHT &dht);
float leerHumedad(DHT &dht);

// Método para conectar a WiFi
void Sensor_DHT11::conectarWiFi(const char* ssid, const char* password) {
    WiFi.begin(ssid, password);
    Serial.print("Conectando a WiFi");
    
    // Espera hasta que se conecte al WiFi
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    
    Serial.println("\nConectado a WiFi");
    Serial.print("Dirección IP: ");
    Serial.println(WiFi.localIP());
}
#endif
