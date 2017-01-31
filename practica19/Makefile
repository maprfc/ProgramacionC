SRCS=sifile.c
OBJS=sifile.o
PROGRAMA=sifile

${OBJS}: ${SRCS}
	gcc -g -c ${SRCS}

${PROGRAMA}: ${OBJS}
	gcc -o ${PROGRAMA} ${OBJS}

all: ${PROGRAMA}

clean:
	rm -f ${PROGRAMA} ${OBJS}
