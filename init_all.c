/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:27:37 by alukongo          #+#    #+#             */
/*   Updated: 2022/03/23 16:55:23 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include"minilibx/mlx.h"

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
int	count_line(char *file, t_data *data)
{
	int		fd;
	int		nb_line;
	char	*str;

	nb_line = 0;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	data->col = ft_strlen(str);
	while (str)
	{
		nb_line++;
		free(str);
		str = get_next_line(fd);
	}
		//free(str);
	
	close(fd);
	data->row = nb_line;
	return (nb_line + 1);
}

/**
 * @brief in this fonction i tcheck the name of my file,
	initialise my map
	and i tcheck the map at the end;
 * 
 * @param map this is the map who i want initialise
 * @return char** i return the my map
 */

int	init_map(t_data *data,char *fichier)
{
	int	i;
	int	fd;
	int	nb_line;

	i = 0;
	nb_line = count_line(fichier, data);
	tcheck_name_map(fichier);
	fd = open(fichier, O_RDONLY);
	data->map = malloc(sizeof(char *) * nb_line + 1);
	if (!data->map || fd < 0)
	{
		ft_printf("Error\n verify init_map\n");
		exit(1);
	}
	data->map[i] = get_next_line(fd);
	while (data->map[i])
	{
		i++;
		data->map[i] = get_next_line(fd);
	}
	tcheck_element_map(data->map);
	tcheck_contour_map(data->map);
	return (1);
}
