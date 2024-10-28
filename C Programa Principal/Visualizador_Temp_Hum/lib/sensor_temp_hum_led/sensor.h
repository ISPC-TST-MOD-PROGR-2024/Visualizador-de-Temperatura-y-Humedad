#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_NeoPixel.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#include <WiFi.h>

class Sensor_DHT11 {
public:
    Sensor_DHT11(int dhtPin, int dhtType, int ledPin, int numPixels);

    void conectarMySQL(const char* user, const char* password, const char* host, int port);
    void begin();
    void leerDatos();
    void enviarDatosMySQL(float temperatura, float humedad);
    void actualizarLED();
    void conectarWiFi(const char* ssid, const char* password);

private:
    int dhtPin;
    int dhtType;
    int ledPin;
    int numPixels;
    DHT dht;
    Adafruit_NeoPixel strip;

    // Puntero a cliente
    WiFiClient client;
    // Conexión MySQL
    MySQL_Connection conn{&client};  // Objeto de conexión MySQL
    MySQL_Cursor* cursor;  // Cursor para ejecutar consultas
};

#endif // SENSOR_H
