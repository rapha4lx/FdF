/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 00:58:02 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/20 15:23:02 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "../parse/parser.h"
#include <stdlib.h>
#include "../../imports/minilibx-linux/mlx.h"


int	init_images(t_window *window)
{
	window->map_image.img_data = NULL;
	window->map_image.img_ptr = NULL;
	window->map_image.zoom	= 10;
	window->map_image.rotation.x = 0;
	window->map_image.rotation.y = 0;
	window->map_image.last_rotation.x = 0;
	window->map_image.last_rotation.y = 0;


	int map_center_x = (window->map->map_width - 1) * window->map_image.zoom / 50.0;
	int map_center_y = (window->map->map_height - 1) * window->map_image.zoom / 50.0;

	window->map_image.position.x = (window->sizex / 2) - map_center_x;
	window->map_image.position.y = (window->sizey / 2) - map_center_y;
	
	window->map_image.last_position.x = window->map_image.position.x;
	window->map_image.last_position.y = window->map_image.position.y;

	window->map_image.img_ptr = mlx_new_image(window->mlx, window->sizex, window->sizey);
	if (!window->map_image.img_ptr)
		return (0);
	window->map_image.img_data = mlx_get_data_addr(window->map_image.img_ptr, &window->map_image.bpp,
		&window->map_image.size_line, &window->map_image.endian);
	if (!window->map_image.img_data)
		return (0);
	render(window);	
	return (1);
}

void	free_images(t_window *window)
{
	if (window->map_image.img_ptr)
		mlx_destroy_image(window->mlx, window->map_image.img_ptr);
}