/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:37:38 by pramos            #+#    #+#             */
/*   Updated: 2024/04/03 23:15:43 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_move(t_image *img)
{
	if (img->map[img->y_pos][img->x_pos] == 'C')
	{
		img = ft_new_sprite(img, "sprites/background.xpm");
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->img, img->x_pos * 64, img->y_pos * 64);
		img->objects -= 1;
		img->map[img->y_pos][img->x_pos] = '0';
	}
	if (img->objects == 0)
		put_door(img->map, img);
	if (img->map[img->y_pos][img->x_pos] == 'E' && img->objects == 0)
	{
		ft_printf("YOU WIN\n");
		free_list(img);
	}
}

int	check_p(char **map, int p)
{
	int	y;
	int	x;

	y = 0;
	while (y < count_lines_w_fd(map))
	{
		x = 0;
		while (map[y][x] != '\0' && map[y][x] != '\n')
		{
			if (map[y][x] == 'P')
			{
				if (p == 0)
					return (x);
				if (p == 1)
					return (y);
			}
			x++;
		}
		y++;
	}
	return (p);
}

char	**change_map(char **argv)
{
	char	**map_full;

	map_full = ft_read(argv);
	return (map_full);
}
