/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:45:05 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/07 16:55:42 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	get_size(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(data->map->fd);
	while (line)
	{
		data->map->width = ft_strlen(line) * 100;
		data->map->lines[i] = ft_strdup(line);
		free(line);
		line = get_next_line(data->map->fd);
		i++;
	}
	free(line);
	data->map->height = i * 100;
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	is_wall(t_data *data, int x, int y)
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

int	nbr_enemies(t_data *data)
{
	int i;
	int j;
	int	nbr_enemies;

	j = -1;
	nbr_enemies = 0;
	while (data->map->lines[++j])
	{
		i = -1;
		while (data->map->lines[j][++i])
		{
			if (data->map->lines[j][i] == 'X')
				nbr_enemies++;
		}
	}
	return(nbr_enemies);
}
