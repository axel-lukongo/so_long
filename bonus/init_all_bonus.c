/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:27:37 by alukongo          #+#    #+#             */
/*   Updated: 2022/04/04 21:56:32 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

int	g_img_width;
int	g_img_height;

/**
 * @brief i initialize all my variable in my structure
 * 
 * @param data this is my strcuture
 */
void	init_struct(t_data *data)
{
	g_img_width = 5;
	g_img_height = 5;
	data->dragon = mlx_xpm_file_to_image(data->ptr_mlx,
			"bonus/image_bonus/dragon.xpm", &g_img_width, &g_img_height);
	data->perso = mlx_xpm_file_to_image(data->ptr_mlx,
			"bonus/image_bonus/hero_fly.xpm", &g_img_width, &g_img_height);
	data->wall = mlx_xpm_file_to_image(data->ptr_mlx,
			"bonus/image_bonus/wall.xpm", &g_img_width, &g_img_height);
	data->collect = mlx_xpm_file_to_image(data->ptr_mlx,
			"bonus/image_bonus/cristaux.xpm", &g_img_width, &g_img_height);
	data->flor = mlx_xpm_file_to_image(data->ptr_mlx,
			"bonus/image_bonus/terre.xpm", &g_img_width, &g_img_height);
	if (check_char(data, 'C') == 0)
	{
		data->door = mlx_xpm_file_to_image(data->ptr_mlx,
				"bonus/image_bonus/door_open.xpm", &g_img_width, &g_img_height);
		data->flag = 1;
	}
	else
	{
		data->door = mlx_xpm_file_to_image(data->ptr_mlx,
				"bonus/image_bonus/porte.xpm", &g_img_width, &g_img_height);
		data->flag = 0;
	}
}

/**
 * @brief in this fonctions i read all the file where my map it is,
 * and i count the number of line, and i will use it for malloc my tab
 * 
 * @param file this is where my map file it storage
 * @return int 
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
 * @brief this fonction allow me to allocat memory
 * for ma variable map in my struct
 * 
 * @param data 
 * @param file it the file where the map had been write
 * @param fd 
 */
void	allocate_map(t_data *data, char *file, int fd)
{
	count_line(file, data);
	data->map = malloc(sizeof(char *) * data->row + 1);
	if (!data->map || fd < 0)
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
 * @return char** i return the my map
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
	data->map[i] = NULL;
	
	check_contour_map(data->map, data);
	check_element_map(data->map, data);
	return (1);
}