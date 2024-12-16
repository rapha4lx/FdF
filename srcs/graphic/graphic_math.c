/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:15:23 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/16 02:50:02 by rferro-d         ###   ########.fr       */
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
	*x = (*x - *y) * cos(0.8) * z;
	*y = (*x + *y) * sin(0.8) * z;
}	

void	rotate(t_point *point, t_point rotate)
{
	point->x += rotate.x;
	point->y += rotate.y;
}