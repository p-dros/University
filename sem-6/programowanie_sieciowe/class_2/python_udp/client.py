import socket
import sys

ip_address = sys.argv[1]
port = int(sys.argv[2])


with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as client_socket:
    client_socket.sendto(b"Hello, world!", (ip_address, port))
