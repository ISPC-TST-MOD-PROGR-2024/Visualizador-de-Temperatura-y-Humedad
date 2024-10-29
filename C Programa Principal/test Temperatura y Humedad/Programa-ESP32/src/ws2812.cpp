#include "ws2812.h"
#include <WiFi.h>

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
