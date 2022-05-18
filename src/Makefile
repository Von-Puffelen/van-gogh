CC		= gcc
CFLAGS	= -Wall -Wextra -Wno-nullability-completeness -Wno-unused-parameter
CFLAGS += -Wno-undef-prefix
LDLIBS 	=

BIN 	= ../bin
OUT 	= ${BIN}/app

SRCS 	= main.c
OBJS 	= $(SRCS:%.c=%.o)

default: $(OUT)

$(OUT): $(OBJS)
	${CC} ${CFLAGS} ${OBJS} -o ${OUT} 

%.o: %.c
	${CC} ${CFLAGS} -c $^
