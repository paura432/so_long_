/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:14:21 by pramos            #+#    #+#             */
/*   Updated: 2023/10/30 16:48:52 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int key_code, t_image *img)
{
	if (key_code == 2)
		right(img);
	if (key_code == 13)
		up(img);
	if (key_code == 0)
		left(img);
	if (key_code == 1)
		down(img);
	if (key_code == 53)
	{
		ft_printf("GAME FINISHED\n");
		free_list(img);
	}
	return (0);
}

void	right(t_image *img)
{
	if (img->map[img->y_pos][img->x_pos + 1] == '1')
		return ;
	img->x_pos += 1;
	check_move(img);
	img = ft_new_sprite(img, "sprites/rick-right.xpm");
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
		img->x_pos * 50, img->y_pos * 50);
	img = ft_new_sprite(img, "sprites/background.xpm");
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->img, (img->x_pos - 1) * 50, img->y_pos * 50);
	ft_printf("\nNumero de pasos: %i\n", img->steps += 1);
}

void	up(t_image *img)
{
	if (img->map[img->y_pos - 1][img->x_pos] == '1')
		return ;
	img->y_pos -= 1;
	check_move(img);
	img = ft_new_sprite(img, "sprites/rick-back.xpm");
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->img, img->x_pos * 50, img->y_pos * 50);
	img = ft_new_sprite(img, "sprites/background.xpm");
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->img, img->x_pos * 50, (img->y_pos + 1) * 50);
	ft_printf("\nNumero de pasos: %i\n", img->steps += 1);
}

void	left(t_image *img)
{

	if (img->map[img->y_pos][img->x_pos - 1] == '1')
		return ;
	img->x_pos -= 1;
	check_move(img);
	img = ft_new_sprite(img, "sprites/rick-left.xpm");
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
		img->x_pos * 50, img->y_pos * 50);
	img = ft_new_sprite(img, "sprites/background.xpm");
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->img, (img->x_pos + 1) * 50, img->y_pos * 50);
	ft_printf("\nNumero de pasos: %i\n", img->steps += 1);
}

void	down(t_image *img)
{
	if (img->map[img->y_pos + 1][img->x_pos] == '1')
		return ;
	img->y_pos += 1;
	check_move(img);
	img = ft_new_sprite(img, "sprites/rick-front.xpm");
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
		img->x_pos * 50, img->y_pos * 50);
	img = ft_new_sprite(img, "sprites/background.xpm");
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
		img->x_pos * 50, (img->y_pos - 1) * 50);
	ft_printf("\nNumero de pasos: %i\n", img->steps += 1);
}
