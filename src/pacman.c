/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pacman_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:55:13 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/07 15:12:23 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	update_position_and_render_map(t_data *data, int x, int y, int i)
{
	data->pacman->pixel_pos.x += x;
	data->pacman->curr_pos.x += x / 100;
	data->pacman->pixel_pos.y += y;
	data->pacman->curr_pos.y += y / 100;
	if (i != data->pacman->image_index)
		data->pacman->image_index = i;
	render_map(data);
}

int	move_character(int keycode, t_data *data)
{
	if (keycode == 65361 && !is_wall(data, -1, 0))
		update_position_and_render_map(data, -100, 0, 1);
	else if (keycode == 65363 && !is_wall(data, 1, 0))
		update_position_and_render_map(data, 100, 0, 0);
	else if (keycode == 65364 && !is_wall(data, 0, 1))
		update_position_and_render_map(data, 0, 100, 3);
	else if (keycode == 65362 && !is_wall(data, 0, -1))
		update_position_and_render_map(data, 0, -100, 2);
	else
		return (0);
	return (0);
}
