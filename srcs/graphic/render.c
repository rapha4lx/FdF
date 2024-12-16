/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:00:00 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/16 01:50:11 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../imports/libft/libft.h"
#include "graphic.h"
#include "../parse/parser.h"
#include "../../imports/minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

static void	set_pixel(t_window *window, int x, int y, int color)
{
	int	index;

	index = (y * window->map_image.size_line + x * (window->map_image.bpp / 8));
	*(int *)(window->map_image.img_data + index) = color;
}

void	bresenham(t_point start, t_point end, t_map_pointer *collum, t_window *window)
{
	float	x_step;
	float	y_step;
	int		max_v;

	start.x *= window->map_image.zoom;
	start.y *= window->map_image.zoom;
	end.x *= window->map_image.zoom;
	end.y *= window->map_image.zoom;
	
	isometric(&start.x, &start.y, start.z);
	isometric(&end.x, &end.y, end.z);
	
	start.x += window->map_image.rotation.x;
	start.y += window->map_image.rotation.y;
	end.x += window->map_image.rotation.x;
	end.y += window->map_image.rotation.y;
	
	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max_v = max(mod(x_step), mod(y_step));
	x_step /= max_v;
	y_step /= max_v;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		if (!((start.x > 0 && start.x < window->sizex) && (start.y > 0 && start.y < window->sizey)))
			return;
		set_pixel(window, start.x, start.y, ft_atoi_hexa(collum->hex));
		start.x += x_step;
		start.y += y_step;
	}
}

void	draw(t_point *start, t_lines *line, t_map_pointer *collum, t_window *window)
{
	t_point end;
	int temp_x;

	temp_x = start->x;
	end.x = start->x + 3;
	end.y = start->y;
	while (collum)
	{
		end.z = collum->value;
		if (collum)
		{
			bresenham(*start, end, collum, window);
			start->x = end.x;
		}
		if (line)
		{
			end.y += 3;
			bresenham(*start, end, collum, window);
			end.y -= 3;
		}
		end.x += 3;
		collum = collum->next;
	}
	start->x = temp_x;
	start->y += 3;
}

void	render(t_window *window)
{
	t_lines *line;
	t_map_pointer *collum;
	t_point start;
	t_point end;

	window->map_image.last_position = window->map_image.position;
	window->map_image.last_zoom = window->map_image.zoom;
	line = window->map->map_lines;
	// start.x = (window->sizex / 2) - ((window->map->map_width * 3) / 2) + window->map_image.position.x;
	// start.y = (window->sizey / 2) - ((window->map->map_height * 3) / 2) + window->map_image.position.y;
	while (line)
	{
		start.z = line->pointer->value;
		collum = line->pointer;
		end = start;
		end.y += 3;
		bresenham(start, end, collum, window);
		draw(&start, line, collum, window);
		line = line->next;
	}
	draw(&start, line, collum, window);
	mlx_put_image_to_window(window->mlx, window->win, window->map_image.img_ptr, 0, 0);
}
