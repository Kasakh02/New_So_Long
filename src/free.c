/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:45:49 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/10 17:05:28 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	clear_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->lines[i])
	{
		free(data->map->lines[i]);
		i++;
	}
	free(data->map->lines);
	data->map->lines = NULL;
	close(data->map->fd);
	free(data->map);
}

void	clear_pacman(t_data *data)
{
	mlx_destroy_image(data->mlx, data->pacman->img_file[0]);
	mlx_destroy_image(data->mlx, data->pacman->img_file[1]);
	mlx_destroy_image(data->mlx, data->pacman->img_file[2]);
	mlx_destroy_image(data->mlx, data->pacman->img_file[3]);
	mlx_destroy_image(data->mlx, data->pacman->img_file[4]);
	free(data->pacman);
}

void	clear_enemy(t_data *data)
{
	int	i;

	i = 0;
	while (i < nbr_enemies(data))
	{
		mlx_destroy_image(data->mlx, data->enemy[i]->img_file[0]);
		mlx_destroy_image(data->mlx, data->enemy[i]->img_file[1]);
		free(data->enemy[i]);
		i++;
	}
	free(data->enemy);
}

void	clear_consumable_exit(t_data *data)
{
	free(data->consumable);
	free(data->exit);
}

void	clear_all(t_data *data)
{
	clear_pacman(data);
	clear_enemy(data);
	clear_map(data);
	clear_consumable_exit(data);
	free(data);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
}
