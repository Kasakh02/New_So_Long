/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pacman.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:55:13 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/10 16:57:35 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	upgrade_pos_render_map_pacman(t_data *data, int x, int y, int i)
{
	data->pacman->pixel_pos.x += x;
	data->pacman->curr_pos.x += x / 50;
	data->pacman->pixel_pos.y += y;
	data->pacman->curr_pos.y += y / 50;
	if (i != data->pacman->image_index)
		data->pacman->image_index = i;
	render_map(data, -1, 0, 0);
}

int	move_character(int keycode, t_data *data)
{
	int				i;
	int				j;

	i = -1;
	j = -1;
	if (keycode == 97 && !is_wall_pacman(data, -1, 0))
		upgrade_pos_render_map_pacman(data, -50, 0, 1);
	else if (keycode == 100 && !is_wall_pacman(data, 1, 0))
		upgrade_pos_render_map_pacman(data, 50, 0, 0);
	else if (keycode == 115 && !is_wall_pacman(data, 0, 1))
		upgrade_pos_render_map_pacman(data, 0, 50, 3);
	else if (keycode == 119 && !is_wall_pacman(data, 0, -1))
		upgrade_pos_render_map_pacman(data, 0, -50, 2);
	else
		return (0);
	nbr_enemies_consumables(data, i, j);
	if (data->pacman->curr_pos.x == data->exit->curr_pos.x
		&& data->pacman->curr_pos.y == data->exit->curr_pos.y
		&& data->pacman->nbr_consumables == nbr_consumables(data))
		win(data);
	return (0);
}

int	is_wall_pacman(t_data *data, int x, int y)
{
	int	pos_y;
	int	pos_x;

	pos_y = data->pacman->curr_pos.y + y;
	pos_x = data->pacman->curr_pos.x + x;
	if (data->map->lines[pos_y][pos_x] == '1')
		return (1);
	else
		return (0);
}
