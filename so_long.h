#ifndef SO_LONG_H
# define SO_long_h
# define WIDTH 1200
# define HEIGHT 1200
#include<fcntl.h>

char	**ft_split(char *str, char *charset);



typedef struct s_data
{
	void 	*img;
	char	**map;
	int 	*addrs;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;
#endif // !SO_LONG_H