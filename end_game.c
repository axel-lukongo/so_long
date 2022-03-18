/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:27:47 by alukongo          #+#    #+#             */
/*   Updated: 2022/03/18 14:06:41 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include"minilibx/mlx.h"

/**
 * @brief when i win i want to print a win image 
 * 
 * @param data 
 */
void	win_game(t_data *data)
{
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
		mlx_put_image_to_window(data->ptr_mlx, data->win,
			data->win_game, 500, 130);
	}
}
