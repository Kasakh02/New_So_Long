/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:12:56 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/10 15:49:40 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../Libft/inc/libft.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <time.h>
# include <sys/time.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdlib.h>

# define WW 1440
# define WH 870
# define GIF_RATE 100
# define ENEMY_FRAME_RATE 500
# define VULNERABLE 5000

# define GREEN_PIXEL 0x00FF00
# define RED_PIXEL 0xFF0000
# define WHITE_PIXEL 0xFFFFFF
# define BLUE_PIXEL 0x0000FF
# define BLACK_PIXEL 0x000000

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_pacman
{
	t_pos			pixel_pos;
	t_pos			curr_pos;
	struct timeval	last_gif;
	struct timeval	last_vulnerable;
	void			**img_file;
	int				image_index;
	bool			mouth_open;
	int				flag;
	int				nbr_consumables;
}			t_pacman;

typedef struct s_enemy
{
	t_pos			pixel_pos;
	t_pos			curr_pos;
	struct timeval	last_movement;
	void			**img_file;
	bool			mouth_open;
	int				flag;
	int				print;
	int				state;
}					t_enemy;

typedef struct s_consumable
{
	t_pos	pixel_pos;
	t_pos	curr_pos;
	int		flag;
	int		print;
}			t_consumable;

typedef struct s_exit
{
	t_pos	pixel_pos;
	t_pos	curr_pos;
	int		flag;
	int		print;
}			t_exit;

typedef struct s_map
{
	int		color;
	int		width;
	int		height;
	int		fd;
	char	**lines;
}			t_map;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_map			*map;
	t_pacman		*pacman;
	t_enemy			**enemy;
	t_consumable	**consumable;
	t_exit			*exit;
}			t_data;

char	*get_next_line(int fd);
void	init_pacman(t_data *data);
void	init_enemy(t_data *data);
void	init_consumable(t_data *data);
void	init_map(t_data *data);
void	get_size(t_data *data);
void	put_pixel(t_data *data, int x, int y, int color);
void	render_map(t_data *data, int j, int x, int c);
int		move_character(int keycode, t_data *data);
int		close_window(t_data *data);
int		die(t_data *data);
int		invalid(t_data *data, int code);
int		win(t_data *data);
int		gif(t_data *data);
int		is_wall_pacman(t_data *data, int x, int y);
int		is_wall_enemy(t_data *data, int x, int y, int i);
int		nbr_enemies(t_data *data);
void	enemy_mallocs(t_data *data);
void	pacman_mallocs(t_data *data);
int		move_enemy(t_data *data);
void	init_images_enemy(t_data *data, int width, int height);
void	init_images_pacman(t_data *data, int width, int height);
int		nbr_consumables(t_data *data);
void	draw_circle(int x, int y, int color, t_data *data);
void	draw_square(int x, int y, int color, t_data *data);
void	valid_map(t_data *data);
void	render_exit(t_data *data, int i, int j);
void	set_enemies_vulnerable(t_data *data, int x);
int		map_sizes(t_data *data);
int		closed_map(t_data *data);
int		valid_character(t_data *data);
void	rand_nbr_enemy(t_data *data, int i);
void	upgrade_pos_render_map_enemy(t_data *data, int x, int y, int i);
void	draw_render(t_data *data, int i, int j);
void	render_pacman(t_data *data, int i, int j);
void	nbr_enemies_consumables(t_data *data, int i, int j);
int		verify_height(t_data *data, int map_height, int map_width, int i);
void	pacman_gif_utils(t_data *data, int elapsed_time, struct timeval now);
void	enemy_gif(t_data *data, int flag);
void	pacman_gif(t_data *data, int flag);
int		valid_path(t_data *data);
void	clear_all(t_data *data);
void	clear_map(t_data *data);
#endif
