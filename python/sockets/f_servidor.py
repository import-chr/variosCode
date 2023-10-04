import socket
import sys
# Configuración del servidor
host = 'localhost'
port = 12345

# Crear un socket TCP/IP
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Enlace del socket al host y puerto
server_socket.bind((host, port))

# Escuchar conexiones entrantes
server_socket.listen(3)
print(f"El servidor está escuchando en {host}:{port}")

while True:
    # Aceptar una conexión entrante
    client_socket, client_address = server_socket.accept()
    print(f"Conexión entrante desde {client_address}")

    for i in range(5):
        try:
            # Recibir datos del cliente
            data = client_socket.recv(1024)
            print(f"Datos recibidos del cliente: {data.decode('utf-8')}")
            # Enviar respuesta al cliente
            response = input() # "Hola, cliente"
            client_socket.sendall(response.encode('utf-8'))
        except:
            print ('\n Hubo un fallo en la fase de comunicacion')
            
            # Cerrar las conexiones
            client_socket.close()        
            server_socket.close()