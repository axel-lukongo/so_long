/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:27:58 by alukongo          #+#    #+#             */
/*   Updated: 2022/03/26 02:06:47 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

/**
 * @brief in this fonction i destroy all my image
 * 
 * @param data 
 */
void	destroy(t_data *data)
{
	mlx_destroy_image(data->ptr_mlx, data->wall);
	mlx_destroy_image(data->ptr_mlx, data->collect);
	mlx_destroy_image(data->ptr_mlx, data->perso);
	mlx_destroy_image(data->ptr_mlx, data->door);
	mlx_destroy_image(data->ptr_mlx, data->flor);
	mlx_destroy_image(data->ptr_mlx, data->dragon);
}

void	close_my_game(t_data *data)
{
	free_map(data);
	destroy(data);
	mlx_clear_window(data->ptr_mlx, data->win);
	mlx_destroy_window(data->ptr_mlx, data->win);
	mlx_destroy_display(data->ptr_mlx);
	free(data->ptr_mlx);
	exit(1);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}
