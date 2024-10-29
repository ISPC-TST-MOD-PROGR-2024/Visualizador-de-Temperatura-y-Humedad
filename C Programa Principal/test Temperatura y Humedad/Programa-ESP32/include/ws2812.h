#ifndef WS2812_H
#define WS2812_H

#include <Adafruit_NeoPixel.h>

class WS2812 {
  public:
    WS2812(int pin, int numPixeles);
    void begin();
    void cambiarColor(uint8_t r, uint8_t g, uint8_t b);

  private:
    Adafruit_NeoPixel strip;
};

#endif
