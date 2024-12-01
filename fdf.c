/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:54:44 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/01 03:16:51 by rferro-d         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		write(1, "map not inserted\n", 18);
		return (0);
	}
	ft_putstr("[START] init_map\n");
	if (!init_map(&map))
		return (0);
	ft_putstr("[SUCCESS] init_map\n");
	ft_putstr("[START] map_check\n");
	if (!map_check(argv[1], &map))
		map_error(argv[1], &map);
	ft_putstr("[END] success read map\n");
	init_window(map);
	free_map(&map);
	ft_putstr("[SUCCESS] finish in main\n");
	return (0);
}
