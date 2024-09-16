#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Adafruit_NeoPixel.h>
#include <WiFi.h>

// DHT11
#define DHTPIN 15  // Pin donde está conectado el DHT11
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// WS2812
#define LED_PIN 4   // Pin donde está conectado el WS2812
#define NUMPIXELS 1  // Número de LEDs
Adafruit_NeoPixel strip(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

// WiFi credentials
const char* ssid = "TU_SSID";   // Cambia esto por tu SSID
const char* password = "TU_PASSWORD"; // Cambia esto por tu contraseña

void setup() {
  Serial.begin(115200);
  dht.begin();
  strip.begin();
  strip.show();  // Inicializar todos los LEDs apagados

  // Conectar a WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Conectado a WiFi");
}

void loop() {
  // Leer temperatura y humedad
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Fallo en la lectura del sensor DHT11");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.print(" C, Humedad: ");
  Serial.print(hum);
  Serial.println(" %");

  // Cambiar el color del LED en función de la temperatura
  if (temp > 30) {
    strip.setPixelColor(0, strip.Color(255, 0, 0));  // Rojo si temperatura > 30°C
  } else {
    strip.setPixelColor(0, strip.Color(0, 255, 0));  // Verde si temperatura <= 30°C
  }
  strip.show();

  delay(2000);
}
