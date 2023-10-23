/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:53:53 by pramos            #+#    #+#             */
/*   Updated: 2023/10/23 23:33:41 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_list(t_image *img)
{
	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_destroy_window(img->mlx, img->mlx_win);
	free_matriz(img->map);
	free(img);
	exit(0);
}

void	free_matriz(char **matriz)
{
	int	i;

	i = 0;
	while (matriz[i])
		free(matriz[i++]);
	free(matriz);
}
