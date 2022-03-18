/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:27:25 by alukongo          #+#    #+#             */
/*   Updated: 2022/03/18 16:24:36 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include"minilibx/mlx.h"

/**
 * @brief here i move my hero on the left or right,
    and according to the key what i press
 * 
 * @param data my strcuture 
 * @param n this the variable who allow me to increment or decrease the y
 * @return int 
 */
int	move_horizontal(t_data *data, int n)
{
	int	x;
	int	y;

	x = 0;
	y = -1;
	while (data->map[x][++y] != '\0')
	{
		if (data->map[x][y] == 'P')
		{
			if (data->map[x][y + n] == '0' || data->map[x][y + n] == 'C')
			{
				data->map[x][y + n] = 'P';
				data->map[x][y] = '0';
				destroy(data);
				init_struct(data);
				print_image(*data);
				return (1);
			}
			if (data->map[x][y + n] == 'E' && data->flag == 1)
				win_game(data);
		}
		if (data->map[x][y] == '\n')
		{
			x++;
			y = 0;
		}
	}
	return (0);
}


//void move(t_data *data, int x, int y, int n)
//{
	
//}

/**
 * @brief here i move my hero on the left or right,
   and according to the key what i press
 * 
 * @param data my strcuture 
 * @param n this the variable who allow me to increment or decrease the x
 * @return int 
 */
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
			if (data->map[x + n][y] == '0' || data->map[x + n][y] == 'C')
			{
					data->map[x + n][y] = 'P';
					data->map[x][y] = '0';
					destroy(data);
					init_struct(data);
					print_image(*data);
					return (1);
			}
			if (data->map[x + n][y] == 'E' && data->flag == 1)
				win_game(data);
		}
		if (data->map[x][y] == '\n')
		{
			x++;
			y = 0;
		}
	}
	return (0);
}
