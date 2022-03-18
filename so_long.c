/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:31:46 by alukongo          #+#    #+#             */
/*   Updated: 2022/03/18 11:26:07 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"minilibx/mlx.h"
#include "so_long.h"
#include "gnl/get_next_line.h"
#include<stdio.h>

/**
 * @brief this fonction allow me to put image in the window,
   while i don't find the '\n' or '\0', i check if the value in my map = 1 or 0.
   if is 1 i print a wall else i print the flor and i step in next case of map.
 * @param map: is a line of my map
 * @param data: this strctur contain the element who i gone use during all my project,
  line the pointer to the mlx, the pointer to my window...
 * @param img_width this is the width of my image
 * @param img_height this is the height of my image
 * @param x and y is the position where i start to print in my window.
 */
 
void	print_image(t_data data)
{
	int	y;
	int	x;
	int	i;
	int	j;

	y = 100;
	j = 0;
	x = 150;
	i = 0;
	while (data.map[i][j] != '\0')
	{
		if (data.map[i][j] == '1')
			mlx_put_image_to_window(data.ptr_mlx, data.win, data.wall, x, y);
		else if (data.map[i][j] == '0')
			mlx_put_image_to_window(data.ptr_mlx, data.win, data.flor, x, y);
		else if (data.map[i][j] == 'P')
			mlx_put_image_to_window(data.ptr_mlx, data.win, data.perso, x, y);
		else if (data.map[i][j] == 'C')
			mlx_put_image_to_window(data.ptr_mlx, data.win, data.collect, x, y);		
		else if (data.map[i][j] == 'E')
			mlx_put_image_to_window(data.ptr_mlx, data.win, data.door, x, y);
		j++;
		x += 50;
		if(data.map[i][j] == '\n')
		{
			y += 50;
			x = 150;
			i++;
			j = 0;
		}
	}
}
/**
 * @brief this fonctions allow me to make a event according to the key what i press
 * 
 * @param key this is the value of my key, ex: w = 100, s = 119...
 * @param data it my struct 
 * @return int 
 */
int	deal_key(int key, t_data *data)
{
	static int i = 0;

	if (key == KEY_RIGHT)
		i += move_horizontal(data, 1);
	else if (key == KEY_LEFT)
		i += move_horizontal(data, -1);
	else if (key == KEY_UP)
		i += move_vertical(data, -1);
	else if (key == KEY_DOWN)
		i += move_vertical(data, 1);
	else if (key == ESC)
	{
		destroy(data);
		mlx_destroy_display(data->ptr_mlx);
		mlx_destroy_window(data->ptr_mlx, data->win);
	}
	ft_printf("%d\n", i);
	win_game(data);
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("give me a map");
		return (0);
	}
	t_data	data;
	data.map = NULL;
	data.ptr_mlx = mlx_init();
	data.win = mlx_new_window(data.ptr_mlx, WIDTH, HEIGHT, "windows");
	data.map = init_map(data.map, av[1]);
	init_struct(&data);
	print_image(data);
	mlx_key_hook(data.win, deal_key, &data);
	mlx_loop(data.ptr_mlx);
}
