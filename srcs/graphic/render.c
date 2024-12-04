/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:00:00 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/04 20:22:37 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../imports/libft/libft.h"
#include "graphic.h"
#include "../parse/parser.h"
#include "../../imports/minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

static int init_image(void* mlx, t_image *image, int width, int height)
{
	image->img_data = NULL;
	image->img_ptr = NULL;
	image->zoom	= 20;
	image->rotation_x = 0;
	image->rotation_y = 0;
	image->position_x = 0;
	image->position_y = 0;
	image->img_ptr = mlx_new_image(mlx, width, height);
	if (!image->img_ptr)
		return (0);
	image->img_data = mlx_get_data_addr(image->img_ptr, &image->bpp,
		&image->size_line, &image->endian);
	if (!image->img_data)
		return (0);
	return (1);
}

int	init_images(t_window *window)
{
	if (!init_image(window->mlx, &window->map_image,
		window->sizex, window->sizey))
		return (0);
	if (!init_image(window->mlx, &window->panel_image,
		300, 500))
		return (0);
	render(window);
	return (1);
}

void	free_images(t_window *window)
{
	if (window->map_image.img_ptr)
		mlx_destroy_image(window->mlx, window->map_image.img_ptr);
	
	if (window->panel_image.img_ptr)
		mlx_destroy_image(window->mlx, window->panel_image.img_ptr);
}

void	bresenham(t_draw_point start, t_draw_point end, t_map_pointer *collum, t_window *window)
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
		mlx_pixel_put(window->mlx,
			window->win, start.x, start.y, ft_atoi_hexa(collum->hex));
		start.x += x_step;
		start.y += y_step;
	}
}

void	draw(t_draw_point *start, t_lines *line, t_map_pointer *collum, t_window *window)
{
	t_draw_point end;
	int temp_x;

	temp_x = start->x;
	end.x = start->x + 10;
	end.y = start->y;
	while (collum)
	{
		if (collum)
		{
			bresenham(*start, end, collum, window);
			start->x = end.x;
		}
		if (line)
		{
			end.y += 10;
			bresenham(*start, end, collum, window);
			end.y  -= 10;
		}
		end.x += 10;
		collum = collum->next;
	}
	start->x = temp_x;
	start->y += 10;
}

void	render(t_window *window)
{
	t_lines *line;
	t_map_pointer *collum;
	t_draw_point start;
	t_draw_point end;
	

	line = window->map->map_lines;
	start.y = (window->sizey / 2) + window->map_image.position_y;
	while (line)
	{
		start.x = (window->sizex / 2) + window->map_image.position_x;
		collum = line->pointer;
		end = start;
		end.y += 10;
		bresenham(start, end, collum, window);
		draw(&start, line, collum, window);
		line = line->next;
	}
	draw(&start, line, collum, window);
}
