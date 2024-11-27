/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:01:07 by rferro-d          #+#    #+#             */
/*   Updated: 2024/11/27 19:29:14 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../../imports/libft/libft.h"

static t_map_pointer	*filter_collum(char *buff)
{
	char	*filter;
	int 	value;
	char	*hex;
	
	value = ft_atoi(buff);
	filter = ft_strnstr(buff, "0x", ft_strlen(buff) + 1);
	hex = NULL;
	if (filter)
		hex = ft_substr(filter, 0, 9);
	return (ft_m_pointer_new(value, hex));
}

int     build_line(t_map **map, char **buff)
{
    t_lines     *last;
	int		it;

	it = 0;
    last = ft_sline_new();
    if (!last)
        return (0);
    ft_sline_add_back(&((*map)->map_lines), last);
	while (buff[it])
		ft_m_pointer_add_back(&last->pointer, filter_collum(buff[it++]));
    return (1);
}
