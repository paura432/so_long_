/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:07:41 by pramos            #+#    #+#             */
/*   Updated: 2023/10/30 16:59:35 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "mlx_linux/mlx.h"

typedef struct s_image {
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	*addr;
	int		bits_p_pixel;
	int		line_len;
	int		endian;
	int		x_size;
	int		y_size;
	int		y_pos;
	int		x_pos;
	int		objects;
	int		steps;
	char	**map;
}				t_image;

//read
t_image	*ft_new_sprite(t_image *img, char *path);
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
char	**ft_read(char **argv);
int		count_bytes(char *argv);
int		count_lines(char *argv);

//put_img
void	put_floor(char **map, t_image *img);
void	put_object(char **map, t_image *img);
void	put_img(t_image *img);
void	put_character(char **map, t_image *img);
void	put_door(char **map, t_image *img);

//move
int		move(int key_code, t_image *img);
void	right(t_image *img);
void	up(t_image *img);
void	left(t_image *img);
void	down(t_image *img);

//check_move

void	check_move(t_image *img);
char	**change_map(char **argv);
int		check_p(char **map, int x);

//check_utils

int		check_map_full(char **map_full, char **map);
void	f_fill_p2e(char **flood_map, char target, int y, int x);
void	flood_fill(char **map_full);
int		count_lines_w_fd(char **map);
int		count_bytes_w_fd(char *map);

//parse
int		check_map(char **map, char **argv);
int		check_walls(char **map);
int		check_obj(char **map, int y, int x);
int		check_flood_map(char **flood_map);
int		check_exit(char **flood_map, int x, int y);

//free
void	free_list(t_image *img);
void	free_mlx(t_image *img);
void	free_matriz(char **matriz);

int		close_window(t_image *img);

#endif
