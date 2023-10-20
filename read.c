/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:55:59 by pramos            #+#    #+#             */
/*   Updated: 2023/10/20 12:01:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_lines(char *argv)
{
    int fd;
    int lines;
    int bytes;
    char character[1];
    
    fd = open(argv, O_RDONLY);
    lines = 1;
    bytes = 1;
    while(bytes != 0)
    {
        if(character[0] == '\n')
            lines++;
        bytes = read(fd, character, 1);
    }
    close(fd);
    return(lines);
}

int count_bytes(char *argv)
{
    int fd;
    int bytes;
    int bytes_read;
    char character[1];
    
    fd = open(argv, O_RDONLY);
    bytes = 0;
    bytes_read = 1;
    while(bytes_read != 0 && character[0] != '\n')
    {
        bytes_read = read(fd, character, 1);
        if(character[0] != '\n')
            bytes++;
    }
    close(fd);
    return(bytes);
}

char **ft_read(char **argv)
{
    int i;
    int lines;
    int fd;
    char **map;
    
    i = 0;
    lines = count_lines(argv[1]);
    map = (char **)malloc(sizeof(char *) * (count_lines(argv[1]) + 1));
    fd = open(argv[1], O_RDONLY);
    while(lines-- > 0)
        map[i++] = get_next_line(fd);
    map[i] = NULL;
    close(fd);
    return(map);
}