CXX = gcc
CXXFLAGS = -Wall -Wextra
DIST_DIR = dist
SERVER_TARGET = $(DIST_DIR)/server
CLIENT_TARGET = $(DIST_DIR)/client

.PHONY: all server client clean

all: server client

server: server.c
	mkdir -p $(DIST_DIR)
	$(CXX) $(CXXFLAGS) -o $(SERVER_TARGET) server.c

client: client.c
	mkdir -p $(DIST_DIR)
	$(CXX) $(CXXFLAGS) -o $(CLIENT_TARGET) client.c

run_server: server
	./$(SERVER_TARGET) $(PORT)

run_client: client
	./$(CLIENT_TARGET) $(SERVER_ADDRESS) $(SERVER_PORT)

clean:
	rm -rf $(DIST_DIR)