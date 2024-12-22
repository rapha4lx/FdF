/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:00:00 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/21 20:58:54 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../imports/libft/libft.h"
#include "graphic.h"
#include "../parse/parser.h"
#include "../../imports/minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

static void	save_last_render(t_window *window)
{
	window->map_image.last_position.x = window->map_image.position.x;
	window->map_image.last_position.y = window->map_image.position.y;
	window->map_image.last_rotation.x = window->map_image.rotation.x;
	window->map_image.last_rotation.y = window->map_image.rotation.y;
	window->map_image.last_zoom = window->map_image.zoom;
	window->map_image.last_zoom = window->map_image.zoom;
}

static void	apply_effect(t_point *start, t_point *end,
	int *color, t_window *window)
{
	start->z = window->map->map_array[(int)start->y][(int)start->x].value;
	end->z = window->map->map_array[(int)end->y][(int)end->x].value;
	if (window->map->map_array[(int)start->y][(int)start->x].hex)
		*color = ft_atoi_hexa(window->map->map_array
			[(int)start->y][(int)start->x].hex);
	else if (start->z > 0)
		*color = 0xe80c0c;
	else
		*color = 0xFFFFFF;
	apply_zoom(start, window->map_image.zoom);
	apply_zoom(end, window->map_image.zoom);
	center_map(start, window->map_image.zoom, window);
	center_map(end, window->map_image.zoom, window);
	isometric(start, &window->map_image.rotation, window->map_image.zoom);
	isometric(end, &window->map_image.rotation, window->map_image.zoom);
	calc_move(start, end, &window->map_image.position);
}

static void	bresenham(t_point start, t_point end, t_window *window)
{
	float	x_step;
	float	y_step;
	int		max_v;
	int		color;

	apply_effect(&start, &end, &color, window);
	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max_v = max(mod(x_step), mod(y_step));
	x_step /= max_v;
	y_step /= max_v;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		if (!((start.x > 0 && start.x < window->sizex)
				&& (start.y > 0 && start.y < window->sizey)))
		{
			start.x += x_step;
			start.y += y_step;
			continue ;
		}
		set_pixel(window, start.x, start.y, color);
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

void	render(t_window *window)
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
	save_last_render(window);
	mlx_put_image_to_window(window->mlx, window->win,
		window->map_image.img_ptr, 0, 0);
}
