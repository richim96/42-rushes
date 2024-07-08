SRC	= main.c map_read.c square_find.c square_print.c funcs.c
OBJS	= ${SRC:.c=.o}
HEAD	= globals.h libs.h
NAME	= bsq
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g

all:	${NAME}

%.o:	%.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

exec:
	./bsq
clean:
	rm -f ${OBJS}
fclean:
	rm -f ${NAME}
re:	fclean all

.PHONY:	all clean fclean re
