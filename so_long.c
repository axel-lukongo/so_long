#include"minilibx/mlx.h"
#include "so_long.h"
#include "gnl/get_next_line.h"
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