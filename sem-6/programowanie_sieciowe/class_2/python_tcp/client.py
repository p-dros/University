import socket
import sys

ip_address = sys.argv[1]
port = int(sys.argv[2])


with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
    client_socket.connect((ip_address, port))
    data = client_socket.recv(1024)

print(f"Received: {data.decode()}")
