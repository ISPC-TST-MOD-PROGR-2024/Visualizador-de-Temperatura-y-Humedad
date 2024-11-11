#ifndef WS2812_H
#define WS2812_H

#include <Adafruit_NeoPixel.h>

// Clase para controlar el LED WS2812
class WS2812 {
  public:
    WS2812(int pin, int numPixeles);  // Constructor
    void begin();  // Inicializa el LED
    void cambiarColor(uint8_t r, uint8_t g, uint8_t b);  // Cambia el color del LED

  private:
    Adafruit_NeoPixel strip;  // Objeto para controlar el LED
};

#endif
