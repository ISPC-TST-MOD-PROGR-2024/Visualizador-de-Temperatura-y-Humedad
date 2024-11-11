#include "ws2812.h"

// Constructor: inicializa el LED con el número de píxeles y el pin de control
WS2812::WS2812(int pin, int numPixeles) : strip(numPixeles, pin, NEO_GRB + NEO_KHZ800) {}

// Inicializa el LED apagado
void WS2812::begin() {
  strip.begin();  // Inicializa el LED
  strip.show();   // Apaga todos los LEDs al iniciar
}

// Cambia el color del LED según los valores RGB
void WS2812::cambiarColor(uint8_t r, uint8_t g, uint8_t b) {
  strip.setPixelColor(0, strip.Color(r, g, b));  // Ajusta el color del primer píxel
  strip.show();  // Aplica el cambio de color
}
