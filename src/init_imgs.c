/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:59:11 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/09 14:41:01 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_images_pacman(t_data *data, int width, int height)
{
	char	**imgs;
	int		i;

	i = 0;
	imgs = malloc(5 * sizeof(char *));
	imgs[0] = "/Users/henrique/Documents/"
		"42 school/So_Long/Images/pacman_right.xpm";
	imgs[1] = "/Users/henrique/Documents/"
		"42 school/So_Long/Images/pacman_left.xpm";
	imgs[2] = "/Users/henrique/Documents/"
		"42 school/So_Long/Images/pacman_up.xpm";
	imgs[3] = "/Users/henrique/Documents/"
		"42 school/So_Long/Images/pacman_down.xpm";
	imgs[4] = "/Users/henrique/Documents/"
		"42 school/So_Long/Images/pacman_close.xpm";
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

	i = 0;
	img0 = "/Users/henrique/Documents/"
		"42 school/So_Long/Images/green_enemy1.xpm";
	img1 = "/Users/henrique/Documents/"
		"42 school/So_Long/Images/green_enemy2.xpm";
	while (i < nbr_enemies(data))
	{
		data->enemy[i]->img_file[0]
			= mlx_xpm_file_to_image(data->mlx, img0, &width, &height);
		data->enemy[i]->img_file[1]
			= mlx_xpm_file_to_image(data->mlx, img1, &width, &height);
		i++;
	}
}
