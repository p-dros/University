import socket
import sys


port = int(sys.argv[1])


with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
    server_socket.bind(("localhost", port))
    server_socket.listen(10)

    while True:
        (client_socket, address) = server_socket.accept()

        print(f"Connection from {address}")

        message = "Hello, world!\r\n"
        client_socket.sendall(message.encode())

        print("Message sent")

        client_socket.close()
