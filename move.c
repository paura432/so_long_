/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:14:21 by pramos            #+#    #+#             */
/*   Updated: 2024/04/03 23:15:33 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int key_code, t_image *img)
{
	printf("%i\n", key_code);
	if (key_code == 100)
	{
		printf("d\n");
		right(img);
	}
	if (key_code == 119)
		up(img);
	if (key_code == 97)
		left(img);
	if (key_code == 115)
		down(img);
	if (key_code == 65307)
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
		img->x_pos * 64, img->y_pos * 64);
	img = ft_new_sprite(img, "sprites/background.xpm");
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->img, (img->x_pos - 1) * 64, img->y_pos * 64);
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
		img->img, img->x_pos * 64, img->y_pos * 64);
	img = ft_new_sprite(img, "sprites/background.xpm");
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->img, img->x_pos * 64, (img->y_pos + 1) * 64);
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
		img->x_pos * 64, img->y_pos * 64);
	img = ft_new_sprite(img, "sprites/background.xpm");
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->img, (img->x_pos + 1) * 64, img->y_pos * 64);
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
		img->x_pos * 64, img->y_pos * 64);
	img = ft_new_sprite(img, "sprites/background.xpm");
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
		img->x_pos * 64, (img->y_pos - 1) * 64);
	ft_printf("\nNumero de pasos: %i\n", img->steps += 1);
}
