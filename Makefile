NAME	:= mirror
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror
MLXFLG	:= -Iinclude -ldl -lglfw -pthread -lm
MLXLIB	:= mlx42/libmlx42.a
RM		:= rm -rf
SRC		:= mirror.c
OBJ		:= ${SRC:.c=.o}
BNOBJ	:= ${BNSRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${OBJ} ${MLXLIB} ${CFLAGS} ${MLXFLG} -o ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re bonus
