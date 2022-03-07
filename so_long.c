#include"minilibx/mlx.h"
#include "so_long.h"
#include<stdio.h>
#include "gnl/get_next_line.h"

char **init_map(char **map)
{
	int	i;
	int	fd;

	i = 0;
	map = malloc(sizeof(char *) * 6);
	fd = open("map/map.ber", O_RDONLY);
	map[i] = get_next_line(fd); 
	while(map[i])
	{
		i++;
		map[i] = get_next_line(fd); 
	}
	return(map);
}

int	print_img(t_data img, char *image, int img_width, int img_height)
{
	void	*ptr_mlx;
	void	*win;
	int		i;
	int		index = 0;
	i = 0;
	(void)win;
	ptr_mlx = mlx_init();
	win = mlx_new_window(ptr_mlx, WIDTH, HEIGHT, "windows");
	
	while(img.map[0][i] != '\n')
	{
		img.img = mlx_xpm_file_to_image(ptr_mlx, image, &img_width, &img_height);
		mlx_put_image_to_window(ptr_mlx, win,img.img, index, 0);
		i++;
		index += 50;
	}

	mlx_loop(ptr_mlx);
	return(0);
}

int main(void)
{
	t_data	img;
	int		img_width;
	int		img_height;
	char	*image;

	image = "image/wall.xpm";
	img.map = NULL;
	img_width = 100;
	img_height = 100;
	img.map = init_map(img.map);
	print_img(img, image, img_width, img_height);
}