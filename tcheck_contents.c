/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcheck_contents.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:05:44 by alukongo          #+#    #+#             */
/*   Updated: 2022/03/28 17:30:22 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include"minilibx/mlx.h"
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
	if (map)
	{
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
	}
	return (0);
}

/**
 * @brief in this fonction function i tcheck if the 
    line have the same length than the first line
 * 
 * @param map 
 * @param length is the length of my map
 * @param c 
 */
void	tcheck_diff(char *map, int length, char c)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (map[i] != c)
		{
			ft_printf("Error\n you forgot a component in map");
			exit (0);
		}
		i++;
	}
}
