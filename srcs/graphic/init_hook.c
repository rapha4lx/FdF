/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:58:32 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/04 20:28:47 by rferro-d         ###   ########.fr       */
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
	{
		window->map_image.position_x -= 10;
		mlx_clear_window(window->mlx, window->win);
		render(window);
	}
	else if (keycode == 119)
	{
		window->map_image.position_y -= 10;
		mlx_clear_window(window->mlx, window->win);
		render(window);
	}
	else if (keycode == 115)
	{
		window->map_image.position_y += 10;
		mlx_clear_window(window->mlx, window->win);
		render(window);
	}
	else if (keycode == 100)
	{
		window->map_image.position_x += 10;
		mlx_clear_window(window->mlx, window->win);
		render(window);
	}
	ft_putnbr_fd(keycode, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

int	init_hook(t_window *window)
{
	if (!mlx_hook(window->win, ON_KEYDOWN, KeyPressMask, keyboard_hook, window))
		return (0);
	if (!mlx_hook(window->win, ON_DESTROY, NoEventMask,
			close_from_button, window))
		return (0);
	// if (!mlx_hook(window->win, ON_MOUSEDOWN, ButtonPressMask,
	// 		set_mouse_down, &window->mouse))
	// 	return (0);
	// if (!mlx_hook(window->win, ON_MOUSEUP, ButtonPressMask,
	// 		set_mouse_up, &window->mouse))
	// 	return (0);
	return (1);
}
