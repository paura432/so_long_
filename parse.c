/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:28:50 by pramos            #+#    #+#             */
/*   Updated: 2023/10/30 17:14:26 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char **map, char **argv)
{
	char	**flood_map;

	if (!check_walls(map) ||!check_obj(map, 0, 0))
		return (0);
	flood_map = change_map(argv);
	if (!check_flood_map(flood_map))
	{
		free_matriz(flood_map);
		return (0);
	}
	free_matriz(flood_map);
	return (1);
}

int	check_flood_map(char **flood_map)
{
	f_fill_p2e(flood_map, '1', check_p(flood_map, 1), check_p(flood_map, 0));
	if (!check_exit(flood_map, 0, 0))
		return (0);
	return (1);
}

int	check_exit(char **flood_map, int x, int y)
{
	while (flood_map[y] != 0)
	{
		x = 0;
		while (flood_map[y][x] != 0 && flood_map[y][x] != '\n')
		{

			if (flood_map[y][x] == 'E')
				return (0);
			if (flood_map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_walls(char **map)
{
	int	y;
	int	x;
	int	lines;
	int	bytes;

	y = 0;
	lines = count_lines_w_fd(map);
	bytes = count_bytes_w_fd(map[0]);
	if (lines - 1 < 2 || bytes - 1 < 2)
		return (0);
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0' && map[y][x] != '\n')
		{
			if (map[0][x] != '1' || map[lines - 1][x] != '1' ||
				map[y][0] != '1' || map[y][bytes - 1] != '1')
				return (0);
			x++;
		}
		if (bytes != count_bytes_w_fd(map[y]))
			return (0);
		y++;
	}
	return (1);
}

int	check_obj(char **map, int y, int x)
{
	int	object;
	int	p;
	int	e;

	object = 0;
	p = 0;
	e = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0' && map[y][x] != '\n')
		{
			if (map[y][x] == 'O')
				object++;
			if (map[y][x] == 'P')
				p++;
			if (map[y][x] == 'E')
				e++;
			x++;
		}
		y++;
	}
	if (p != 1 || e != 1 || object < 0)
		return (0);
	return (1);
}
