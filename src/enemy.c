/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:02:37 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/11 09:49:38 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	upgrade_pos_render_map_enemy(t_data *data, int x, int y, int i)
{
	data->enemy[i]->pixel_pos.x += x;
	data->enemy[i]->curr_pos.x += x / 50;
	data->enemy[i]->pixel_pos.y += y;
	data->enemy[i]->curr_pos.y += y / 50;
	render_map(data, -1, 0, 0);
}

int	move_enemy(t_data *data)
{
	int				i;
	struct timeval	now;
	int				elapsed_time;

	gettimeofday(&now, NULL);
	elapsed_time = (now.tv_sec - data->enemy[0]->last_movement.tv_sec) * 1000
		+ (now.tv_usec - data->enemy[0]->last_movement.tv_usec) / 1000;
	i = -1;
	if (elapsed_time >= ENEMY_FRAME_RATE || elapsed_time < 0)
	{
		while (++i < nbr_enemies(data))
		{
			rand_nbr_enemy(data, i);
			if (data->enemy[i]->curr_pos.x == data->pacman->curr_pos.x
				&& data->enemy[i]->curr_pos.y == data->pacman->curr_pos.y
				&& data->enemy[i]->print)
			{
				if (data->enemy[i]->state == 0)
				{
					data->nbr_enemies_killed++;
					data->enemy[i]->print = 0;
				}
				else
					die(data);
			}
		}
		data->enemy[0]->last_movement = now;
	}
	return (0);
}

int	is_wall_enemy(t_data *data, int x, int y, int i)
{
	int	pos_y;
	int	pos_x;

	pos_y = data->enemy[i]->curr_pos.y + y;
	pos_x = data->enemy[i]->curr_pos.x + x;
	if (data->map->lines[pos_y][pos_x] == '1')
		return (1);
	else
		return (0);
}

int	nbr_enemies(t_data *data)
{
	int	i;
	int	j;
	int	nbr_enemies;

	j = 0;
	nbr_enemies = 0;
	while (data->map->lines[j])
	{
		i = 0;
		while (data->map->lines[j][i])
		{
			if (data->map->lines[j][i] == 'X')
				nbr_enemies++;
			i++;
		}
		j++;
	}
	return (nbr_enemies);
}
