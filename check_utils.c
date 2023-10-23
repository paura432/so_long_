/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:11:59 by pramos            #+#    #+#             */
/*   Updated: 2023/10/23 23:33:28 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_bytes_w_fd(char *map)
{
	int	x;

	x = 0;
	while (map[x] != '\0' && map[x] != '\n')
		x++;
	return (x);
}

int	count_lines_w_fd(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0' && map[y][x] != '\n')
			x++;
		y++;
	}
	return (y);
}

void	f_fill_p2e(char **flood_map, char target, int y, int x)
{
	if (y < 0 || x < 0 || y >= 7 || x >= 17)
		return ;
	if (flood_map[y][x] == 'F' || flood_map[y][x] == target)
		return ;
	if (flood_map[y][x] != 'P')
		flood_map[y][x] = 'F';
	f_fill_p2e(flood_map, target, y - 1, x);
	f_fill_p2e(flood_map, target, y + 1, x);
	f_fill_p2e(flood_map, target, y, x - 1);
	f_fill_p2e(flood_map, target, y, x + 1);
}
