/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:58:32 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/01 17:45:02 by rferro-d         ###   ########.fr       */
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
		return (free_window(window));
	return (0);
}

int	init_hook(t_window *window)
{
	if (!mlx_hook(window->win, ON_KEYDOWN, KeyPressMask, keyboard_hook, window))
		return (0);
	ft_putstr("SUCCESS keyboard_hook\n");
	if (!mlx_hook(window->win, ON_DESTROY, NoEventMask,
			close_from_button, window))
		return (0);
	ft_putstr("SUCCESS close_from_button\n");
	if (!mlx_hook(window->win, ON_MOUSEDOWN, Button1MotionMask,
			set_mouse_down, &window->mouse))
		return (0);
	ft_putstr("SUCCESS mouse_down\n");
	if (!mlx_hook(window->win, ON_MOUSEUP, Button1MotionMask,
			set_mouse_up, &window->mouse))
		return (0);
	ft_putstr("SUCCESS mouse_up\n");
	return (1);
}
