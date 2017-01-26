SRCS=random.c
OBJS=random.o
PROGRAM=random

${OBJS}: ${SRCS}
	gcc -c ${SRCS}

program: ${OBJS}
	gcc -g -Wall -o ${PROGRAM} ${OBJS}
