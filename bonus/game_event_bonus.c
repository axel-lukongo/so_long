/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:05:50 by alukongo          #+#    #+#             */
/*   Updated: 2022/03/26 02:06:35 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"
/**
 * @brief this fonctions allow me to make a event according to
    the key what i press
 * 
 * @param key this is the value of my key, ex: w = 100, s = 119...
 * @param data it my struct 
 * @return int 
*/
int	key_event(int key, t_data *data)
{
	if (key == KEY_RIGHT)
		move_horizontal(data, 1);
	else if (key == KEY_LEFT)
		move_horizontal(data, -1);
	else if (key == KEY_UP)
		move_vertical(data, -1);
	else if (key == KEY_DOWN)
		move_vertical(data, 1);
	else if (key == ESC)
		close_my_game(data);
	return (0);
}

/**
 * @brief this fonction it for close my window with the cross properly
 * 
 * @param data 
 * @return int 
 */
int	mouse_event(t_data *data)
{
	close_my_game(data);
	return (1);
}
