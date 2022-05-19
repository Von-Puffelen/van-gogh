BIN = ./bin
LIB = ./lib
SRC = ./src

CC       = gcc
CFLAGS   = -std=c11
CFLAGS  += -Wall -Wextra -Wno-nullability-completeness -Wno-unused-parameter
CFLAGS  += -Wno-undef-prefix `pkg-config sdl2 --cflags`

LDLIBS  += -L ${LIB}
LDFLAGS += `pkg-config sdl2 --libs`

TARGET  = ${BIN}/"Van Gogh"

SRCS    = $(wildcard $(SRC)/*.c)
OBJS    = $(patsubst $(SRC)/%.c, $(BIN)/%.o, $(SRCS))

all: $(TARGET) start
default: all

$(TARGET): $(OBJS)
	@echo "=== Linking... ============================================================"
	$(CC) $^ -o $(TARGET) $(LDFLAGS) -O3

$(BIN)/%.o: $(SRC)/%.c
	@echo "\033[1;33m"
	@echo "=== Building... ==========================================================="
	@mkdir -p $(BIN)
	$(CC) $(CFLAGS) -c -o $@ $< -O3

start:
	@echo "\033[0;32m"
	@echo "=== Executing... =========================================================="
	@echo "\033[0m" 
	@$(TARGET)

clean:
	@echo "=== Cleaning... ==========================================================="
	@rm -rfv $(BIN) $(TARGET)

.PHONY: start clean
