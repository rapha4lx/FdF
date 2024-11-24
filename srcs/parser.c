/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:05:17 by rferro-d          #+#    #+#             */
/*   Updated: 2024/11/24 00:15:20 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <fcntl.h>
#include <stdio.h>
#include "../includes/get_next_line.h"
#include "../includes/libft.h"

int		init_map(t_map **map)
{
	(*map) = (t_map*)malloc(sizeof(t_map) * 1);
	if (*map)
		return (0);
	(*map)->status = 0;
	(*map)->map_width = -1;
	(*map)->map_heigh = -1;
	(*map)->map_info = NULL;
	return (1);
}

void	free_map(t_map *map)
{
	t_map_pointer	*tmp;

	if (map->map_info)
	{
		while (map->map_info != NULL)
		{
			tmp = map->map_info;
		}
		
	}
	free(map);
}

int		map_line(t_map **map, char *line)
{
	char	*buff;
	
	buff = ft_split(line, ' ');


}

int		map_check(char *file, t_map **map)
{
    int		fd;
    char	*line;
	
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	init_map(map);
    while(*map && line)
	{
		// if ((*map)->map_heigh == -1)
		// 	(*map)->map_heigh = 
		line = get_next_line(fd);
	}
	close(fd);
	return (*map);
}


