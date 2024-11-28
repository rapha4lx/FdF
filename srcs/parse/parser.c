/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:05:17 by rferro-d          #+#    #+#             */
/*   Updated: 2024/11/28 18:16:39 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <fcntl.h>
#include <stdio.h>
#include "../../imports/libft/libft.h"

int		init_map(t_map **map)
{
	(*map) = (t_map*)malloc(sizeof(t_map) * 1);
	if (!*map)
		return (0);
	(*map)->status = 0;
	(*map)->map_fd = -1;
	(*map)->map_file = NULL;
	(*map)->map_width = -1;
	(*map)->map_height = -1;
	(*map)->map_lines = NULL;
	return (1);
}

void	free_map(t_map **map)
{
	char * line;

	if (!(*map))
		return;
	if ((*map)->fd_status && (*map)->map_fd != 0)
	{
		while ((line = get_next_line((*map)->map_fd)))
			free (line);
		close((*map)->map_fd);
	}
	ft_sline_clear(&(*map)->map_lines, NULL);
	free(*map);
	(*map) = NULL;
}

int		map_line(t_map **map, char *line)
{
	char	**buff;
	int		buff_s;

	if (!(*line) && *map)
		return (1);
	buff = ft_split(line, ' ');
	buff_s = ft_get_nsplit_size(buff, '\n');
	if ((*map)->map_width == -1)
		(*map)->map_width = buff_s;
	else if ((*map)->map_width != buff_s)
	{
		ft_free_split(buff);
		return (0);
	}
	if (!build_line(map, buff))
	{
		ft_free_split(buff);
		return (0);
	}
	ft_free_split(buff);
	return (1);
}

int		map_check(char *file, t_map **map)
{
    char	*line;
	
	(*map)->map_fd = open(file, O_RDONLY);
	if ((*map)->map_fd < 0)
		return (0);
	(*map)->fd_status = 1;
	(*map)->map_file = file;
	line = get_next_line((*map)->map_fd);
    while (*map && line)
	{
		ft_search_and_replace(line, '\n', '\0');
		if (!(map_line(map, line)))
		{
			free_map(map);
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line((*map)->map_fd);
	}
	free(line);
	(*map)->fd_status = 0;
	close((*map)->map_fd);
	return (1);
}


