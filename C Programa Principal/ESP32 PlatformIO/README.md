# Visualizador de Temperatura y Humedad con ESP32, DHT11 y WS2812  
Este proyecto es una aplicación básica que utiliza un ESP32, un sensor de temperatura y humedad DHT11, y un LED WS2812 (NeoPixel). La información de temperatura y humedad se muestra en la consola serie, y el color del LED cambia según la temperatura.

## Estructura del Proyecto
La estructura del repositorio es la siguiente:

```python
├── .vscode/           # Configuraciones de Visual Studio Code
├── include/           # Archivos de cabecera (headers)
├── lib/               # Librerías externas
├── src/               # Código fuente principal
│   └── main.cpp       # Código principal del proyecto
├── test/              # Pruebas del proyecto
├── .gitignore         # Archivos a ignorar por Git
├── README.md          # Documentación del proyecto
├── diagram.json       # Archivo de configuración de Wokwi (simulador)
├── platformio.ini     # Configuraciones de PlatformIO
└── wokwi.toml         # Configuración para Wokwi
```

## Descripción de los Archivos
**.vscode/:** Contiene configuraciones del entorno de Visual Studio Code.  

**include/:** Archivos de cabecera necesarios para separar la lógica del código.  

**lib/:** Librerías externas que se utilizan en el proyecto.  

**src/:** Contiene el archivo main.cpp, que es el código principal.  

**test/:** Carpeta destinada para pruebas unitarias o de integración.  

**.gitignore:** Archivo que especifica qué archivos o carpetas deben ser ignorados por Git.  

**diagram.json:** Archivo generado por Wokwi para la simulación del hardware.  

**platformio.ini:** Archivo de configuración para PlatformIO, define el entorno y las dependencias del proyecto.  

**wokwi.toml:** Archivo de configuración específico para simular en Wokwi.  

## Instalación y Configuración  

**Requisitos:**  
PlatformIO  
VSCode  
Sensor DHT11  
LED WS2812  
ESP32  

**Dependencias:**  
Este proyecto utiliza las siguientes librerías, que serán automáticamente gestionadas por PlatformIO a través del archivo **platformio.ini**:
```python
[env:esp32]
platform = espressif32
board = esp32dev
framework = arduino
lib_deps = 
    adafruit/Adafruit Unified Sensor @ ^1.1.6
    adafruit/DHT sensor library @ ^1.4.3
    adafruit/Adafruit NeoPixel @ ^1.10.6
```
## Configuración de WiFi
En el archivo main.cpp, debes cambiar las credenciales de WiFi para que el ESP32 se conecte a tu red local:

```cpp
// WiFi credentials
const char* ssid = "TU_SSID";   // Cambia esto por tu SSID
const char* password = "TU_PASSWORD"; // Cambia esto por tu contraseña
```
## Código Principal (main.cpp)
El archivo main.cpp es el núcleo del proyecto. Este programa lee los valores de temperatura y humedad desde el sensor DHT11, los muestra en la consola y cambia el color del LED WS2812 según la temperatura.

## Funciones Principales
**Conexión a WiFi:** El programa intenta conectarse a una red WiFi usando las credenciales definidas. Muestra el estado de conexión por consola.  

**Lectura de datos del sensor DHT11:** En cada ciclo, se obtienen la temperatura y la humedad.  

**Control del LED WS2812:** El color del LED cambia según la temperatura:

**Rojo:** Si la temperatura es mayor a 30°C.  

**Verde:** Si la temperatura es menor o igual a 30°C.  

## Ejemplo de salida por consola:
```python
Conectado a WiFi
Temperatura: 28.7 C, Humedad: 65.0 %
```
## Ejecución
* Clona este repositorio.  

* Configura tus credenciales de WiFi en main.cpp.  

* Conecta tu ESP32 al ordenador.  

* Abre el proyecto en PlatformIO (VSCode) y carga el código en el ESP32. 

* Observa los datos de temperatura y humedad en la consola serie.  

Licencia
Este proyecto está bajo la Licencia MIT.