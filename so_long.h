#ifndef SO_LONG_H
# define SO_long_h
# define WIDTH 1200
# define HEIGHT 1200
# define KEY_LEFT 97
# define KEY_RIGHT 100
# define KEY_UP 119
# define KEY_DOWN 115
# define ESC 65307
#include<fcntl.h>
#include<stdio.h>
#include "gnl/get_next_line.h"

char **init_map(char **map);

typedef struct s_data
{
	void	*ptr_mlx;
	void	*win;
	char	**map;
	void	*img;
	void	*perso;
	void	*wall;
	void	*collect;
	void	*door;
	void	*flor;
}	t_data;
void	print_image(t_data data);
void	init_struct(t_data *data);
void	destroy(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
#endif // !SO_LONG_H