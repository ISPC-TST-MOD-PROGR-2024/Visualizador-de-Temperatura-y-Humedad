#ifndef WS2812_H
#define WS2812_H
#include <WiFi.h>

#include <Adafruit_NeoPixel.h>

class WS2812 {
  public:
    WS2812(int pin, int numPixeles);
    void begin();
    void cambiarColor(uint8_t r, uint8_t g, uint8_t b);

  private:
    Adafruit_NeoPixel strip;
}
 
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
