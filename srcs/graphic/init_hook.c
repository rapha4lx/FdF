/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:58:32 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/16 01:45:30 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "../parse/parser.h"
#include "keys.h"
#include "../hooks/hooks.h"
#include "../../imports/minilibx-linux/mlx.h"
#include "../../imports/libft/libft.h"

static int	close_from_button(t_window *window)
{
	mlx_loop_end(window->mlx);
	return (0);
}

static int	keyboard_hook(int keycode, void *window)
{
    printf("Tecla pressed: %d\n", keycode);
	if (keycode == 53 || keycode == 65307)
		return (mlx_loop_end(((t_window*)window)->mlx));
	if (keycode == 97)
		((t_window*)window)->map_image.position.x -= 10;
	else if (keycode == 119)
		((t_window*)window)->map_image.position.y -= 10;
	else if (keycode == 115)
		((t_window*)window)->map_image.position.y += 10;
	else if (keycode == 100)
		((t_window*)window)->map_image.position.x += 10;
	else if (keycode == 122)
		((t_window*)window)->map_image.zoom += 10;
	else if (keycode == 120)
		((t_window*)window)->map_image.zoom -= 10;
	else if (keycode == 65361)
		((t_window*)window)->map_image.rotation.x -= 10;

	return (0);
}

static int	loop_render(t_window *window)
{
	// if ((window->map_image.last_position.x
	// 		== window->map_image.position.x
	// 	&& window->map_image.last_position.y
	// 		== window->map_image.position.y) 
	// 		&& (window->map_image.rotation.x
	// 		== window->map_image.last_rotation.x
	// 			&& window->map_image.last_rotation.y
	// 		== window->map_image.rotation.y)
	// 	)
	// 	return (0);
	// ft_putstr("loop\n");
	clear_pixels(window);
	render(window);

	mlx_string_put(window->mlx, window->win, 10, 10, 0xFFFFFF, "positionX: ");
	mlx_string_put(window->mlx, window->win, 70, 10, 0xFFFFFF, ft_itoa(window->map_image.position.x));
	
	mlx_string_put(window->mlx, window->win, 10, 30, 0xFFFFFF, "positionY: ");
	mlx_string_put(window->mlx, window->win, 70, 30, 0xFFFFFF, ft_itoa(window->map_image.position.y));

	mlx_string_put(window->mlx, window->win, 10, 50, 0xFFFFFF, "rotationX: ");
	mlx_string_put(window->mlx, window->win, 70, 50, 0xFFFFFF, ft_itoa(window->map_image.rotation.x));

	mlx_string_put(window->mlx, window->win, 10, 70, 0xFFFFFF, "rotationY: ");
	mlx_string_put(window->mlx, window->win, 70, 70, 0xFFFFFF, ft_itoa(window->map_image.rotation.y));
	
	mlx_string_put(window->mlx, window->win, 10, 90, 0xFFFFFF, "zoom: ");
	mlx_string_put(window->mlx, window->win, 70, 90, 0xFFFFFF, ft_itoa(window->map_image.zoom));
	
	return (1);
}

int	init_hook(t_window *window)
{	
	mlx_loop_hook(window->mlx, loop_render, window);
	if (!mlx_hook(window->win, ON_DESTROY, NoEventMask,
			&close_from_button, window))
		return (0);
	if (!mlx_hook(window->win, ON_KEYDOWN,
			KeyPressMask, &keyboard_hook, window))
		return (0);
	if (!mlx_hook(window->win, ON_MOUSEDOWN, ButtonPressMask,
			set_mouse_down, window))
		return (0);
	if (!mlx_hook(window->win, ON_MOUSEUP, ButtonReleaseMask,
			set_mouse_up, window))
		return (0);
	if (!mlx_hook(window->win, ON_MOUSEMOVE, PointerMotionMask,
			set_mouse_move_event, window))
		return (0);
	return (1);
}
