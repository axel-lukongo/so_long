CC = gcc

RM = rm -rf

NAME = so_long

SRCS = so_long.c\

BONUS_SRCS	=	${BONUS}

OBJ	= ${SRCS:.c=.o}

CFLAGS	= -g -Wall -Wextra -Werror


.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	$(CC) $(SRCS) minilibx/libmlx_Linux.a -lXext -lX11 -o $(NAME) 

all: ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re