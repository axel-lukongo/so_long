#ifndef SO_LONG_H
# define SO_long_h
# define WIDTH 500
# define HEIGHT 500
#include<fcntl.h>
#include<stdio.h>
#include "gnl/get_next_line.h"

char **init_map(char **map);

typedef struct s_data
{
	void	*ptr_mlx;
	void	*win;
	void 	*img;
	char	**map;
	int 	*addrs;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_image
{
	char	*wall;
	char	*flor;
}	t_image;

#endif // !SO_LONG_H