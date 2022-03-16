/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:27:25 by alukongo          #+#    #+#             */
/*   Updated: 2022/03/16 12:27:28 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include"minilibx/mlx.h"

int	move_horizontal(t_data *data, int n)
{
	int x;
	int y;

	x = 0;
	y = -1;
	while (data->map[x][++y] != '\0')
		{
			if (data->map[x][y] == 'P')
			{
				if (data->map[x][y + (1 * n)] != '1')
				{
					data->map[x][y + (1 * n)] = 'P';
					data->map[x][y] = '0';
					destroy(data);
					init_struct(data);
					print_image(*data);
					return (1);
				}
			}
			if (data->map[x][y] == '\n')
			{
				x++;
				y = 0;
			}
		}
		return (0);
}

int	move_vertical(t_data *data, int n)
{
	int	x;
	int	y;

	x = 0;
	y = -1;
	while (data->map[x][++y] != '\0')
		{
			if (data->map[x][y] == 'P')
			{
				if (data->map[x + (1 * n)][y] != '1')
				{
					data->map[x + (1 * n)][y] = 'P';
					data->map[x][y] = '0';
					destroy(data);
					init_struct(data);
					print_image(*data);
					return (1);
				}
			}
			if (data->map[x][y] == '\n')
			{
				x++;
				y = 0;
			}
		}
		return (0);
}