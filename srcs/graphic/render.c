/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:00:00 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/01 22:19:11 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "../../imports/minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

static int init_image(void* mlx, t_image *image, int width, int height)
{
	image->img_data = NULL;
	image->img_ptr = NULL;
	
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
	return (1);
}

void	free_images(t_window *window)
{
	if (window->map_image.img_ptr)
		mlx_destroy_image(window->mlx, window->map_image.img_ptr);
	
	if (window->panel_image.img_ptr)
		mlx_destroy_image(window->mlx, window->panel_image.img_ptr);
}

// void	render(t_window *window)
// {
// 	t_lines *line;
// 	t_map_pointer	*pointer;

	
// }