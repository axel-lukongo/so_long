/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:27:37 by alukongo          #+#    #+#             */
/*   Updated: 2022/03/22 02:02:30 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
//#include"minilibx/mlx.h"

/**
 * @brief i initialize all my variable in my structure
 * 
 * @param data this is my strcuture
 */
void	init_struct(t_data *data)
{
	int		img_width;
	int		img_height;

	img_width = 5;
	img_height = 5;
	data->perso = mlx_xpm_file_to_image(data->ptr_mlx,
			"image/hero_fly.xpm", &img_width, &img_height);
	data->wall = mlx_xpm_file_to_image(data->ptr_mlx,
			"image/wall.xpm", &img_width, &img_height);
	data->collect = mlx_xpm_file_to_image(data->ptr_mlx,
			"image/cristaux.xpm", &img_width, &img_height);
	data->flor = mlx_xpm_file_to_image(data->ptr_mlx,
			"image/terre.xpm", &img_width, &img_height);
	if (tcheck_char(data->map, 'C') == 0)
	{
		data->door = mlx_xpm_file_to_image(data->ptr_mlx,
				"image/door_open.xpm", &img_width, &img_height);
		data->flag = 1;
	}
	else
	data->door = mlx_xpm_file_to_image(data->ptr_mlx,
				"image/porte.xpm", &img_width, &img_height);
}

/**
 * @brief in this fonctions i read the file where my map he is, and i count the 
   number of line, and i will use it for malloc my tab
 * 
 * @param file this is where my map file it storage
 * @return int 
 */
int	count_line(char *file)
{
	int		fd;
	int		nb_line;
	char	*str;

	nb_line = 0;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		nb_line++;
		str = get_next_line(fd);
	}
	close(fd);
	return (nb_line);
}

/**
 * @brief in this fonction i initialise my map
 * 
 * @param map this is the map who i want initialise
 * @return char** i return the my map
 */
char	**init_map(char **map, char *fichier)
{
	int	i;
	int	fd;
	int	nb_line;

	nb_line = count_line(fichier);
	name_map(fichier);
	i = 0;
	map = malloc(sizeof(char *) * nb_line);
	fd = open("map/map.ber", O_RDONLY);
	map[i] = get_next_line(fd);
	while (map[i])
	{
		i++;
		map[i] = get_next_line(fd);
	}
	tcheck_map(map);
	contour_map(map);
	return (map);
}
