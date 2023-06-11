CC := g++
CFLAGS := -Wall -std=c++11 -g
LIBS :=
BIN_DIR := bin
SRC_DIR := src
INC_DIR := include
TARGET := $(BIN_DIR)/main.out

# List of source files to compile
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)

# Include directories
INC := -I $(INC_DIR)

.PHONY: all clean run test

all: $(TARGET)

$(TARGET): $(OBJS) $(BIN_DIR)/main.o
	$(CC) $(CFLAGS) $(INC) $^ -o $@ $(LIBS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(BIN_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS) $(BIN_DIR)/main.o $(BIN_DIR)/test.o

run: $(TARGET)
	./$(TARGET)

