CC		= gcc
CFLAGS	= -std=c11
CFLAGS += -Wall -Wextra -Wno-nullability-completeness -Wno-unused-parameter
CFLAGS += -Wno-undef-prefix
CFLAGS += `sdl2-config --cflags`
LDFLAGS	= `sdl2-config --libs`

BIN 	= ../bin
OUT 	= ${BIN}/"Van Gogh"

SRCS 	= main.c window.c
OBJS 	= $(SRCS:%.c=%.o)

default: $(OUT)

$(OUT): $(OBJS)
	${CC} ${CFLAGS} ${LDFLAGS} ${OBJS} -o ${OUT} 

%.o: %.c
	${CC} ${CFLAGS} -c $^
