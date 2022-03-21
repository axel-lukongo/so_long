/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:24:02 by alukongo          #+#    #+#             */
/*   Updated: 2022/03/21 19:05:04 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH 1200
# define HEIGHT 450
# define KEY_LEFT 97
# define KEY_RIGHT 100
# define KEY_UP 119
# define KEY_DOWN 115
# define ESC 65307
# include <fcntl.h>
# include <stdio.h>
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include"minilibx/mlx.h"

char	**init_map(char **map, char *file);

typedef struct s_data
{
	void	*ptr_mlx;
	void	*win;
	char	**map;
	void	*img;
	void	*perso;
	void	*wall;
	void	*collect;
	void	*door;
	void	*flor;
	void	*win_game;
	int		flag;
}	t_data;
void	print_image(t_data data);
void	init_struct(t_data *data);
void	destroy(t_data *data);
int		move_horizontal(t_data *data, int sign);
int		move_vertical(t_data *data, int sign);
void	open_door(t_data *data);
int		tcheck_char(char **map, char c);
void	win_game(t_data *data);
void	tcheck_map(char **map);
void	name_map(char *file);
void	contour_map(char **map);
void	tcheck_diff(char *map, int width, char c);
void	free_map(t_data *data);
void	close_my_game(t_data *data);
int		mouse_event(t_data *data);
int		key_event(int key, t_data *data);
#endif // !SO_LONG_H