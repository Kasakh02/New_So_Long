/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:13:57 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/10 16:56:48 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	else if (keycode == 115 || keycode == 100 || keycode == 97 || keycode == 119)
		move_character(keycode, data);
	return (1);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == 65307)
		key_press(65307, data);
	return (0);
}

void	general_init(t_data *data)
{
	char	**lines;

	lines = malloc(100 * sizeof(char *));
	data->map->lines = lines;
	get_size(data);
	valid_map(data);
	pacman_mallocs(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map->width,
			data->map->height, "PacMan");
	data->img = mlx_new_image(data->mlx, data->map->width,
			data->map->height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	init_map(data);
	init_pacman(data);
	init_enemy(data);
	init_consumable(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	(void)argv;
	if (argc == 2)
	{
		data = malloc(sizeof(t_data));
		data->map = malloc(sizeof(t_map));
		data->map->fd = open(argv[1], O_RDONLY);
		if (!data || !data->map || data->map->fd == -1)
			return (0);
		general_init(data);
		mlx_loop_hook(data->mlx, gif, data);
		mlx_hook(data->win, 2, 0, key_press, data);
		mlx_hook(data->win, 3, 1, key_release, data);
		mlx_hook(data->win, 17, 17, close_window, data);
		mlx_loop(data->mlx);
	}
	else if (argc > 2)
		printf("Too many arguments!\n");
	else
		printf("Too few arguments!\n");
	return (0);
}
