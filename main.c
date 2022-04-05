/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:31:46 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/05 14:02:47 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include<stdio.h>

/**
 * @brief in this fonction i put image to the window depending to the char in c
 *
 * @param data 
 * @param c 
 * @param x the position in abcisse
 * @param y the position in ordinate
 */
void	put_in_window(t_data data, char c, int x, int y)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
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
		return ;
	}
	if (c != '\n' && c != '\0')
	{
		ft_printf("Error\n other character detected");
		close_my_game(&data);
	}
}

/**
 * @brief this fonction allow me to put image in the window. base in my map.
   i check if the value in the case of my map.
   if is 1 i print a wall 0 it the flor and...
 *
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
	while (i < data.row - 1)
	{
		put_in_window(data, data.map[i][j], x, y);
		j++;
		x += 50;
		if (j == data.col)
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
	data.win = mlx_new_window(data.ptr_mlx,
			data.col * 50, data.row * 50, "windows");
	init_struct(&data);
	print_image(data);
	mlx_key_hook(data.win, key_event, &data);
	mlx_hook(data.win, 17, 1L << 17, mouse_event, &data);
	mlx_loop(data.ptr_mlx);
}
