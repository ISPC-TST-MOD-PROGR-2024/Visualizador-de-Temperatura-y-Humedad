# Script SQL para la Base de Datos `sensores`

Este script SQL crea una base de datos llamada `sensores`, define las estructuras de las tablas `actuador` y `mediciones`, e inserta algunos datos iniciales para ambas tablas. A continuación se explican cada uno de los componentes del script.

## Tabla de Contenidos

- [Crear la Base de Datos](#crear-la-base-de-datos)
- [Tabla `actuador`](#tabla-actuador)
- [Tabla `mediciones`](#tabla-mediciones)
- [Configuraciones Finales](#configuraciones-finales)

---

## Crear la Base de Datos

```sql
CREATE DATABASE IF NOT EXISTS `sensores`
    /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */
    /*!80016 DEFAULT ENCRYPTION='N' */;
```
## Explicación:  
**Base de datos sensores:** Este comando crea una base de datos llamada sensores si no existe previamente.  
**Conjunto de caracteres y collation:** Se usa el conjunto de caracteres utf8mb4 para soportar una amplia variedad de caracteres, incluidos emojis y caracteres de diferentes idiomas. El collation utf8mb4_0900_ai_ci asegura que las comparaciones de texto sean insensibles a mayúsculas y acentos.  


## Usar la Base de Datos  

```sql
USE `sensores`;
```  
## Explicación:
Este comando selecciona la base de datos sensores para que todas las operaciones posteriores se apliquen en ella.

# Tabla actuador

## Crear la Tabla

```sql
CREATE TABLE `actuador` (
  `id_actuador` int NOT NULL AUTO_INCREMENT,     -- Identificador único del actuador
  `estado` varchar(10) NOT NULL,                 -- Estado del actuador (ON/OFF)
  `fecha_accion` datetime DEFAULT CURRENT_TIMESTAMP,  -- Fecha y hora de la acción realizada
  `alerta` varchar(100) DEFAULT NULL,            -- Mensaje de alerta asociado con el actuador
  PRIMARY KEY (`id_actuador`)                    -- Definir la clave primaria
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
```  

## Explicación:
**id_actuador:** Es el identificador único del actuador, se auto incrementa con cada nuevo registro.
estado: Indica el estado del actuador (puede ser ON o OFF).  

**fecha_accion:** Fecha y hora de la acción realizada. Se define como el valor por defecto la fecha y hora actual (CURRENT_TIMESTAMP).
alerta: Un mensaje de alerta opcional asociado con el actuador.  

**Motor de almacenamiento:** Se utiliza el motor de almacenamiento InnoDB, que soporta transacciones y claves foráneas.
Conjunto de caracteres: Se define utf8mb4 para manejar caracteres especiales.  

## Insertar Datos en actuador
```sql
INSERT INTO `actuador` (id_actuador, estado, fecha_accion, alerta) VALUES
    (1, 'ON',  '2024-10-05 15:27:48', 'Alerta: Temperatura fuera de rango - 32.0 °C'),
    (2, 'ON',  '2024-10-05 15:27:49', 'Alerta: Humedad fuera de rango - 28.0%'),
    (3, 'OFF', '2024-10-05 15:57:23', 'Temperatura dentro de rango'),
    (4, 'OFF', '2024-10-05 15:57:23', 'Temperatura dentro de rango'),
    (5, 'OFF', '2024-10-05 15:57:23', 'Temperatura dentro de rango'),
    (6, 'OFF', '2024-10-05 15:57:23', 'Temperatura dentro de rango'),
    (7, 'ON',  '2024-10-05 15:57:23', 'Alerta: Temperatura fuera de rango - 32.0 °C');
```
## Explicación:
Se insertan valores iniciales en la tabla actuador, indicando el estado y las alertas relacionadas con las acciones de los actuadores.

# Tabla mediciones  

## Crear la Tabla
```sql
CREATE TABLE `mediciones` (
  `id` int NOT NULL AUTO_INCREMENT,              -- Identificador único de la medición
  `temperatura` float NOT NULL,                  -- Valor de la temperatura medida
  `humedad` float NOT NULL,                      -- Valor de la humedad medida
  `fecha` datetime DEFAULT CURRENT_TIMESTAMP,    -- Fecha y hora de la medición
  PRIMARY KEY (`id`)                             -- Definir la clave primaria
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
```

## Explicación:  

**id:** Identificador único de la medición, que se auto incrementa.
temperatura: Valor de la temperatura registrado.  

**humedad:** Valor de la humedad registrado.  

**fecha:** Fecha y hora de la medición. Se usa CURRENT_TIMESTAMP como valor predeterminado.  

**Motor InnoDB y utf8mb4:** Igual que la tabla anterior, estas opciones aseguran el manejo correcto de transacciones y caracteres.  

## Insertar Datos en mediciones
```sql
INSERT INTO `mediciones` (id, temperatura, humedad, fecha) VALUES
    (1, 25.3, 60.5, '2024-10-05 15:21:35'),
    (2, 30.1, 70.2, '2024-10-05 15:21:35'),
    (3, 22.4, 55.8, '2024-10-05 15:21:35'),
    (4, 28.7, 65,   '2024-10-05 15:21:35'),
    (5, 32.0, 28.0, '2024-10-05 15:25:12'),
    (6, 32.0, 28.0, '2024-10-05 15:27:48'),
    (7, 25.3, 60.5, '2024-10-05 15:56:49'),
    (8, 30.1, 70.2, '2024-10-05 15:56:49'),
    (9, 22.4, 55.8, '2024-10-05 15:56:49'),
    (10, 28.7, 65,  '2024-10-05 15:56:49'),
    (11, 32.0, 28.0, '2024-10-05 15:56:49');
```
## Explicación:
Se insertan valores iniciales para las mediciones de temperatura y humedad. Cada registro incluye la fecha y hora de la medición.

**Configuraciones Finales**  
Al final del script, se restauran algunas configuraciones que pudieran haber sido alteradas temporalmente para optimizar la inserción de datos:  

```sql
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;
```

**Restaurar zona horaria:** Se restablece la configuración original de zona horaria.  

**Restaurar modo SQL y otros valores:** Las configuraciones de claves foráneas y verificaciones únicas se restauran a su estado original.  

Este script crea las tablas necesarias, las llena con algunos datos iniciales y asegura que las configuraciones originales se restauren al final.
```sql
/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
```
## Licencia

Este proyecto está licenciado bajo la Licencia Creative Commons Atribución-NoComercial (CC BY-NC). Esta licencia permite que otros remixen, adapten y construyan sobre el trabajo de forma no comercial y, aunque sus nuevos trabajos deben también reconocer al autor original y ser no comerciales, no tienen que licenciar sus obras derivadas en los mismos términos.

Esta licencia es adecuada para un uso educativo y de aprendizaje, permitiendo la libre distribución y utilización del material mientras se protege contra el uso comercial sin autorización previa. Para usos comerciales, es necesario contactar a los autores para obtener permiso.

Para obtener más información sobre esta licencia y ver una copia completa de sus términos, visite [Creative Commons Atribución-NoComercial (CC BY-NC)](https://creativecommons.org/licenses/by-nc/4.0/).


