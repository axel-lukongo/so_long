/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:31:46 by alukongo          #+#    #+#             */
/*   Updated: 2022/03/14 15:20:52 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"minilibx/mlx.h"
#include "so_long.h"
#include "gnl/get_next_line.h"
#include<stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	nbr = (unsigned int)nb;
	if (nbr <= 9)
		ft_putchar(nbr + '0');
	if (nbr >= 10)
	{
		ft_putnbr (nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
}


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
	int	y = 100;
	int			x;
	int			i;
	int			j;

	j = 0;
	x = 150;
	i = 0;
	while (data.map[i][j] != '\0')
	{
		if (data.map[i][j] == '1')
			mlx_put_image_to_window(data.ptr_mlx, data.win, data.wall, x, y);
		else if (data.map[i][j] == '0')
				mlx_put_image_to_window(data.ptr_mlx, data.win, data.flor, x, y);
		else if (data.map[i][j] == 'p')
			mlx_put_image_to_window(data.ptr_mlx, data.win, data.perso, x, y);
		else if (data.map[i][j] == 'c')
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
 * @brief this fonction allow me to send my map line by line
  to the fonction print_map
 * @param data this strctur contain the element who i gone use during all my project,
  line the pointer to the mlx, the pointer to my window...
 * @param img_width this is the width of my image
 * @param img_height this is the height of my image
 * @param the variable i is juste a index for browse my map line by line
 */
void	send_line_map(t_data data)
{
	print_image(data);
}

int	deal_key(int key, t_data *data)
{
	int x = 0;
	int y = 0;
	if (key == KEY_RIGHT)
	{
		while (data->map[x][y] != '\0')
		{
			if(data->map[x][y] == 'p')
			{
				if(data->map[x][y + 1] != '1')
				{
					data->map[x][y + 1] = 'p';
					data->map[x][y] = '0';
				}
				break;
			}
			if(data->map[x][y] == '\n')
			{
				x++;
				y = 0;
			}
			y++;
		}
		destroy(data);
		init_struct(data);
		send_line_map(*data);
	}
	return (0);
}

int main(void)
{
	t_data	data;
	data.map = NULL;

	data.map = init_map(data.map);
	init_struct(&data);
	print_image(data);
	mlx_key_hook(data.win, deal_key, &data);
	mlx_loop(data.ptr_mlx);
}
