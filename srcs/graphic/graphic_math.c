/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:15:23 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/20 16:28:06 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "graphic.h"

// float mod(float i)
// {
// 	if (i < 0)
// 		return (-i);
// 	return (i);
// }

// float max(float a, float b)
// {
// 	if (a > b)
// 		return (a);
// 	return (b);
// }

void	apply_zoom(t_point *point, int zoom)
{
	point->x = point->x * zoom;
	point->y = point->y * zoom;
}

void	isometric(t_point *point, t_point *rotation, int zoom)
{
	float	previous_x;
	float	previous_y;
	float	rotated_y;
	float	rotated_z;
	float	rotated_x;

	previous_x = point->x;
	previous_y = point->y;
	// z *= graph->depth_factor;
	point->z *= zoom;
	rotated_y = previous_y * cos(rotation->y) - point->z * sin(rotation->y);
	rotated_z = previous_y * sin(rotation->y) + point->z * cos(rotation->y);
	rotated_x = previous_x * cos(rotation->x) + rotated_z * sin(rotation->x);
	rotated_z = -previous_x * sin(rotation->x) + rotated_z * cos(rotation->x);
	point->x = rotated_x;
	point->y = rotated_y;
}	

void	center_map(t_point *point, int zoom, t_window *window)
{
	point->x -=  (window->map->map_width - 1 ) * zoom / 2;
	point->y -=  (window->map->map_height - 1 ) * zoom / 2;
}

void	calc_move(t_point *start, t_point *end, t_point *position)
{
	start->x += (position->x);
	start->y += (position->y);
	end->x += (position->x);
	end->y += (position->y);
}