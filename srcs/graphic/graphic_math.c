/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:15:23 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/02 17:32:27 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


