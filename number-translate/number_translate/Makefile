SRC	= *.c
SRCS	= ${SRC}
OBJS	= ${SRCS:.c=.o}
HEAD	= rush_02.h
DICT	= ./dicts/
NAME	= rush-02
GCC	= cc
CFLAGS	= -Wall -Wextra -Werror

all:	${NAME}

.c.o:
	${GCC} ${CFLAGS} -c -I. $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${GCC} ${CFLAGS} -o ${NAME} ${OBJS}

exec:
	./rush-02			
clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:		all clean fclean re
