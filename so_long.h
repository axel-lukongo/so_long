/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:24:02 by alukongo          #+#    #+#             */
/*   Updated: 2022/03/28 13:10:57 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH 1300
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

typedef struct s_data
{
	void	*ptr_mlx;
	void	*win;
	char	**map;
	void	*perso;
	void	*wall;
	void	*collect;
	void	*door;
	void	*flor;
	void	*win_game;
	int		flag;
	int		row;
	int		col;
}	t_data;
int		init_map(t_data *data, char *file);
void	print_image(t_data data);
void	init_struct(t_data *data);
void	destroy(t_data *data);
int		move_horizontal(t_data *data, int sign);
int		move_vertical(t_data *data, int sign);
void	open_door(t_data *data);
int		tcheck_char(char **map, char c);
void	win_game(t_data *data);
void	tcheck_element_map(char **map, t_data *data);
void	tcheck_name_map(char *file);
void	tcheck_contour_map(char **map, t_data *data);
void	tcheck_diff(char *map, int length, char c);
void	free_map(t_data *data);
void	close_my_game(t_data *data);
int		mouse_event(t_data *data);
int		key_event(int key, t_data *data);
void	error_contents(t_data *data);
#endif // !SO_LONG_H