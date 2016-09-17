CC = gcc
CCFLAGS = -std=c99 -g -Wall -Wextra -lreadline 
EXEC = prog1
OBJS = prog1.o

${EXEC}: ${OBJS}
	${CC} ${CCFLAGS} -o ${EXEC} ${OBJS}

.c.o:
	${CC} ${CCFLAGS} -c $<

clean:
	rm -f ${EXEC} ${OBJS}