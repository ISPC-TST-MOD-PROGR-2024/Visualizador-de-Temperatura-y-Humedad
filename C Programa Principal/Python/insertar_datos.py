import mysql.connector
from mysql.connector import Error

# Función para conectarse a la base de datos
def conectar_base_datos():
    try:
        conexion = mysql.connector.connect(
            host='localhost',         # Dirección del servidor MySQL
            database='sensores',       # Nombre de la base de datos
            user='Prueba_sensor',         # Cambia por tu usuario de MySQL
            password='Prueba_sensor'   # Cambia por tu contraseña de MySQL
        )
        if conexion.is_connected():
            print("Conexión exitosa a la base de datos")
            return conexion
    except Error as e:
        print(f"Error de conexión: {e}")
        return None

# Función para insertar datos en la tabla Mediciones
def insertar_datos(conexion, temperatura, humedad):
    try:
        cursor = conexion.cursor()
        query = """INSERT INTO Mediciones (temperatura, humedad) VALUES (%s, %s)"""
        datos = (temperatura, humedad)
        cursor.execute(query, datos)
        conexion.commit()  # Confirmar los cambios en la base de datos
        print(f"Datos insertados: Temperatura = {temperatura}, Humedad = {humedad}")
    except Error as e:
        print(f"Error al insertar los datos: {e}")

# Función principal para manejar el flujo del programa
def main():
    # Conectarse a la base de datos
    conexion = conectar_base_datos()

    if conexion:
        # Datos de ejemplo (reemplázalos con lecturas reales del sensor)
        temperatura = 28.7  # Por ejemplo, temperatura de 28.7°C
        humedad = 65.0      # Por ejemplo, humedad de 65.0%

        # Insertar los datos en la tabla
        insertar_datos(conexion, temperatura, humedad)

        # Cerrar la conexión
        conexion.close()
        print("Conexión cerrada")

# Ejecutar la función principal
if __name__ == "__main__":
    main()
