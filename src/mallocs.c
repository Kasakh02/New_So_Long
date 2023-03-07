/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:12:07 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/07 16:56:19 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	enemy_mallocs(t_data *data)
{
	int	i;
	int	size;

	i = 0;
	size = nbr_enemies(data);
	data->enemy = malloc(size * sizeof(t_enemy *));
	if (!data->enemy)
		return ;
	while (i < size)
	{
		data->enemy[i] = malloc(sizeof(t_enemy));
		if (!data->enemy[i])
			return ;
		data->enemy[i]->img_file = malloc(2 * sizeof(void *));
		if (!data->enemy[i]->img_file)
			return ;
		i++;
	}
}

void	pacman_mallocs(t_data *data)
{
	data->pacman = malloc(sizeof(t_pacman));
	data->pacman->img_file = malloc(5 * sizeof(void *));
	enemy_mallocs(data);
	if (!data->pacman || !data->pacman->img_file)
		return ;
}
