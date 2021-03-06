/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:27:37 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/05 15:37:22 by alukongo         ###   ########.fr       */
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
	if (check_char(data, 'C') == 0)
		data->flag = 1;
	else
		data->flag = 0;
	data->door = mlx_xpm_file_to_image(data->ptr_mlx,
			"image/porte.xpm", &img_width, &img_height);
}

/**
 * @brief in this fonctions i read all the file where my map it is,
 * and i count the number of line, and i will use it for malloc my tab/
 * 
 * @param file this is where my map file it srage
 */
void	count_line(char *file, t_data *data)
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
	free(str);
	close(fd);
	data->row = nb_line + 1;
}

/**
 * @brief this fonction allow me to allocat
 * memory for ma variable map in my struct
 * 
 * @param data 
 * @param file it the file where the map had been write
 * @param fd 
 */
void	allocate_map(t_data *data, char *file, int fd)
{
	if (fd < 0)
	{
		ft_printf("Error\n invalid fd");
		exit(1);
	}
	count_line(file, data);
	data->map = malloc(sizeof(char *) * data->row + 1);
	if (!data->map || data->row < 3)
	{
		free(data->map);
		ft_printf("Error\n verify init_map\n");
		exit(1);
	}
}

/**
 * @brief in this fonction i check the name of my file,
	initialise my map
	and i check the map at the end;
 * 
 * @param map this is the map who i want initialise
 * @return char** i return the map initialized
 */
int	init_map(t_data *data, char *file)
{
	int	i;
	int	fd;

	i = 0;
	check_name_map(file);
	fd = open(file, O_RDONLY);
	allocate_map(data, file, fd);
	while (1)
	{
		data->map[i] = get_next_line(fd);
		if (data->map[i] == NULL)
			break ;
		i++;
	}
	//printf("map = %s", str);
	data->map[i] = NULL;
	check_contour_map(data->map, data);
	check_element_map(data->map, data);
	return (1);
}
