/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcheck_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:26:23 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/04 16:02:07 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include"minilibx/mlx.h"

/*
int nb_perso(char **map)
{
	int	i;
	int	j;
	int count_p;

	count_p = 0;
	i = 0;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == 'P')
			count_p++;
		j++;
		if (map[i][j] == '\n')
		{
			j = 0;
			i++;
		}
	}
	if (count_p != 1)
		return (0);
	return (1);
}
*/
/**
 * @brief in this fonction i tcheck if i have at least one hero,
           one exit, and one collectable
 * @param map 
 */
void	tcheck_element_map(char **map, t_data *data)
{
	(void) map;
	if (check_char(data, 'E') == 0)
	{
		free_map(data);
		ft_printf("Error\nmust have a exit");
		exit(0);
	}
	if (check_char(data, 'C') == 0)
	{
		free_map(data);
		ft_printf("Error\nmust have collectable");
		exit(0);
	}
	if (check_char(data, 'P') == 0)
	{
		free_map(data);
		ft_printf("Error\nmust have 1 personage");
		exit(0);
	}
}

/**
 * @brief in this fonction i tcheck the border of my map
 * 
 * width this is the lentgh in my first line of my map
 * 
 * @param map this is my map 
 */
void	tcheck_contour_map(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	tcheck_diff(data, map[0], data->col, '1');
	tcheck_diff(data, map[data->row - 2], data->col, '1');
	while (i < data->row - 1)
	{
		if (j == data->col - 1)
		{
			if (map[i][0] != '1' || map[i][j - 1] != '1')
			{
				free_map(data);
				ft_printf("Error\nmap ain't close by a wall");
				exit(1);
			}
			i++;
			j = 0;
		}
		j++;
	}
}

/**
 * @brief in this fonction i tcheck if i the file name finish by .ber else i exit
 * 
 * @param file this is the name of the file where i store my map
 */
void	tcheck_name_map(char *file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (file[i] == '.')
			if (file[i + 1] == 'b')
				if (file[i + 2] == 'e')
					if (file[i + 3] == 'r')
						if (file[i + 4] == '\0')
							return ;
		i++;
	}
	ft_printf("Error\nfile must finish by .ber");
	exit (1);
}
