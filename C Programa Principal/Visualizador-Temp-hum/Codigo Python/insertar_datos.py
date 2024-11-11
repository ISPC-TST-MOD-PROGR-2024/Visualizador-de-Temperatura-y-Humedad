import mysql.connector  # Importa el módulo para interactuar con una base de datos MySQL
from mysql.connector import Error  # Importa la clase de errores para manejar excepciones en MySQL
import serial  # Importa la librería para manejar la comunicación serial
import time  # Importa el módulo para manejar retrasos de tiempo

# Conectar al puerto serial (ajusta 'COM3' al puerto que estés usando)
ser = serial.Serial('COM3', 115200, timeout=1)  # Configura el puerto serial con la velocidad en baudios (115200) y un tiempo de espera
time.sleep(2)  # Espera 2 segundos para establecer la conexión serial correctamente

# Función para conectar a la base de datos MySQL
def conectar_base_datos():
    try:
        # Intenta establecer la conexión con los parámetros proporcionados
        conexion = mysql.connector.connect(
            host='localhost',  # Dirección del servidor MySQL (localhost en este caso)
            database='sensores',  # Nombre de la base de datos
            user='root',  # Usuario de la base de datos
            password='123456'  # Contraseña del usuario de la base de datos
        )
        if conexion.is_connected():
            print("Conexión exitosa a la base de datos")
            return conexion  # Devuelve la conexión si se establece correctamente
    except Error as e:
        # Muestra un mensaje de error si la conexión falla
        print(f"Error de conexión: {e}")
        return None  # Devuelve None si no se puede conectar

# Función para insertar los datos de temperatura, humedad y el color del LED en la base de datos
def insertar_datos(temperatura, humedad, color):
    conexion = conectar_base_datos()  # Conectar a la base de datos
    if not conexion:
        return  # Si no se puede conectar, termina la función
    try:
        with conexion.cursor() as cursor:
            # Inserta los datos de temperatura y humedad en la tabla 'Mediciones'
            query = "INSERT INTO Mediciones (temperatura, humedad) VALUES (%s, %s)"
            cursor.execute(query, (temperatura, humedad))
            
            # Inserta el color del LED en la tabla 'Estado_led'
            query_led = "INSERT INTO Estado_led (color) VALUES (%s)"
            cursor.execute(query_led, (color,))
            
            conexion.commit()  # Guarda los cambios en la base de datos
            print(f"Datos insertados: Temperatura = {temperatura}, Humedad = {humedad}, Color LED = {color}")
    except Error as e:
        # Si ocurre un error al insertar los datos, se muestra un mensaje
        print(f"Error al insertar los datos: {e}")
    finally:
        conexion.close()  # Cierra la conexión a la base de datos

# Bucle principal que ejecuta continuamente el programa
while True:
    # Si hay datos disponibles en el puerto serial
    if ser.in_waiting > 0:
        # Lee la línea del puerto serial, la decodifica y elimina los espacios en blanco
        line = ser.readline().decode('utf-8').strip()
        
        # Divide los datos recibidos separados por comas
        data = line.split(',')
        
        # Si se reciben exactamente 3 elementos (temperatura, humedad, color LED)
        if len(data) == 3:
            temperatura, humedad, color = data  # Asigna cada valor a sus respectivas variables
            
            # Inserta los datos en la base de datos
            insertar_datos(float(temperatura), float(humedad), color)
    
    # Espera 2 segundos antes de leer nuevamente del puerto serial
    time.sleep(2)
