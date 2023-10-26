/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:08:19 by pramos            #+#    #+#             */
/*   Updated: 2023/10/26 19:35:04 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*ft_new_sprite(t_image *img, char *path)
{
	img->img = mlx_xpm_file_to_image(img->mlx, path,
			&img->x_size, &img->y_size);
	if (img->img == NULL)
		perror("Error\nImage failed to push to window");
	img->addr = mlx_get_data_addr(img->img, &img->bits_p_pixel,
			&img->line_len, &img->endian);
	return (img);
}

void	leaks(void)
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	char	**map;
	t_image	*img;

	// atexit(leaks);
	map = ft_read(argv);
	if (!check_map(map, argv))
		return (ft_printf("\nbad map\n"));
	img = (t_image *)malloc(sizeof(t_image));
	if (!img)
		exit(1);
	if (argc != 2)
		ft_printf("bad arguments\n");
	img->mlx = mlx_init();
	img->y_size = count_lines_w_fd(map) * 50;
	img->x_size = count_bytes_w_fd(map[0]) * 50;
	ft_printf("%i\n", img->y_size / 50);
	ft_printf("%i\n", img->x_size / 50);
	img->mlx_win = mlx_new_window(img->mlx, img->x_size,
			img->y_size, "So_long!");
	img->steps = 0;
	img->map = map;
	put_img(img);
	mlx_key_hook(img->mlx_win, move, img);
	mlx_loop(img->mlx);
}
