/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:37:38 by pramos            #+#    #+#             */
/*   Updated: 2023/10/19 17:49:00 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    check_move(t_image *img)
{
    if(img->map[img->y_pos][img->x_pos] == 'C')
    {
        img = ft_new_sprite(img, "sprites/background.xpm");
        mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->x_pos * 50, img->y_pos * 50);
        img->objects -= 1;
    }
    if(img->objects == 0)
        put_door(img->map, img);
    if(img->map[img->y_pos][img->x_pos] == 'E')
        mlx_destroy_window(img->mlx, img->mlx_win);
}

int check_p(char **map, int p)
{
    int y;
    int x;
    
    y = 0;
    while(map[y])
    {
        x = 0;
        while(map[y][x] != '\0' && map[y][x] != '\n')
        {
            if(map[y][x] == 'P')
            {
                if(p == 0)
                    return(x);
                if(p == 1)
                    return(y);
            }
            x++;
        }
        y++;
    }
    return(p);
}

char    **change_map(char **map)
{
    int x;
    int y;
    char **map_full;

    y = 0;
    map_full = malloc(sizeof(char *) * (count_lines_w_fd(map) + 1));
    while(map[y])
    {
        x = 0;
        map_full[y] = malloc(sizeof(char *) * (count_bytes_w_fd(map[y])));
        while(map[y][x] != '\0' && map[y][x] != '\n')
        {
            map_full[y][x] = map[y][x];
            x++;
        }
        y++;
    }
    map_full[y] = malloc(sizeof(char *) * 1);
    map_full[y] = NULL;
    return (map_full);
}