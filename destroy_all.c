/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:27:58 by alukongo          #+#    #+#             */
/*   Updated: 2022/03/18 16:56:52 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include"minilibx/mlx.h"

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
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		data->map[i] = NULL;
		i++;
	}
	free(data->map);
}
