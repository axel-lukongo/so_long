CC = gcc

RM = rm -rf

NAME = so_long

SRCS = so_long.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c\
		init_all.c\
		destroy_all.c\
		movement.c\
		open_door.c\
		end_game.c\
		tcheck_map.c\

BONUS_SRCS	=	${BONUS}

OBJ	= ${SRCS:.c=.o}

CFLAGS	= -g -Wall -Werror -Wextra

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	make -C ft_printf
	$(CC) $(SRCS) minilibx/libmlx_Linux.a ft_printf/libftprintf.a -lXext -lX11 -o $(NAME) 

all: ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	make fclean -C ft_printf
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
