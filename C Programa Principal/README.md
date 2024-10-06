# Visualizador de Temperatura y Humedad

Este repositorio contiene tres componentes clave para un sistema IoT que monitorea la temperatura y humedad usando un ESP32, almacena los datos en una base de datos MySQL y utiliza un script en Python para interactuar con la base de datos.

## 1. Base de Datos MySQL

### Descripción
Este componente incluye el esquema y las consultas necesarias para crear y gestionar la base de datos MySQL. Los datos obtenidos por el ESP32 (temperatura y humedad) se almacenan en una tabla específica.

### Archivos Relevantes:
- **Script de Creación de la Base de Datos**: Contiene el esquema de la tabla donde se almacenan los datos.
- **Consultas SQL**: Consultas necesarias para la gestión y extracción de datos.

### Tecnologías
- **MySQL**: Sistema de gestión de bases de datos utilizado para almacenar y organizar los datos recolectados.

---

## 2. Código ESP32 (PlatformIO)

### Descripción
El código desarrollado para el ESP32 está basado en el entorno de desarrollo PlatformIO. Este programa lee los valores de temperatura y humedad desde el sensor DHT11, los envía a la base de datos MySQL y controla un LED WS2812 para indicar diferentes rangos de temperatura.

### Archivos Relevantes:
- **`main.cpp`**: Código principal que realiza la lectura de sensores y envía los datos a la base de datos.
- **Configuraciones de PlatformIO**: Archivo `platformio.ini` con las dependencias y configuración del proyecto.

### Tecnologías
- **ESP32**: Microcontrolador utilizado para la lectura de datos.
- **PlatformIO**: Entorno de desarrollo para microcontroladores.
- **DHT11**: Sensor de temperatura y humedad.
- **WS2812 (NeoPixel)**: LED que cambia de color según los datos de temperatura.

---

## 3. Código Python

### Descripción
El código en Python se utiliza para realizar consultas a la base de datos MySQL y mostrar los datos recolectados por el ESP32. También permite realizar análisis o visualización de la información almacenada.

### Archivos Relevantes:
- **`script.py`**: Script principal que se conecta a la base de datos, realiza consultas y muestra los resultados.

### Tecnologías
- **Python**: Lenguaje de programación utilizado para la manipulación de datos.
- **MySQL Connector**: Librería que permite la conexión entre Python y la base de datos MySQL.

---

## Cómo Usar

1. **Configurar la Base de Datos**:
   - Ejecuta el script SQL para crear la base de datos y las tablas necesarias.

2. **Cargar el Código en el ESP32**:
   - Utiliza PlatformIO para cargar el código en tu ESP32 y asegúrate de configurar correctamente la conexión a WiFi y la URL de la base de datos.

3. **Ejecutar el Script en Python**:
   - Ejecuta el script Python para consultar los datos de la base de datos y realizar cualquier análisis adicional.

## Requisitos

- **ESP32**
- **Sensor DHT11**
- **LED WS2812**
- **MySQL**
- **Python 3.x**
