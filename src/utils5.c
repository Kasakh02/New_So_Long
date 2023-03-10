/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:15:40 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/10 14:07:06 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	pacman_gif_utils(t_data *data, int elapsed_time, struct timeval now)
{
	if (elapsed_time >= GIF_RATE || elapsed_time < 0)
	{
		enemy_gif(data, 1);
		pacman_gif(data, 1);
		data->pacman->last_gif = now;
	}
	else
	{
		enemy_gif(data, 0);
		pacman_gif(data, 0);
	}
}

char	**array_dup(char **array)
{
	char	**new;
	int		i;

	i = 0;
	while (array[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	if (!new)
		return NULL;
	i = 0;
	while (array[i])
	{
		new[i] = ft_strdup(array[i]);
		i++;
	}
	new[i] = 0;
	return (new);
}

int	can_p(char **lines, int x, int y, int dir)
{
	char	**map_dup;

	if (dir == 0)
	{
		map_dup = array_dup(lines);
		dir = can_p(map_dup, x, y, 5);
		return (dir);
	}
	if (x < 0 || y < 0 || !lines[x][y] || lines[x][y] == '1')
		return (0);
	if (lines[x][y] == 'P')
		return (1);
	lines[x][y] = '1';
	if (dir != 2 && can_p(lines, x, y + 1, 1))
		return (1);
	if (dir != 1 && can_p(lines, x, y - 1, 2))
		return (1);
	if (dir != 4 && can_p(lines, x + 1, y, 3))
		return (1);
	if (dir != 3 && can_p(lines, x - 1, y, 4))
		return (1);
	return (0);
}

int	valid_path(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->lines[i])
	{
		j = 0;
		while (data->map->lines[i][j])
		{
			if ((data->map->lines[i][j] == 'C' || data->map->lines[i][j] == 'E')
				&& !can_p(data->map->lines, i, j, 0))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
