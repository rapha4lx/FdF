/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_in_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:18:24 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/21 21:25:35 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../imports/minilibx-linux/mlx.h"
#include "graphic.h"
#include <stdlib.h>

void	set_pixel(t_window *window, int x, int y, int color)
{
	int	index;

	index = (y * window->map_image.size_line + x * (window->map_image.bpp / 8));
	*(int *)(window->map_image.img_data + index) = color;
}

static float	get_text_size(char *string)
{
	int		count;
	float	size;

	count = 0;
	size = 0;
	while (string[count])
		count++;
	size = count * 6;
	return (size);
}

void	draw_string(t_point *point, char *text, char *value, t_window *window)
{
	float	string_size;

	string_size = get_text_size(text);
	mlx_string_put(window->mlx, window->win, point->x, point->y, 0xFFFFFF,
		text);
	mlx_string_put(window->mlx, window->win, point->x + string_size, point->y,
		0xFFFFFF, value);
	point->y += 20;
	free(value);
}
