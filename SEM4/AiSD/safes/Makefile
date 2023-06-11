CC := g++
CFLAGS := -Wall -std=c++11 -g
LIBS :=
BIN_DIR := bin
SRC_DIR := src
INC_DIR := include
MAIN_TARGET := $(BIN_DIR)/main.out
TEST_TARGET := $(BIN_DIR)/test.out

# List of source files to compile
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
MAIN_OBJS := $(filter-out $(BIN_DIR)/test.o, $(SRCS:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o))
TEST_OBJS := $(filter-out $(BIN_DIR)/main.o, $(SRCS:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o))

# Include directories
INC := -I $(INC_DIR)

.PHONY: all clean run test

all: $(MAIN_TARGET)

$(MAIN_TARGET): $(MAIN_OBJS)
	$(CC) $(CFLAGS) $(INC) $^ -o $@ $(LIBS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(MAIN_TARGET) $(TEST_TARGET) $(MAIN_OBJS) $(TEST_OBJS)

run: $(MAIN_TARGET)
	./$(MAIN_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	$(CC) $(CFLAGS) $(INC) $^ -o $@ $(LIBS)
