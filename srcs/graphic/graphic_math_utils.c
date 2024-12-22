/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_math_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:16:35 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/21 21:17:58 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

float	mod(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

float	max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}
