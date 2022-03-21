/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:31:46 by alukongo          #+#    #+#             */
/*   Updated: 2022/03/21 18:39:06 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minilibx/mlx.h"
#include "so_long.h"
#include "gnl/get_next_line.h"
#include<stdio.h>

/**
 * @brief in this fonction i put image to the window depending to the char in c
 * 
 * @param data 
 * @param c 
 * @param x the position in 
 * @param y 
 */
void	put_in_window(t_data data, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(data.ptr_mlx, data.win, data.wall, x, y);
	else if (c == '0')
		mlx_put_image_to_window(data.ptr_mlx, data.win, data.flor, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(data.ptr_mlx, data.win, data.perso, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(data.ptr_mlx, data.win, data.collect, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(data.ptr_mlx, data.win, data.door, x, y);
}

/**
 * @brief this fonction allow me to put image in the window. base in my map.
   i check if the value in the case of my map.
   if is 1 i print a wall 0 it the flor and...
 *
 * @param map: is my map
 * @param data: this structur contain the element of my project:
  the pointer to the mlx, the pointer to my window...
  
 * @param x and y is the position where i print image in my window.
 */
void	print_image(t_data data)
{
	int	y;
	int	x;
	int	i;
	int	j;

	y = 20;
	j = 0;
	x = 20;
	i = 0;
	while (data.map[i][j] != '\0')
	{
		put_in_window(data, data.map[i][j], x, y);
		j++;
		x += 50;
		if (data.map[i][j] == '\n')
		{
			y += 50;
			x = 20;
			i++;
			j = 0;
		}
	}
}

/**
 * @brief this fonctions allow me to make a event according to
    the key what i press
 * 
 * @param key this is the value of my key, ex: w = 100, s = 119...
 * @param data it my struct 
 * @return int 
 */
int	deal_key(int key, t_data *data)
{
	if (key == KEY_RIGHT)
		move_horizontal(data, 1);
	else if (key == KEY_LEFT)
		move_horizontal(data, -1);
	else if (key == KEY_UP)
		move_vertical(data, -1);
	else if (key == KEY_DOWN)
		move_vertical(data, 1);
	else if (key == ESC)
	{
		close_my_game(data);
	}
	return (0);
}

int	mouse_event(t_data *data)
{
	close_my_game(data);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		ft_printf("Error\ngive me a map");
		return (0);
	}
	data.map = NULL;
	data.ptr_mlx = mlx_init();
	data.win = mlx_new_window(data.ptr_mlx, WIDTH, HEIGHT, "windows");
	data.map = init_map(data.map, av[1]);
	init_struct(&data);
	print_image(data);
	mlx_key_hook(data.win, deal_key, &data);
	mlx_hook(data.win, 17, 1L << 17, mouse_event, &data);
	mlx_loop(data.ptr_mlx);
}
