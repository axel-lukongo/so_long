#include"minilibx/mlx.h"
#include "so_long.h"
#include "gnl/get_next_line.h"
#include<stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}



void	ft_putnbr(int nb)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	nbr = (unsigned int)nb;
	if (nbr <= 9)
		ft_putchar(nbr + '0');
	if (nbr >= 10)
	{
		ft_putnbr (nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
}
int deal_key(int key, void *param)
{
	(void) param;
	ft_putnbr(key);
	return(0);
}
/**
 * @brief this fonction allow me to put image in the window,
   while i don't find the '\n' or '\0', i check if the value in my map = 1 or 0.
   if is 1 i print a wall else i print the flor and i step in next case of map.
 * @param map: is a line of my map
 * @param data: this strctur contain the element who i gone use during all my project,
  line the pointer to the mlx, the pointer to my window...
 * @param img_width this is the width of my image
 * @param img_height this is the height of my image
 * @param x and y is the position where i start to print in my window.
 */

void print_image(char *map, t_data data, int img_width, int img_height)
{
	static int y = 100;
	int x;
	int i;

	x = 150;
	i = 0;
	while(map[i] != '\n' && map[i] != '\0')
	{
		if(map[i] == '1')
			data.img = mlx_xpm_file_to_image(data.ptr_mlx, "image/wall.xpm", &img_width, &img_height);
		else if (map[i] == '0')
			data.img = mlx_xpm_file_to_image(data.ptr_mlx, "image/terre.xpm", &img_width, &img_height);
		else if (map[i] == 'p')
			data.img = mlx_xpm_file_to_image(data.ptr_mlx, "image/hero_fly.xpm", &img_width, &img_height);
		else if (map[i] == 'c')
			data.img = mlx_xpm_file_to_image(data.ptr_mlx, "image/cristaux.xpm", &img_width, &img_height);
		else if (map[i] == 'E')
			data.img = mlx_xpm_file_to_image(data.ptr_mlx, "image/porte.xpm", &img_width, &img_height);
		mlx_put_image_to_window(data.ptr_mlx, data.win, data.img, x, y);
		i++;
		x += 50;
	}
	y += 50;
}


/**
 * @brief this fonction allow me to send my map line by line
  to the fonction print_map
 * @param data this strctur contain the element who i gone use during all my project,
  line the pointer to the mlx, the pointer to my window...
 * @param img_width this is the width of my image
 * @param img_height this is the height of my image
 * @param the variable i is juste a index for browse my map line by line
 */
void	send_line_map(t_data data, int img_width, int img_height)
{
	int	i;

	i = 0;
	data.ptr_mlx = mlx_init();
	data.win = mlx_new_window(data.ptr_mlx, WIDTH, HEIGHT, "windows");
	while(data.map[i])
	{
		print_image(data.map[i], data, img_width, img_height);
		i++;
	}
	mlx_key_hook(data.win, deal_key, (void *)0);
	mlx_loop(data.ptr_mlx);
}

int main(void)
{
	t_data	img;
	int		img_width;
	int		img_height;
	img.map = NULL;
	img_width = 5;
	img_height = 5;
	img.map = init_map(img.map);
	send_line_map(img, img_width, img_height);
}

/*
typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	ft_close(int keycode, t_vars *vars)
{
	(void) keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
	//mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
	mlx_key_hook(vars.win, deal_key, (void *)0);
	mlx_loop(vars.mlx);
}
*/