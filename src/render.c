/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:49:24 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/07 17:04:11 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void draw_square(int x, int y, int color, t_data *data)
{
	int i;
	int j;

	i = 0;
	if (x + 100 > data->map->width || y + 100 > data->map->height)
		return;
	while (i < 100)
	{
		j = 0;
		while (j < 100)
		{
			put_pixel(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void render_pacman(t_data *data, int i, int j)
{
	data->pacman->pixel_pos.x = i * 100;
	data->pacman->pixel_pos.y = j * 100;
	data->pacman->curr_pos.x = i;
	data->pacman->curr_pos.y = j;
	data->pacman->flag = 1;
}

void render_enemy(t_data *data, int x, int y)
{
	int	i;

	while (data->enemy)
	{
		data->enemy[i]->pixel_pos.x = x * 100;
		data->enemy[i]->pixel_pos.y = y * 100;
		data->enemy[i]->curr_pos.x = x;
		data->enemy[i]->curr_pos.y = y;
		data->enemy[i]->flag = 1;
		i++;
	}
}

void render_map(t_data *data)
{
	int i;
	int j;
	int	k;

	j = -1;
	k = 0;
	while (data->map->lines[++j])
	{
		i = -1;
		while (data->map->lines[j][++i])
		{
			if (data->map->lines[j][i] == '1')
				draw_square(i * 100, j * 100, RED_PIXEL, data);
			else
				draw_square(i * 100, j * 100, BLACK_PIXEL, data);
			if (data->map->lines[j][i] == 'P' && data->pacman->flag != 1)
				render_pacman(data, i, j);
			if (data->map->lines[j][i] == 'X' && data->enemy[k]->flag != 1)
			{
				printf("enemy 0 = %p\nenemy flag = %i\n", data->enemy[k], data->enemy[k]->flag);
				render_enemy(data, i, j);
				k++;
			}
		}
	}
}
