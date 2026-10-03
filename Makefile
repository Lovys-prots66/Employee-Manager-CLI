CC = clang

CFLAGS = -Wall -Wextra -Iinclude -g -O2

SRC_DIR = src
BUILD_DIR = build

SRCs = $(wildcard $(SRC_DIR)/*.c)
TARGET = $(BUILD_DIR)/main.exe

OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCs))

all: $(TARGET) 

$(TARGET): $(OBJS)
	mkdir -p $(BUILD_DIR)
	$(CC) $(OBJS) -o $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(BUILD_DIR)

run: all
	./$(TARGET)
.PHONY: all clean run
