#ifndef SO_LONG_H
# define SO_long_h
# define WIDTH 1200
# define HEIGHT 1200
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

void init_struct(t_data *data);

#endif // !SO_LONG_H