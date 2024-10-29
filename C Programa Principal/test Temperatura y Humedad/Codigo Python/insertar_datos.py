import mysql.connector
from mysql.connector import Error
import serial
import time

# Conectar al puerto serial (ajusta el puerto a tu configuración)
ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=1)
time.sleep(2)  # Esperar para establecer la conexión

def conectar_base_datos():
    try:
        conexion = mysql.connector.connect(
            host='localhost',
            database='sensores',
            user='root',
            password='123456'
        )
        if conexion.is_connected():
            print("Conexión exitosa a la base de datos")
            return conexion
    except Error as e:
        print(f"Error de conexión: {e}")
        return None

def insertar_datos(temperatura, humedad, color):
    conexion = conectar_base_datos()
    if not conexion:
        return
    try:
        with conexion.cursor() as cursor:
            query = "INSERT INTO Mediciones (temperatura, humedad) VALUES (%s, %s)"
            cursor.execute(query, (temperatura, humedad))
            query_led = "INSERT INTO Estado_led (color) VALUES (%s)"
            cursor.execute(query_led, (color,))
            conexion.commit()
            print(f"Datos insertados: Temperatura = {temperatura}, Humedad = {humedad}, Color LED = {color}")
    except Error as e:
        print(f"Error al insertar los datos: {e}")
    finally:
        conexion.close()

while True:
    if ser.in_waiting > 0:
        line = ser.readline().decode('utf-8').strip()
        data = line.split(',')
        if len(data) == 3:
            temperatura, humedad, color = data
            insertar_datos(float(temperatura), float(humedad), color)
    time.sleep(2)
