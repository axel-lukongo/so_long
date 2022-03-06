#include"minilibx/mlx.h"
#include "so_long.h"
#include<stdio.h>
typedef struct s_data
{
	void 	*img;
	int 	*addrs;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

/*void my_pixel_put(t_data *data_pixel, int x, int y, int color)
{
	char *pxl;

	pxl = data_pixel->addrs + (y * data_pixel->line_length + x *(data_pixel->bits_per_pixel / 8));
	*(unsigned int*)pxl = color;
}*/

int	main(void)
{
	void	*ptr_mlx;
	void	*win;
	int		count_h = -1;
	int		count_w;
	int		y = 0;
	int		colors = 0xff0000;
	t_data	img;

	//(void)win;
	ptr_mlx = mlx_init();
	img.img = mlx_new_image(ptr_mlx, WIDTH, HEIGHT);
	win = mlx_new_window(ptr_mlx, WIDTH, HEIGHT, "windows");
	img.addrs = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (++count_h < 350)
	{
		count_w = 0;
		while(++count_w < y)
			img.addrs[count_h * WIDTH + count_w] = colors += 1000;
		y += 1;
	}
	mlx_put_image_to_window(ptr_mlx, win,img.img, 100, 100);
	mlx_loop(ptr_mlx);
	return(0);
}