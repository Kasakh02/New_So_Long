/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:12:56 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/03/07 16:29:31 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../mlx_linux/mlx.h"
#include "../Libft/inc/libft.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdbool.h>
#include <fcntl.h>

#define WW 1440
#define WH 870

#define GREEN_PIXEL 0x00FF00
#define RED_PIXEL 0xFF0000
#define WHITE_PIXEL 0xFFFFFF
#define BLUE_PIXEL 0x0000FF
#define BLACK_PIXEL 0x000000

typedef	struct	s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_pacman
{
	t_pos	pixel_pos;
	t_pos	curr_pos;
	void	**img_file;
	int		image_index;
	bool	mouth_open;
	int		flag;
}			t_pacman;

typedef struct s_enemy
{
	t_pos	pixel_pos;
	t_pos	curr_pos;
	void	**img_file;
	bool	mouth_open;
	int		flag;
}			t_enemy;

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
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_map		*map;
	t_pacman	*pacman;
	t_enemy		**enemy;
}			t_data;

char	*get_next_line(int fd);
void	init_pacman(t_data *data);
void	init_enemy(t_data *data);
void	init_map(t_data *data);
void	get_size(t_data *data);
void	put_pixel(t_data *data, int x, int y, int color);
void	render_map(t_data *data);
int		move_character(int keycode, t_data *data);
void	close_window();
int		gif(t_data *data);
int		is_wall(t_data *data, int x, int y);
int		nbr_enemies(t_data *data);
void	enemy_mallocs(t_data *data);
void	pacman_mallocs(t_data *data);

#endif
