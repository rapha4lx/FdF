/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:58:32 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/21 22:14:17 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../imports/libft/libft.h"
#include "../../imports/minilibx-linux/mlx.h"
#include "../hooks/hooks.h"
#include "../parse/parser.h"
#include "graphic.h"
#include "keys.h"

static int	close_from_button(t_window *window)
{
	mlx_loop_end(window->mlx);
	return (0);
}

static int	check_last_render(t_window *window)
{
	if (window->map_image.last_position.x != window->map_image.position.x)
		return (0);
	if (window->map_image.last_position.y != window->map_image.position.y)
		return (0);
	if (window->map_image.rotation.x != window->map_image.last_rotation.x)
		return (0);
	if (window->map_image.last_rotation.y != window->map_image.rotation.y)
		return (0);
	if (window->map_image.zoom != window->map_image.last_zoom)
		return (0);
	return (1);
}

static int	loop_render(t_window *window)
{
	t_point		point;

	if (check_last_render(window))
		return (0);
	clear_pixels(window);
	render(window);
	point.x = 10;
	point.y = 10;
	draw_string(&point, "positionX: ", ft_itoa(window->map_image.position.x),
		window);
	draw_string(&point, "positionY: ", ft_itoa(window->map_image.position.y),
		window);
	draw_string(&point, "rotationX: ", ft_itoa(window->map_image.rotation.x),
		window);
	draw_string(&point, "rotationY: ", ft_itoa(window->map_image.rotation.x),
		window);
	draw_string(&point, "zoom: ", ft_itoa(window->map_image.zoom), window);
	draw_string(&point, "sizeX: ", ft_itoa(window->sizex), window);
	draw_string(&point, "sizeY: ", ft_itoa(window->sizey), window);
	return (1);
}

int	init_hook(t_window *window)
{
	mlx_loop_hook(window->mlx, loop_render, window);
	if (!mlx_hook(window->win, ON_DESTROY, NoEventMask, &close_from_button,
			window))
		return (0);
	if (!mlx_hook(window->win, ON_KEYDOWN, KeyPressMask, &keyboard_hook,
			window))
		return (0);
	if (!mlx_hook(window->win, ON_MOUSEDOWN, ButtonPressMask, set_mouse_down,
			window))
		return (0);
	if (!mlx_hook(window->win, ON_MOUSEUP, ButtonReleaseMask, set_mouse_up,
			window))
		return (0);
	if (!mlx_hook(window->win, ON_MOUSEMOVE, PointerMotionMask,
			set_mouse_move_event, window))
		return (0);
	return (1);
}
