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
		game_event.c\

BONUS_SRCS	=	bonus/destroy_all_bonus.c\
				bonus/gnl/get_next_line.c\
				bonus/gnl/get_next_line_utils.c\
				bonus/init_all_bonus.c\
				bonus/movement_bonus.c\
				bonus/so_long_bonus.c\
				bonus/end_game_bonus.c\
				bonus/game_event_bonus.c\
				bonus/open_door_bonus.c\
				bonus/tcheck_map_bonus.c\

OBJ	= ${SRCS:.c=.o}

OBJ_BONUS	= ${bonus/,${BONUS_SRCS:.c=.o}}

CFLAGS	= -g -Wall -Werror -Wextra

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	make -C ft_printf
	$(CC) $(SRCS) minilibx/libmlx_Linux.a ft_printf/libftprintf.a -lXext -lX11 -o $(NAME) 

all: ${NAME}

bonus : $(BONUS_OBJ)
	make -C ft_printf
	$(CC) $(BONUS_SRCS) minilibx/libmlx_Linux.a ft_printf/libftprintf.a -lXext -lX11 -o $(NAME) 

val : ${NAME}
		valgrind \

clean:
	${RM} ${OBJ} ${BONUS_OBJ}

fclean: clean
	make fclean -C ft_printf
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
