/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:45:05 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/10 15:45:09 by hcorrea-         ###   ########.fr       */
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
		data->map->width = ft_strlen(line) * 50;
		data->map->lines[i] = ft_strdup(line);
		free(line);
		line = get_next_line(data->map->fd);
		i++;
	}
	free(line);
	data->map->height = i * 50;
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	nbr_consumables(t_data *data)
{
	int	i;
	int	j;
	int	nbr_consumables;

	j = -1;
	nbr_consumables = 0;
	while (data->map->lines[++j])
	{
		i = -1;
		while (data->map->lines[j][++i])
		{
			if (data->map->lines[j][i] == 'C')
				nbr_consumables++;
		}
	}
	return (nbr_consumables);
}

void	draw_circle(int x, int y, int color, t_data *data)
{
	int	i;
	int	j;
	int	distance_squared;

	i = x + 50 / 2 - 15;
	while (i <= x + 50 / 2 + 15)
	{
		j = y + 50 / 2 - 15;
		while (j <= y + 50 / 2 + 15)
		{
			distance_squared = (i - (x + 50 / 2)) * (i - (x + 50 / 2))
				+ (j - (y + 50 / 2)) * (j - (y + 50 / 2));
			if (distance_squared <= 15 * 15)
			{
				put_pixel(data, i, j, color);
			}
			j++;
		}
		i++;
	}
}

int	map_sizes(t_data *data)
{
	int	i;
	int	j;
	int	comp_size;

	i = 0;
	comp_size = ft_strlen(data->map->lines[0]);
	comp_size--;
	while (data->map->lines[i])
	{
		j = 0;
		while (data->map->lines[i][j])
			j++;
		if (data->map->lines[i][j - 1] == '\n'
			&& data->map->lines[i][j] == '\0')
			j--;
		if (j != comp_size)
			return (0);
		i++;
	}
	return (1);
}
