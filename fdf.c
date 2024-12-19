/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: showoff <showoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:54:44 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/18 19:59:23 by showoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "imports/libft/libft.h"
#include "srcs/parse/parser.h"
#include "srcs/graphic/graphic.h"

static void	map_error(char *map_file, t_map **map)
{
	ft_putstr("This map: ");
	ft_putstr(map_file);
	ft_putstr(" is brock\n");
	free_map(map);
	exit(0);
}

static void input_error(char *erro)
{
	ft_putstr(erro);
	exit(0);
}

static void	init_map_array(t_map_pointer_array ***array, t_lines *lines, int height, int widht)
{
	(*array) = (t_map_pointer_array **)malloc(sizeof(t_map_pointer_array*) * (height + 1));
	t_lines *line;
	t_map_pointer *pointer;

	int x;
	int y;
	y = 0;
	line = lines;
	while (line)
	{
		x = 0;
		(*array)[y] = (t_map_pointer_array *)malloc(sizeof(t_map_pointer_array) * (widht + 1));
		pointer = line->pointer;
		while(pointer)
		{
			(*array)[y][x].value = pointer->value;
			(*array)[y][x].hex = pointer->hex;
			pointer = pointer->next;
			x++;
		}
		y++;
		line = line->next;
	}
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		input_error("not inserted map");
	// if (!ft_strnstr(argv[2], ".fdf", ft_strlen(argv[2])))
	// 	input_error("file not is a fdf file");
	ft_putstr("[START] init_map\n");
	if (!init_map(&map))
		return (0);
	ft_putstr("[SUCCESS] init_map\n");
	ft_putstr("[START] map_check\n");
	if (!map_check(argv[1], &map))
		map_error(argv[1], &map);
	
	init_map_array(&map->map_array, map->map_lines, map->map_height, map->map_width);
	ft_putstr("[END] success read map\n");

	init_window(map);
	free_map(&map);
	ft_putstr("[SUCCESS] finish in main\n");
	return (0);
}
