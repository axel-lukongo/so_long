/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:27:47 by alukongo          #+#    #+#             */
/*   Updated: 2022/03/21 15:57:23 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include"minilibx/mlx.h"

/**
 * @brief this fonction allow me to quit the game when i win,
    whetever the key i press
 * 
 * @param key 
 * @param data 
 * @return int 
 */
int	close_game(int key, t_data *data)
{
	if (key)
	{
		mlx_destroy_window(data->ptr_mlx, data->win);
		exit(1);
	}
	return (1);
}

/**
 * @brief when i won i want to print a image who tell me i won 
 * 
 * @param data 
 */
void	win_game(t_data *data)
{
	int	img_width;
	int	img_height;

	img_width = 5;
	img_height = 5;
	destroy(data);
	mlx_clear_window(data->ptr_mlx, data->win);
	data->win_game = mlx_xpm_file_to_image(data->ptr_mlx,
			"image/win.xpm", &img_width, &img_height);
	mlx_put_image_to_window(data->ptr_mlx, data->win,
		data->win_game, 500, 130);
	mlx_key_hook(data->win, close_game, data);
}
