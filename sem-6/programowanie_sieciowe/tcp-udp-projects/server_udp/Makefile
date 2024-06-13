CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Iinclude
DEPS = include/server.h include/utils.h
OBJ = obj/main.o obj/server.o obj/utils.o
BIN = bin/program

obj/%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BIN): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) $(BIN)