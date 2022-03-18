/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:27:58 by alukongo          #+#    #+#             */
/*   Updated: 2022/03/18 11:49:29 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include"minilibx/mlx.h"

/**
 * @brief in this fonction i destroy all my image
 * 
 * @param data 
 */
void destroy(t_data *data)
{
	mlx_destroy_image(data->ptr_mlx, data->wall);
	mlx_destroy_image(data->ptr_mlx, data->collect);
	mlx_destroy_image(data->ptr_mlx, data->perso);
	mlx_destroy_image(data->ptr_mlx, data->door);
	mlx_destroy_image(data->ptr_mlx, data->flor);
//	mlx_destroy_display(data->ptr_mlx);
}

