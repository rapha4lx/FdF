/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_pixels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: showoff <showoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:12:29 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/24 17:28:07 by showoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

static void	apply_effect(t_point *start, t_point *end, t_window *window)
{
	start->z = window->map->map_array[((int)start->y * window->map->map_width)
		+ (int)start->x].value;
	end->z = window->map->map_array[((int)end->y * window->map->map_width)
		+ (int)end->x].value;
	apply_zoom(start, window->map_image.last_zoom);
	apply_zoom(end, window->map_image.last_zoom);
	center_map(start, window->map_image.last_zoom, window);
	center_map(end, window->map_image.last_zoom, window);
	isometric(start, &window->map_image.last_rotation,
		window->map_image.last_zoom);
	isometric(end, &window->map_image.last_rotation,
		window->map_image.last_zoom);
	calc_move(start, end, &window->map_image.last_position);
}

static void	bresenham(t_point start, t_point end, t_window *window)
{
	float	x_step;
	float	y_step;
	int		max_v;

	apply_effect(&start, &end, window);
	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max_v = max(mod(x_step), mod(y_step));
	x_step /= max_v;
	y_step /= max_v;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		if (!((start.x > 0 && start.x < window->sizex) && (start.y > 0
					&& start.y < window->sizey)))
		{
			start.x += x_step;
			start.y += y_step;
			continue ;
		}
		set_pixel(window, start.x, start.y, 0);
		start.x += x_step;
		start.y += y_step;
	}
}

static void	check_if_apply_bresenham(t_point start, t_point end,
		t_window *window)
{
	if (start.x < window->map->map_width - 1)
	{
		++end.x;
		bresenham(start, end, window);
		--end.x;
	}
	if (start.y < window->map->map_height - 1)
	{
		++end.y;
		bresenham(start, end, window);
		--end.y;
	}
}

void	clear_pixels(t_window *window)
{
	t_point	start;
	t_point	end;

	start.y = 0;
	while (start.y < window->map->map_height)
	{
		start.x = 0;
		while (start.x < window->map->map_width)
		{
			end = start;
			check_if_apply_bresenham(start, end, window);
			start.x++;
		}
		start.y++;
	}
}
