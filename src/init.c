/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:24:49 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/07 16:56:55 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_images_pacman(t_data *data, int width, int height)
{
	char	**imgs;
	int		i;

	i = 0;
	imgs = malloc(5 * sizeof(char *));
	imgs[0] = "/nfs/homes/hcorrea-/Documents/"
		"42_Projects/So_Long/Images/pacman_right.xpm";
	imgs[1] = "/nfs/homes/hcorrea-/Documents/"
		"42_Projects/So_Long/Images/pacman_left.xpm";
	imgs[2] = "/nfs/homes/hcorrea-/Documents/"
		"42_Projects/So_Long/Images/pacman_up.xpm";
	imgs[3] = "/nfs/homes/hcorrea-/Documents/"
		"42_Projects/So_Long/Images/pacman_down.xpm";
	imgs[4] = "/nfs/homes/hcorrea-/Documents/"
		"42_Projects/So_Long/Images/pacman_close.xpm";
	while (i < 5)
	{
		data->pacman->img_file[i]
			= mlx_xpm_file_to_image(data->mlx, imgs[i], &width, &height);
		i++;
	}
	free(imgs);
}

void	init_images_enemy(t_data *data, int width, int height)
{
	char	*img0;
	char	*img1;
	int		i;

	i= 0;
	img0 = "/nfs/homes/hcorrea-/Documents/"
		"42_Projects/So_Long/Images/green_enemy1.xpm";
	img1 = "/nfs/homes/hcorrea-/Documents/"
		"42_Projects/So_Long/Images/green_enemy2.xpm";
	while (data->enemy)
	{
		data->enemy[i]->img_file[0]
			= mlx_xpm_file_to_image(data->mlx, img0, &width, &height);
		data->enemy[i]->img_file[1]
			= mlx_xpm_file_to_image(data->mlx, img1, &width, &height);
		i++;
	}
}

void	init_pacman(t_data *data)
{
	int	width;
	int	height;

	width = 100;
	height = 100;
	init_images_pacman(data, width, height);
}

void	init_enemy(t_data *data)
{
	int	width;
	int	height;

	width = 100;
	height = 100;
	init_images_enemy(data, width, height);
}

void	init_map(t_data *data)
{
	render_map(data);
	printf("OK\n");
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
