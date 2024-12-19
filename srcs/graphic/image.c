/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: showoff <showoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 00:58:02 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/18 13:51:57 by showoff          ###   ########.fr       */
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
	window->map_image.position.x = 0;
	window->map_image.position.y = 0;
	window->map_image.last_rotation.x = 0;
	window->map_image.last_rotation.y = 0;
	window->map_image.last_position.x = 0;
	window->map_image.last_position.y = 0;
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