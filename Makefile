OUT 	= "Van Gogh" 
BIN 	= ./bin
SRC 	= ./src

GREEN 	= "\033[0;32m"
YELLOW 	= "\033[1;33m"
NO_COLOUR  = "\033[0m"

all: build start
default: all

start:
	@echo ${GREEN}==== EXECUTING APPLICATION ==========================================
	@echo ${NO_COLOUR}
	@${BIN}/${OUT}

build:
	@echo ${GREEN}==== BUILDING APPLICATION ===========================================
	@mkdir -p ${BIN}
	@+$(MAKE) -C ${SRC}

clean:
	@echo ${YELLOW}==== PURGING APPLICATION ============================================
	@rm -rfv ${SRC}/*.o 
	@rm -rfv ${BIN}

.PHONY: start build clean
