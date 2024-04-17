import socket
import sys


port = int(sys.argv[1])


with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as server_socket:
    server_socket.bind(("localhost", port))

    while True:
        data, addr = server_socket.recvfrom(1024)
        print(f"Received: {data.decode()} from {addr}\n")
