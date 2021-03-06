CC = gcc

RM = rm -rf

NAME = so_long

BONUS_NAME = so_long_bonus

SRCS = main.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c\
		init_all.c\
		destroy_all.c\
		movement.c\
		check_contents.c\
		end_game.c\
		check_map.c\
		game_event.c\

BONUS_SRC = bonus/so_long_bonus.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c\
		bonus/init_all_bonus.c\
		bonus/destroy_all_bonus.c\
		bonus/movement_bonus.c\
		bonus/check_contents_bonus.c\
		bonus/end_game_bonus.c\
		bonus/check_map_bonus.c\
		bonus/game_event_bonus.c\


BONUS_SRCS = ${BONUS_SRC}

OBJ	= ${SRCS:.c=.o}

BONUS_OBJS	= ${BONUS_SRCS:.c=.o}

CFLAGS	= -g -Wall -Werror -Wextra

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	make -C ft_printf
	make -C minilibx
	$(CC) $(SRCS) ${CFLAGS} minilibx/libmlx_Linux.a ft_printf/libftprintf.a -lXext -lX11 -o $(NAME) 

all: ${NAME}

bonus:	${BONUS_OBJS} ${BONUS}
	make -C ft_printf
	make -C minilibx
	$(CC) $(BONUS_SRCS) ${CFLAGS} minilibx/libmlx_Linux.a ft_printf/libftprintf.a -lXext -lX11 -o $(BONUS_NAME) 

clean:
	${RM} ${OBJ} ${BONUS_OBJS}

fclean: clean
	make fclean -C ft_printf
	make clean -C minilibx
	${RM} ${NAME} ${BONUS_NAME}

re: fclean all

.PHONY: all clean fclean re
