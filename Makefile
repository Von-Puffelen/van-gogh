TARGET  = ${BIN}/"Van Gogh"

BIN  = ./bin
LIB  = ./lib
SRC  = ./src
SDIR = $(addprefix $(BIN), /gfx)

CC       = gcc
CFLAGS   = -std=c11
CFLAGS  += -Wall -Wextra -Wno-nullability-completeness -Wno-unused-parameter
CFLAGS  += -Wno-undef-prefix
CFLAGS  += `pkg-config --cflags glfw3 cglm`

LDLIBS  += -L $(LIB)
LDFLAGS += `pkg-config --static --libs glfw3 cglm` -lm -lglfw -lGLEW
LDFLAGS += -framework OpenGL -framework IOKIT -framework CoreVideo -framework Cocoa
LDFLAGS += -Ilib/stb

INC := -I ./include
DEF := -DCGLM_STATIC=ON

SRCS    = $(wildcard $(SRC)/*.c) $(wildcard $(SRC)/**/*.c)
OBJS    = $(patsubst $(SRC)/%.c, $(BIN)/%.o, $(SRCS))

all: $(TARGET) start
default: all

$(TARGET): $(OBJS)
	@echo "\033[1;33m"
	@echo "=== Linking... ========================================================="
	$(CC) $^ -o $(TARGET) $(DEF) $(LDLIBS) $(LDFLAGS) -O3

$(BIN)/%.o: $(SRC)/%.c
	@echo "\033[1;33m"
	@echo "=== Building... ========================================================"
	mkdir -p $(BIN) $(SDIR) 
	$(CC) $(CFLAGS) $(INC) -c -o $@ $< -O3

start:
	@echo "\033[0;32m"
	@echo "=== Executing... ======================================================="
	@echo "\033[0m" 
	@$(TARGET)

clean:
	@echo "\033[0;32m"
	@echo "=== Cleaning... ========================================================"
	@rm -rfv $(BIN) $(TARGET)

.PHONY: start clean
