/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:31:46 by alukongo          #+#    #+#             */
/*   Updated: 2022/03/26 02:05:54 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
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
	else if (c == 'D')
		mlx_put_image_to_window(data.ptr_mlx, data.win, data.dragon, x, y);
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

	y = 0;
	j = 0;
	x = 0;
	i = 0;
	while (data.map[i][j] != '\0')
	{
		put_in_window(data, data.map[i][j], x, y);
		j++;
		x += 50;
		if (data.map[i][j] == '\n')
		{
			y += 50;
			x = 0;
			i++;
			j = 0;
		}
	}
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
	init_map(&data, av[1]);
	data.ptr_mlx = mlx_init();
	data.win = mlx_new_window(data.ptr_mlx, data.col*50, data.row*50 , "windows");
	init_struct(&data);
	print_image(data);
	mlx_key_hook(data.win, key_event, &data);
	mlx_hook(data.win, 17, 1L << 17, mouse_event, &data);
	mlx_loop(data.ptr_mlx);
}
