/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 04:31:34 by rferro-d          #+#    #+#             */
/*   Updated: 2024/11/24 00:13:24 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H


typedef	struct s_map_pointer
{
	int		value;
	char	*hex;
} t_map_pointer;

typedef struct s_map
{
    int     status;
	int		map_width;
	int		map_heigh;
	t_map_pointer **map_info;
}       t_map;

int map_check(char *file, t_map **map);

#endif