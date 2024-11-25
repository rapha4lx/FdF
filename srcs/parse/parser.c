/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:05:17 by rferro-d          #+#    #+#             */
/*   Updated: 2024/11/24 22:57:04 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <fcntl.h>
#include <stdio.h>
// #include "../includes/get_next_line.h"
#include "../includes/libft.h"

int		init_map(t_map **map)
{
	(*map) = (t_map*)malloc(sizeof(t_map) * 1);
	if (*map)
		return (0);
	(*map)->status = 0;
	(*map)->map_width = -1;
	(*map)->map_height = -1;
	(*map)->map_lines = NULL;
	return (1);
}

void	free_map(t_map *map)
{
	int		m_width;
	int		m_height;

	if (!map)
		return;
	m_width = 0;
	m_height = 0;

	
	free(map);
}

int		map_line(t_map **map, char *line)
{
	char	**buff;
	int		buff_s;

	buff = ft_split(line, ' ');
	buff_s = 0;
	while (buff[buff_s] != NULL)
		buff_s++;
	if ((*map)->map_width == -1)
		(*map)->map_width = buff_s;

	return (1);
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
		if (!(map_line(map, line)))
		{
			free_map(*map);
			break;
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (*map != NULL);
}


