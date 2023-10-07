import socket
import sys

#INICIA FASE DE CONFIGURACION

#crea el socket
cliente_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#AF_INET protocolos para establecer el socket, comunicar socket a travez de internet
#SOCK_STREAM socket tipo TCP
direccion_servidor = ('localhost', 12345)
#localhost = direccion ip
#12345 = puerto del servidor

cliente_socket.connect(direccion_servidor)
#conexion con el servidor

#COMIENZA FASE DE COMUNICACION 
try:
    for i in range(5):
        # Enviar datos al servidor
        message = input() # "Hola, servidor"
        cliente_socket.sendall(message.encode('utf-8'))

        # Recibir respuesta del servidor
        data = cliente_socket.recv(1024)
        print(f"Respuesta del servidor: {data.decode('utf-8')}")

except:
    print ('\n Hubo un fallo en la fase de comunicacion')

# Cerrar la conexión
cliente_socket.close()