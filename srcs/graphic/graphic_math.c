/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:15:23 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/16 01:22:45 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

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

void	apply_zoom(int *i, int zoom)
{
	*i = *i * zoom;
	(void)zoom; 
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}
