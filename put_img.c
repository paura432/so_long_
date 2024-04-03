/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:27:34 by pramos            #+#    #+#             */
/*   Updated: 2024/04/03 23:15:23 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_floor(char **map, t_image *img)
{
	char	*relative_path;
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0' && map[y][x] != '\n')
		{
			if (map[y][x] == '1')
			{
				img = ft_new_sprite(img, "sprites/background.xpm");
				mlx_put_image_to_window(img->mlx, img->mlx_win,
				img->img, x * 64, y * 64);
				relative_path = "sprites/wall.xpm";
			}
			else
				relative_path = "sprites/background.xpm";
			img = ft_new_sprite(img, relative_path);
			mlx_put_image_to_window(img->mlx, img->mlx_win,
				img->img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	put_object(char **map, t_image *img)
{
	char	*relative_path;
	int		x;
	int		y;

	y = 0;
	img->objects = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0' && map[y][x] != '\n')
		{
			if (map[y][x] == 'C')
			{
				relative_path = "sprites/object.xpm";
				img = ft_new_sprite(img, relative_path);
				img->objects += 1;
				mlx_put_image_to_window(img->mlx, img->mlx_win,
					img->img, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}

void	put_door(char **map, t_image *img)
{
	char	*relative_path;
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0' && map[y][x] != '\n')
		{
			if (map[y][x] == 'E')
			{
				relative_path = "sprites/door.xpm";
				img = ft_new_sprite(img, relative_path);
				mlx_put_image_to_window(img->mlx, img->mlx_win,
					img->img, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}

void	put_character(char **map, t_image *img)
{
	char	*relative_path;
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0' && map[y][x] != '\n')
		{
			if (map[y][x] == 'P')
			{
				relative_path = "sprites/rick-front.xpm";
				img = ft_new_sprite(img, relative_path);
				img->x_pos = x;
				img->y_pos = y;
				mlx_put_image_to_window(img->mlx, img->mlx_win,
					img->img, (x * 64), (y * 64));
			}
			x++;
		}
		y++;
	}
}

void	put_img(t_image *img)
{
	put_floor(img->map, img);
	put_object(img->map, img);
	put_character(img->map, img);
}
