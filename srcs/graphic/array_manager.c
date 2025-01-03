/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:41:31 by rferro-d          #+#    #+#             */
/*   Updated: 2025/01/02 16:51:57 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include <stdlib.h>

int	init_map_array(t_map_pointer_array **array, t_lines *lines, int height,
		int width)
{
	t_lines			*line;
	t_map_pointer	*point;
	int				index;

	*array = (t_map_pointer_array *)malloc(sizeof(t_map_pointer_array) * (height
				* width + 1));
	if (!(*array))
		return (0);
	line = lines;
	index = 0;
	while (line)
	{
		point = line->pointer;
		while (point)
		{
			(*array)[index].value = point->value;
			(*array)[index].hex = point->hex;
			index++;
			point = point->next;
		}
		line = line->next;
	}
	return (1);
}

void	free_map_array(t_map_pointer_array *array)
{
	free(array);
	array = NULL;
}
