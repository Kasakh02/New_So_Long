/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:13:57 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/07 16:56:40 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int key_press(int keycode, t_data *data)
{
	if (keycode == 65307)
		exit(0);
	else if (keycode == 65361 || keycode == 65362 || keycode == 65363 || keycode == 65364)
		move_character(keycode, data);
	return (1);
}

int key_release(int keycode, t_data *data)
{
	if (keycode == 53)
		key_press(53, data);
	return (0);
}

void general_init(t_data *data)
{
	char **lines;

	lines = malloc(100 * sizeof(char *));
	data->map->lines = lines;
	data->map->fd = open("Maps/map1.ber", O_RDONLY);
	if (data->map->fd == -1)
		return;
	get_size(data);
	pacman_mallocs(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map->width,
							   data->map->height, "PacMan");
	data->img = mlx_new_image(data->mlx, data->map->width,
							  data->map->height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
								   &data->line_length, &data->endian);
	init_map(data);
	printf("OK\n");
	init_pacman(data);
	init_enemy(data);
}

int main(int argc, char **argv)
{
	t_data *data;

	(void)argv;
	if (argc == 2)
	{
		data = malloc(sizeof(t_data));
		data->map = malloc(sizeof(t_map));
		if (!data || !data->map)
			return (0);
		general_init(data);
		mlx_loop_hook(data->mlx, gif, data);
		mlx_hook(data->win, 2, 0, key_press, data);
		mlx_hook(data->win, 3, 1, key_release, data);
		mlx_loop(data->mlx);
	}
	else if (argc > 2)
		printf("Too many arguments!\n");
	else
		printf("Too few arguments!\n");
	return (0);
}
