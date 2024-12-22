/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:41:31 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/21 22:12:03 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include <stdlib.h>

void		free_map_array(t_map_pointer_array ***array);

static int	store_array_value_collum(t_map_pointer_array ***array, int width,
		int y)
{
	(*array)[y] = (t_map_pointer_array *)malloc(sizeof(t_map_pointer_array)
			* (width + 1));
	if ((*array)[y] == NULL)
		return (0);
	return (1);
}

static void	store_value(t_map_pointer_array ***array, t_map_pointer *pointer,
		int *x, int y)
{
	while (pointer)
	{
		(*array)[y][*x].value = pointer->value;
		(*array)[y][*x].hex = pointer->hex;
		pointer = pointer->next;
		*x += 1;
	}
}

static int	store_array_values_lines(t_map_pointer_array ***array,
		t_lines *lines, int width)
{
	t_lines			*line;
	t_map_pointer	*pointer;
	int				x;
	int				y;

	y = 0;
	line = lines;
	while (line)
	{
		x = 0;
		if (!store_array_value_collum(array, width, y))
			return (0);
		pointer = line->pointer;
		store_value(array, pointer, &x, y);
		y++;
		line = line->next;
	}
	array[y] = NULL;
	return (1);
}

int	init_map_array(t_map_pointer_array ***array, t_lines *lines, int height,
		int widht)
{
	(*array) = (t_map_pointer_array **)malloc(sizeof(t_map_pointer_array *)
			* (height + 1));
	if (*array == NULL)
		return (0);
	if (!store_array_values_lines(array, lines, widht))
	{
		free_map_array(array);
		return (0);
	}
	return (1);
}

void	free_map_array(t_map_pointer_array ***array)
{
	int	x;
	int	y;

	y = 0;
	while (array[y])
	{
		x = 0;
		while (array[y][x])
		{
			free(array[y][x]);
			array[y][x] = NULL;
			x++;
		}
		free(array[y]);
		array[y] = NULL;
		y++;
	}
}
