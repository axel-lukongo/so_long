#include"so_long.h"
#include"minilibx/mlx.h"

void	win_game(t_data *data)
{
	//ft_putnbr(collect(data->map, 'p'));
	int	img_width;
	int	img_height;

	img_width = 5;
	img_height = 5;
	if (tcheck_char(data->map, 'E') == 0)
	{
		destroy(data);
		mlx_clear_window(data->ptr_mlx, data->win);
		data->win_game = mlx_xpm_file_to_image(data->ptr_mlx,
		"image/win.xpm", &img_width, &img_height);
		mlx_put_image_to_window(data->ptr_mlx, data->win, data->win_game, 500, 130);
	}
}