/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:54:44 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/21 21:41:41 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "imports/libft/libft.h"
#include "srcs/graphic/graphic.h"
#include "srcs/parse/parser.h"
#include <unistd.h>

static void	map_error(char *map_file, t_map **map)
{
	ft_putstr("This map: ");
	ft_putstr(map_file);
	ft_putstr(" is brock\n");
	free_map(map);
	exit(0);
}

static void	input_error(char *erro)
{
	ft_putstr(erro);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		input_error("not inserted map\n");
	if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
		input_error("file not is a fdf file\n");
	if (!init_map(&map))
		return (0);
	if (!map_check(argv[1], &map))
		map_error(argv[1], &map);
	init_map_array(&map->map_array, map->map_lines, map->map_height,
		map->map_width);
	init_window(map);
	free_map(&map);
	return (0);
}
