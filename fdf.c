/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:54:44 by rferro-d          #+#    #+#             */
/*   Updated: 2024/11/30 23:31:08 by rferro-d         ###   ########.fr       */
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

/*
	remove after finish project
*/
// static void	print_map(t_lines *lines)
// {
// 	t_lines			*it_line;
// 	t_map_pointer	*it_pointer;

// 	it_line = lines;
// 	while (it_line)
// 	{
// 		it_pointer = it_line->pointer;
// 		while (it_pointer)
// 		{
// 			ft_putnbr_fd(it_pointer->value, 1);
// 			if (it_pointer->next)
// 				ft_putchar_fd(' ', 1);
// 			it_pointer = it_pointer->next;
// 		}
// 		it_line = it_line->next;
// 		ft_putchar_fd('\n', 1);
// 	}
// }

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
	// print_map(map->map_lines);
	init_window();
	free_map(&map);
	ft_putstr("[SUCCESS] finish in main\n");
	return (0);
}
