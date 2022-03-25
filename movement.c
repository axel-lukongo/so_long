/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:27:25 by alukongo          #+#    #+#             */
/*   Updated: 2022/03/25 21:52:15 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include"minilibx/mlx.h"

static int	g_count = 0;

/**
 * @brief in this fonction i shift the personnage in horizontal sens
 * 
 * @param data this this structur
 * @param x my abcisse
 * @param y my hordinate
 * @param n i use this variable for move forward or rearward, it can be 1 or -1
 */
void	shift_horizontal(t_data *data, int x, int y, int n)
{
	if (data->map[x][y + n] == '0' || data->map[x][y + n] == 'C')
	{
		data->map[x][y + n] = 'P';
		data->map[x][y] = '0';
		destroy(data);
		init_struct(data);
		print_image(*data);
		g_count += 1;
		ft_printf("%d\n", g_count);
	}
	if (data->map[x][y + n] == 'E' && data->flag == 1)
		win_game(data);
}

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
			shift_horizontal(data, x, y, n);
			return (1);
		}
		if (data->map[x][y] == '\n')
		{
			x++;
			y = 0;
		}
	}
	return (0);
}

/**
 * @brief in this fonction i shift the personnage in vertcial  
 * 
 * @param data it my structur
 * @param x my abcisse
 * @param y my ordinate
 * @param n allow me to move on the top or down, it can be equal 1 or -1
 */
void	shift_vertical(t_data *data, int x, int y, int n)
{
	if (data->map[x + n][y] == '0' || data->map[x + n][y] == 'C')
	{
		data->map[x + n][y] = 'P';
		data->map[x][y] = '0';
		destroy(data);
		init_struct(data);
		print_image(*data);
		g_count += 1;
		ft_printf("%d\n", g_count);
	}
	if (data->map[x + n][y] == 'E' && data->flag == 1)
		win_game(data);
}

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
			shift_vertical(data, x, y, n);
			return (1);
		}
		if (data->map[x][y] == '\n')
		{
			x++;
			y = 0;
		}
	}
	return (0);
}
