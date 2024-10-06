-- Crear base de datos si no existe
CREATE DATABASE IF NOT EXISTS `sensores`
    /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */
    /*!80016 DEFAULT ENCRYPTION='N' */;

-- Usar la base de datos recién creada
USE `sensores`;

-- ------------------------------------------------------
-- Estructura de la tabla `actuador`
-- ------------------------------------------------------

-- Elimina la tabla `actuador` si ya existe para evitar errores
DROP TABLE IF EXISTS `actuador`;

-- Crear la tabla `actuador`
CREATE TABLE `actuador` (
  `id_actuador` int NOT NULL AUTO_INCREMENT,     -- Identificador único del actuador
  `estado` varchar(10) NOT NULL,                 -- Estado del actuador (ON/OFF)
  `fecha_accion` datetime DEFAULT CURRENT_TIMESTAMP,  -- Fecha y hora de la acción realizada por el actuador
  `alerta` varchar(100) DEFAULT NULL,            -- Mensaje de alerta asociado con el actuador
  PRIMARY KEY (`id_actuador`)                    -- Definir la clave primaria
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ------------------------------------------------------
-- Datos iniciales para la tabla `actuador`
-- ------------------------------------------------------

-- Bloquear la tabla `actuador` para escritura
LOCK TABLES `actuador` WRITE;

-- Desactivar claves foráneas para insertar los datos más rápido
/*!40000 ALTER TABLE `actuador` DISABLE KEYS */;

-- Insertar datos iniciales en la tabla `actuador`
INSERT INTO `actuador` (id_actuador, estado, fecha_accion, alerta) VALUES
    (1, 'ON',  '2024-10-05 15:27:48', 'Alerta: Temperatura fuera de rango - 32.0 °C'),
    (2, 'ON',  '2024-10-05 15:27:49', 'Alerta: Humedad fuera de rango - 28.0%'),
    (3, 'OFF', '2024-10-05 15:57:23', 'Temperatura dentro de rango'),
    (4, 'OFF', '2024-10-05 15:57:23', 'Temperatura dentro de rango'),
    (5, 'OFF', '2024-10-05 15:57:23', 'Temperatura dentro de rango'),
    (6, 'OFF', '2024-10-05 15:57:23', 'Temperatura dentro de rango'),
    (7, 'ON',  '2024-10-05 15:57:23', 'Alerta: Temperatura fuera de rango - 32.0 °C');

-- Activar nuevamente las claves foráneas
/*!40000 ALTER TABLE `actuador` ENABLE KEYS */;

-- Desbloquear la tabla `actuador`
UNLOCK TABLES;

-- ------------------------------------------------------
-- Estructura de la tabla `mediciones`
-- ------------------------------------------------------

-- Elimina la tabla `mediciones` si ya existe para evitar errores
DROP TABLE IF EXISTS `mediciones`;

-- Crear la tabla `mediciones`
CREATE TABLE `mediciones` (
  `id` int NOT NULL AUTO_INCREMENT,              -- Identificador único de la medición
  `temperatura` float NOT NULL,                  -- Valor de la temperatura medida
  `humedad` float NOT NULL,                      -- Valor de la humedad medida
  `fecha` datetime DEFAULT CURRENT_TIMESTAMP,    -- Fecha y hora de la medición
  PRIMARY KEY (`id`)                             -- Definir la clave primaria
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ------------------------------------------------------
-- Datos iniciales para la tabla `mediciones`
-- ------------------------------------------------------

-- Bloquear la tabla `mediciones` para escritura
LOCK TABLES `mediciones` WRITE;

-- Desactivar claves foráneas para insertar los datos más rápido
/*!40000 ALTER TABLE `mediciones` DISABLE KEYS */;

-- Insertar datos iniciales en la tabla `mediciones`
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

-- Activar nuevamente las claves foráneas
/*!40000 ALTER TABLE `mediciones` ENABLE KEYS */;

-- Desbloquear la tabla `mediciones`
UNLOCK TABLES;

-- ------------------------------------------------------
-- Fin del script de creación de tablas y datos
-- ------------------------------------------------------

-- Restaurar configuraciones originales
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;
/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
