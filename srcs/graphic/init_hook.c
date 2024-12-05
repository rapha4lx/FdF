/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:58:32 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/05 20:28:21 by rferro-d         ###   ########.fr       */
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

static int	keyboard_hook(int keycode, t_window *window)
{
	if (keycode == 53 || keycode == 65307)
		return (mlx_loop_end(window->mlx));
	if (keycode == 97)
		window->map_image.position.x -= 10;
	else if (keycode == 119)
		window->map_image.position.y -= 10;
	else if (keycode == 115)
		window->map_image.position.y += 10;
	else if (keycode == 100)
		window->map_image.position.x += 10;
	else
	{
		ft_putnbr_fd(keycode, 1);
		ft_putchar_fd('\n', 1);
	}
	window->Key_event_count++;
	return (0);
}

static int	key_up(int keycode, t_window *window)
{
	if (window->Key_event_count < 3)
		return (0);
	ft_putstr("key_up\n");
	window->Key_event_count = 0;
	if (keycode == 97)
	{
		clear_pixels(window);
		render(window);
	}
	else if (keycode == 119)
	{
		clear_pixels(window);
		render(window);
	}
	else if (keycode == 115)
	{
		clear_pixels(window);
		render(window);
	}
	else if (keycode == 100)
	{
		clear_pixels(window);
		render(window);
	}
	return (0);
}

int	init_hook(t_window *window)
{
	mlx_key_hook(window->win, &key_up, window);

	if (!mlx_hook(window->win, ON_KEYDOWN, KeyPressMask, &keyboard_hook, window))
		return (0);
	if (!mlx_hook(window->win, ON_DESTROY, NoEventMask,
			&close_from_button, window))
		return (0);
	// if (!mlx_hook(window->win, KeyRelease, KeyReleaseMask, &key_up, window))
	// 	return (0);
	// if (!mlx_hook(window->win, ON_MOUSEDOWN, ButtonPressMask,
	// 		set_mouse_down, &window->mouse))
	// 	return (0);
	// if (!mlx_hook(window->win, ON_MOUSEUP, ButtonPressMask,
	// 		set_mouse_up, &window->mouse))
	// 	return (0);
	return (1);
}
