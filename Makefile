
CXX    = clang++
TARGET = van-gogh

# project structure
BIN = ./bin
LIB = ./libs
INC = ./include
SRC = ./src

OUT = $(BIN)/$(TARGET)

# Dependencies
PATH_GLFW = $(LIB)/glfw
PATH_GLEW = $(LIB)/glew
PATH_GLM = $(LIB)/glm
PATH_STB = $(LIB)/stb

# Flags
CXXFLAGS  = -std=c++20 -g -O1
CXXFLAGS += -Wall -Wextra -Wno-nullability-completeness -Wno-unused-parameter
CXXFLAGS += -Wpedantic -Wno-undef-prefix

LDFLAGS   = -lm -lstdc++ 
LDFLAGS  += $(PATH_GLFW)/src/libglfw3.a # GLFW
LDFLAGS  += $(PATH_GLEW)/lib/libGLEW.a  # GLEW 

INCFLAGS  = -iquotesrc
INCFLAGS += -I$(INC)
INCFLAGS += -I$(PATH_GLFW)/include 
INCFLAGS += -I$(PATH_GLEW)/include 
INCFLAGS += -I$(PATH_GLM) 
INCFLAGS += -I$(PATH_STB) 

# Frameworks
FRAMEWORKS  = -framework OpenGL
FRAMEWORKS += -framework Cocoa
FRAMEWORKS += -framework IOKIT
FRAMEWORKS += -framework CoreFoundation

# sources 
SRCS = $(shell find $(SRC) -name "*.cpp")
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET) start

libs:
	cd $(LIB)/glfw && cmake . && make
	cd $(LIB)/glm && cmake . && make

$(TARGET): $(OBJS)
	@echo "\033[1;33m"
	@echo "=== Linking... ========================================================="
	@mkdir -p $(BIN)
	$(CXX) $^ -o $(OUT) $(LDFLAGS) $(FRAMEWORKS) 

%.o: %.cpp
	@echo "\033[1;33m"
	@echo "=== Building... ========================================================"
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c -o $@ $< 

start:
	@echo "\033[0;32m"
	@echo "=== Executing... ======================================================="
	@echo "\033[0m" 
	@$(OUT)

clean:
	@echo "\033[0;32m"
	@echo "=== Cleaning... ========================================================"
	@rm -rfv $(OBJS) 

.PHONY: start clean
