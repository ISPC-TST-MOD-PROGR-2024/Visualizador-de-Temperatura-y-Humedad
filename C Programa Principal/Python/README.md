# Inserción de Datos en Base de Datos MySQL desde Python

Este script en Python permite la inserción de datos en una base de datos MySQL. Está diseñado para trabajar con una base de datos que almacena mediciones de sensores, como temperatura y humedad, en la tabla `Mediciones`.

## Descripción General

El objetivo del script es conectarse a una base de datos MySQL, insertar datos de sensores (temperatura y humedad) en la tabla `Mediciones`, y luego cerrar la conexión. El flujo del programa es sencillo y efectivo, con manejo de excepciones para asegurar que la conexión y la inserción de datos se realicen correctamente.

### Componentes principales:
1. **Conexión a la Base de Datos**
2. **Inserción de Datos**
3. **Cierre de la Conexión**

## Requisitos Previos

Para ejecutar este script necesitas:

1. **Python 3.x** instalado en tu sistema.
2. El paquete `mysql-connector-python` instalado. Puedes instalarlo usando pip:
   ```bash
   pip install mysql-connector-python
   ```
## Configuración del Script
Antes de ejecutar el script, asegúrate de cambiar las credenciales de acceso a la base de datos:

```python
host='localhost'         # Dirección del servidor MySQL
database='sensores'       # Nombre de la base de datos
user='Prueba_sensor'      # Cambia por tu usuario de MySQL
password='Prueba_sensor'  # Cambia por tu contraseña de MySQL
```

## Funcionamiento del Código
**1. Conectar a la Base de Datos**  
La función **conectar_base_datos()** establece una conexión con el servidor MySQL. Si la conexión es exitosa, retorna el objeto de conexión, de lo contrario, imprime un error.

```python
def conectar_base_datos():
    try:
        conexion = mysql.connector.connect(
            host='localhost',        
            database='sensores',      
            user='Prueba_sensor',        
            password='Prueba_sensor'   
        )
        if conexion.is_connected():
            print("Conexión exitosa a la base de datos")
            return conexion
    except Error as e:
        print(f"Error de conexión: {e}")
        return None
```

**2. Insertar Datos en la Tabla**  
La función insertar_datos() recibe como parámetros el objeto de conexión, la temperatura y la humedad, e inserta estos valores en la tabla Mediciones de la base de datos.

```python
def insertar_datos(conexion, temperatura, humedad):
    try:
        cursor = conexion.cursor()
        query = """INSERT INTO Mediciones (temperatura, humedad) VALUES (%s, %s)"""
        datos = (temperatura, humedad)
        cursor.execute(query, datos)
        conexion.commit()
        print(f"Datos insertados: Temperatura = {temperatura}, Humedad = {humedad}")
    except Error as e:
        print(f"Error al insertar los datos: {e}")
```

**3. Flujo Principal del Programa**  
En la función main(), se maneja el flujo principal del programa. Primero, se conecta a la base de datos, luego se define una lectura de temperatura y humedad (en este caso, datos de ejemplo), y se inserta esta información en la tabla. Finalmente, se cierra la conexión.

```python
def main():
    conexion = conectar_base_datos()
    if conexion:
        temperatura = 28.7  
        humedad = 65.0      

        insertar_datos(conexion, temperatura, humedad)
        conexion.close()
        print("Conexión cerrada")
```
## Cómo Ejecutar el Script  
Asegúrate de haber configurado las credenciales de acceso a la base de datos correctamente.
Ejecuta el script con el siguiente comando:
```python
python nombre_del_script.py
```
El script intentará conectarse a la base de datos, insertar los datos de ejemplo y luego cerrar la conexión.



## Licencia

Este proyecto está licenciado bajo la Licencia Creative Commons Atribución-NoComercial (CC BY-NC). Esta licencia permite que otros remixen, adapten y construyan sobre el trabajo de forma no comercial y, aunque sus nuevos trabajos deben también reconocer al autor original y ser no comerciales, no tienen que licenciar sus obras derivadas en los mismos términos.

Esta licencia es adecuada para un uso educativo y de aprendizaje, permitiendo la libre distribución y utilización del material mientras se protege contra el uso comercial sin autorización previa. Para usos comerciales, es necesario contactar a los autores para obtener permiso.

Para obtener más información sobre esta licencia y ver una copia completa de sus términos, visite [Creative Commons Atribución-NoComercial (CC BY-NC)](https://creativecommons.org/licenses/by-nc/4.0/).


