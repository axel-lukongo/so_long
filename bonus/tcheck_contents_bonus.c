/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:05:44 by alukongo          #+#    #+#             */
/*   Updated: 2022/03/26 02:06:01 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"
/**
 * @brief i tcheck if i have the char in my variable c in my map
 * 
 * @param map 
 * @param c the char who i want look in my map
 * @return int 
 */
int	tcheck_char(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == c)
			return (1);
		j++;
		if (map[i][j] == '\n')
		{
			j = 0;
			i++;
		}
	}
	return (0);
}

void	tcheck_diff(char *map, int width, char c)
{
	int	i;

	i = 0;
	while (i < width - 1)
	{
		if (map[i] != c)
		{
			ft_printf("Error\nwall ain't close by a wall");
			exit (0);
		}
		i++;
	}
}
