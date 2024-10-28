#include "sensor.h"

// Constructor de la clase Sensor
Sensor_DHT11::Sensor_DHT11(int dhtPin, int dhtType, int ledPin, int numPixels) 
    : dhtPin(dhtPin), dhtType(dhtType), ledPin(ledPin), numPixels(numPixels), 
      dht(dhtPin, dhtType), strip(numPixels, ledPin, NEO_GRB + NEO_KHZ800) {}

// Método conectarMySQL para establecer la conexión con la base de datos

void Sensor_DHT11::conectarMySQL(const char* user, const char* password, const char* host, int port) {
    IPAddress server_ip;

    // Resuelve la IP del host y verifica que sea exitosa
    if (WiFi.hostByName(host, server_ip)) {
        Serial.println("Conectando a la base de datos MySQL...");
        
        // Intenta conectarse a MySQL con la IP resuelta y el puerto
        if (conn.connect(server_ip, port, (char*)user, (char*)password)) {
            Serial.println("Conectado a MySQL");
            cursor = new MySQL_Cursor(&conn);
        } else {
            Serial.println("Error de conexión a MySQL");
        }
    } else {
        Serial.println("Error: No se pudo resolver el nombre de host.");
    }
}

// Método para inicializar el sensor DHT y los LEDs
void Sensor_DHT11::begin() {
    dht.begin();  // Inicializar el sensor DHT
    strip.begin();  // Inicializar el LED WS2812
    strip.show();   // Apagar todos los LEDs inicialmente
}

// Método para leer datos de temperatura y humedad
void Sensor_DHT11::leerDatos() {
    float temperatura = dht.readTemperature();
    float humedad = dht.readHumidity();
    
    if (isnan(temperatura) || isnan(humedad)) {
        Serial.println("Error en la lectura del sensor DHT11");
        return;
    }

    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print(" C, Humedad: ");
    Serial.print(humedad);
    Serial.println(" %");

    // Enviar datos a MySQL
    enviarDatosMySQL(temperatura, humedad);
}

// Método enviar DatosMySQL para insertar los datos en la tabla mediciones
void Sensor_DHT11::enviarDatosMySQL(float temperatura, float humedad) {
    if (conn.connected()) {
        char query[128];
        snprintf(query, sizeof(query), 
            "INSERT INTO mediciones (temperatura, humedad) VALUES (%.2f, %.2f);", 
            temperatura, humedad);

        cursor->execute(query);
        Serial.println("Datos enviados a la base de datos MySQL.");
    } else {
        Serial.println("No hay conexión con MySQL para enviar los datos.");
    }
}

// Método para actualizar el LED según la temperatura
void Sensor_DHT11::actualizarLED() {
    float temperatura = dht.readTemperature();
    
    if (temperatura > 30) {
        strip.setPixelColor(0, strip.Color(255, 0, 0));  // Rojo si temperatura > 30°C
    } else {
        strip.setPixelColor(0, strip.Color(0, 255, 0));  // Verde si temperatura <= 30°C
    }
    strip.show();
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