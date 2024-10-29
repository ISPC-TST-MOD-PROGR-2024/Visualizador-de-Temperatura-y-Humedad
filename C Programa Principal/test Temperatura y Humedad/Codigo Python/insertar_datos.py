import mysql.connector
from mysql.connector import Error

# Configuración de la base de datos
def conectar_base_datos():
    try:
        conexion = mysql.connector.connect(
            host='localhost',
            database='sensores',  # Cambia el nombre de la base de datos según sea necesario
            user='root',
            password='123456'     # Cambia la contraseña según sea necesario
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
        conexion.commit()
        print(f"Datos insertados: Temperatura = {temperatura}, Humedad = {humedad}")
    except Error as e:
        print(f"Error al insertar los datos: {e}")

# Función principal
def main():
    conexion = conectar_base_datos()
    
    if conexion:
        # Simulación de datos de temperatura y humedad
        # Aquí puedes reemplazar con la lógica para capturar datos del sensor
        temperatura = 25.0  # Ejemplo de temperatura
        humedad = 60.0      # Ejemplo de humedad
        
        # Insertar los datos en la base de datos
        insertar_datos(conexion, temperatura, humedad)
        
        # Cerrar la conexión
        conexion.close()
        print("Conexión cerrada")

if __name__ == "__main__":
    main()
