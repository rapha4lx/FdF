/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:58:32 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/01 03:22:16 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse/parser.h"
#include "graphic.h"
#include "keys.h"
#include "../../imports/minilibx-linux/mlx.h"

#include <unistd.h>

static int		close_from_button(t_window *window)
{
	mlx_loop_end(window->mlx);
	return (0);
}

static int		keyboard_hook(int keycode, t_window *window)
{
	if (keycode == 53 || keycode == 65307)
		return (free_window(window));
	return (0);
}

int	init_hook(t_window *window)
{
	if (!mlx_hook(window->win, ON_KEYDOWN, KeyPressMask, keyboard_hook, window))
		return (0);
	if (!mlx_hook(window->win, ON_DESTROY, NoEventMask, close_from_button, window))
		return (0);
	return (1);
}
