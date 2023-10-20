/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:08:19 by pramos            #+#    #+#             */
/*   Updated: 2023/10/20 12:29:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*ft_new_sprite(t_image *img, char *path)
{
	img->img = mlx_xpm_file_to_image(img->mlx, path, &img->x_size, &img->y_size);
	if (img->img == NULL)
		perror("Error\nImage failed to push to window");
	img->addr = mlx_get_data_addr(img->img, &img->bits_p_pixel,
			&img->line_len, &img->endian);
	return (img);
}

void	leaks()
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	char 	**map;
	t_image	*img;
	
	map = ft_read(argv);
	if (argc != 2)
		ft_printf("more than 2 arguments\n");
	if(!check_map(map))
		return(ft_printf("\nbad map"));
	img = (t_image *)malloc(sizeof(t_image));
	if(!img)
		exit(1);

	img->mlx = mlx_init();
	if (img->mlx == NULL)
		return(ft_printf("bad inicialization of mlx \n"), 0);
	img->y_size = count_lines(argv[1]) * 50;
	img->x_size = count_bytes(argv[1]) * 50;
	img->mlx_win = mlx_new_window(img->mlx, img->x_size, img->y_size, "So_long!");
	img->map = map;
//	put_img(img);
//	mlx_key_hook(img->mlx_win, move, img);
	mlx_loop(img->mlx);
}