/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gif.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:12:06 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/07 15:56:07 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	pacman_gif(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pacman->pixel_pos.x;
	pos_y = data->pacman->pixel_pos.y;
	data->pacman->mouth_open = !data->pacman->mouth_open;
	if (data->pacman->mouth_open)
		mlx_put_image_to_window(data->mlx, data->win,
			data->pacman->img_file[data->pacman->image_index], pos_x, pos_y);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->pacman->img_file[4], pos_x, pos_y);
}

void	enemy_gif(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->enemy[0]->pixel_pos.x;
	pos_y = data->enemy[0]->pixel_pos.y;
	data->enemy[0]->mouth_open = !data->enemy[0]->mouth_open;
	if (data->enemy[0]->mouth_open)
		mlx_put_image_to_window(data->mlx, data->win,
			data->enemy[0]->img_file[0], pos_x, pos_y);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->enemy[0]->img_file[1], pos_x, pos_y);
}

int	gif(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	enemy_gif(data);
	pacman_gif(data);
	usleep(100000);
	return (0);
}
