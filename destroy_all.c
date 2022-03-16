#include"so_long.h"
#include"minilibx/mlx.h"

void destroy(t_data *data)
{
	mlx_destroy_image(data->ptr_mlx, data->wall);
	mlx_destroy_image(data->ptr_mlx, data->collect);
	mlx_destroy_image(data->ptr_mlx, data->perso);
	mlx_destroy_image(data->ptr_mlx, data->door);
	mlx_destroy_image(data->ptr_mlx, data->flor);
//	mlx_destroy_display(data->ptr_mlx);
}

