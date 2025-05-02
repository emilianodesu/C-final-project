# Configuración básica
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra
SRC_DIR = src
BIN_DIR = bin
SOURCES = $(wildcard $(SRC_DIR)/*.c)
EXECUTABLE = $(BIN_DIR)/tienda

.PHONY: all run clean

all: $(EXECUTABLE)

# Compilación directa
$(EXECUTABLE): $(SOURCES) include/*.h
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(BIN_DIR)