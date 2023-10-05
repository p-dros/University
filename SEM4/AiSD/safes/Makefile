CC := g++
CFLAGS := -Wall -std=c++11 -g
BIN_DIR := bin
SRC_DIR := src
INC_DIR := include
MAIN_TARGET := $(BIN_DIR)/main.out
TEST_TARGET := $(BIN_DIR)/test.out

TEST_FILES := 1_23.txt 2_3.txt 3_8.txt 4_1000.txt 5_500.txt 6_2.txt 7_31.txt 8_5041.txt 10_1.txt 11_20175.txt 12_991043.txt 13_19.txt 14_1.txt

# List of source files to compile
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
MAIN_OBJS := $(filter-out $(BIN_DIR)/test.o, $(SRCS:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o))
TEST_OBJS := $(filter-out $(BIN_DIR)/main.o, $(SRCS:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o))

# Include directories
INC := -I $(INC_DIR)

.PHONY: all clean run test

all: $(MAIN_TARGET)

$(TEST_FILES): %: $(MAIN_TARGET)
	./$(MAIN_TARGET) < tests/$@

$(MAIN_TARGET): $(MAIN_OBJS)
	$(CC) $(CFLAGS) $(INC) $^ -o $@ 

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
