/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: showoff <showoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:15:23 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/18 22:02:46 by showoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "graphic.h"

float mod(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

float max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	apply_zoom(t_point *point, int zoom)
{
	point->x = point->x * zoom;
	point->y = point->y * zoom;
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}	

void	move(t_point *point, int zoom, t_window *window)
{
	point->x = (window->sizex / 2) - (window->map->map_width * zoom) + point->x;
	point->y = (window->sizey / 2) - (window->map->map_height * zoom) + point->y;
}