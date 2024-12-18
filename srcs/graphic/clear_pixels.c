/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_pixels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:12:29 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/05 19:25:56 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	static clear(t_window *window, int x, int y)
{
    unsigned int	index;

	if (!((x > 0 && x < window->sizex) && (y  > 0 && y < window->sizey)))
		return;
	index = (y * window->map_image.size_line + x * (window->map_image.bpp / 8));
	*(unsigned int *)(window->map_image.img_data + index) = 0; // Define a cor do pixel
}

void	static bresenham(t_point start, t_point end, t_window *window)
{
	float	x_step;
	float	y_step;
	int		max_v;
	
	// apply_zoom(&start.x, image->zoom);
	// apply_zoom(&start.y, image->zoom);
	// apply_zoom(&end.x, image->zoom);
	// apply_zoom(&end.y, image->zoom);
	
	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max_v = max(mod(x_step), mod(y_step));
	x_step /= max_v;
	y_step /= max_v;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		clear(window, start.x, start.y);
		start.x += x_step;
		start.y += y_step;
	}
}

void	static calc_line(t_point *start, t_lines *line, t_map_pointer *collum, t_window *window)
{
	t_point end;
	int temp_x;

	temp_x = start->x;
	end.x = start->x + 3;
	end.y = start->y;
	while (collum)
	{
		if (collum)
		{
			bresenham(*start, end, window);
			start->x = end.x;
		}
		if (line)
		{
			end.y += 3;
			bresenham(*start, end, window);
			end.y  -= 3;
		}
		end.x += 3;
		collum = collum->next;
	}
	start->x = temp_x;
	start->y += 3;
}

void	clear_pixels(t_window *window)
{
	t_lines *line;
	t_map_pointer *collum;
	t_point start;
	t_point end;

	line = window->map->map_lines;
	start.x = (window->sizex / 2) - ((window->map->map_width * 3) / 2) + window->map_image.position.x;
	start.y = (window->sizey / 2) - ((window->map->map_height * 3) / 2) + window->map_image.position.y;
	while (line)
	{
		collum = line->pointer;
		end = start;
		end.y += 3;
		bresenham(start, end, window);
		calc_line(&start, line, collum, window);
		line = line->next;
	}
	calc_line(&start, line, collum, window);
}