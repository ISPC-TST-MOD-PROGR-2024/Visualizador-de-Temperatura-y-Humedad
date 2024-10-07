
# Visualizador de Temperatura y Humedad

Este proyecto se enfoca en el diseño e implementación de un dispositivo IoT para el monitoreo de variables ambientales, en este caso, la **temperatura** y la **humedad**. Utiliza un sensor **DHT11** para recolectar los datos, procesados por un microcontrolador **ESP32** y almacenados en una base de datos **MySQL** a través de conectividad **WiFi**. Además, incluye un sistema de alerta visual mediante un **LED WS2812**, que cambia de color cuando se superan ciertos umbrales.

## Tabla de Contenidos
- [Resumen](#resumen)
- [Stack Tecnológico](#stack-tecnológico)
- [Diagrama de Conexión](#diagrama-de-conexión)
- [Metodología](#metodología)
  - [Simulación](#simulación)
  - [Implementación Física](#implementación-física)
- [Pruebas y Resultados](#pruebas-y-resultados)
- [Conclusión](#conclusión)

## Resumen

El sistema de monitoreo ambiental permite la medición en tiempo real de la temperatura y la humedad. Los datos son enviados a una base de datos para su análisis y almacenamiento. Adicionalmente, el dispositivo monitorea el nivel de batería para asegurar su funcionamiento continuo, y utiliza un LED WS2812 como indicador visual cuando se exceden ciertos parámetros definidos.

## Stack Tecnológico

- **Lenguajes de Programación**: 
  - **C++**: Para la programación del ESP32.
  - **Python**: Para conectar la base de datos MySQL y realizar consultas.
  
- **Entorno de Desarrollo**:
  - **Visual Studio Code con PlatformIO**: Para el desarrollo del firmware del ESP32.
  
- **Microcontrolador**:
  - **ESP32**: Recolecta los datos del sensor y controla el LED WS2812.
  
- **Base de Datos**:
  - **MySQL**: Almacena las mediciones de temperatura, humedad y nivel de batería.
  - **MySQL Workbench**: Herramienta para gestionar la base de datos.
  
- **Componentes Físicos**:
  - **Sensor DHT11**: Mide temperatura y humedad.
  - **LED WS2812**: Señal visual de alerta.
  - **Medidor de nivel de batería**: Monitorea la batería del dispositivo.

- **Conectividad**: 
  - **Wi-Fi**: Para enviar los datos al servidor.

## Diagrama de Conexión

![Diagrama de Conexión](./E%20assets/diagramaConexion.PNG)

## Metodología

### Simulación
La simulación se realizó utilizando la plataforma **Wokwi** para validar el correcto funcionamiento de los componentes y su interconexión. Los pasos incluyeron la selección del hardware virtual, la configuración de la simulación, la programación en **C++**, y pruebas de funcionamiento.

### Implementación Física
Una vez validada la simulación, se procedió a la construcción del sistema real, integrando el **ESP32**, el **DHT11** y el **LED WS2812**. El código se ajustó para la implementación física y se conectó el ESP32 a una red **Wi-Fi** para la transmisión de datos a una base de datos **MySQL**. También se implementó un sistema de medición del nivel de batería.

## Pruebas y Resultados

Las pruebas realizadas en entornos controlados mostraron que el sistema responde correctamente a las lecturas del sensor. El **LED WS2812** se activa y cambia de color cuando los valores de temperatura o humedad exceden los umbrales definidos. Además, el sistema es capaz de almacenar los datos en la base de datos MySQL en tiempo real.

## Conclusión

Este proyecto demostró ser efectivo para el monitoreo de temperatura y humedad en tiempo real, con un diseño modular y replicable. Las pruebas tanto en simulación como en implementación física confirmaron la funcionalidad del sistema.

---

Proyecto realizado por:
- Karina Jazmin Barbero
- Macarena Aylén Carballo
- Nicolás Nahuel Barrionuevo
- Raúl Antonio Jara

Profesor: Lisandro Lanfranco

## Licencia

Este proyecto está licenciado bajo la Licencia Creative Commons Atribución-NoComercial (CC BY-NC). Esta licencia permite que otros remixen, adapten y construyan sobre el trabajo de forma no comercial y, aunque sus nuevos trabajos deben también reconocer al autor original y ser no comerciales, no tienen que licenciar sus obras derivadas en los mismos términos.

Esta licencia es adecuada para un uso educativo y de aprendizaje, permitiendo la libre distribución y utilización del material mientras se protege contra el uso comercial sin autorización previa. Para usos comerciales, es necesario contactar a los autores para obtener permiso.

Para obtener más información sobre esta licencia y ver una copia completa de sus términos, visite [Creative Commons Atribución-NoComercial (CC BY-NC)](https://creativecommons.org/licenses/by-nc/4.0/).

![img](./E%20assets/ispclogo.PNG)

