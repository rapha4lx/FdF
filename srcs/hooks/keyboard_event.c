/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:03:46 by rferro-d          #+#    #+#             */
/*   Updated: 2025/01/02 19:37:17 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../imports/minilibx-linux/mlx.h"
#include "../graphic/graphic.h"
#include "hooks.h"

static void	change_zoom(int keycode, t_window *window);

static int	position_key_event(int keycode, void *window)
{
	if (keycode == 97)
		((t_window *)window)->map_image.position.x -= 10;
	else if (keycode == 119)
		((t_window *)window)->map_image.position.y -= 10;
	else if (keycode == 115)
		((t_window *)window)->map_image.position.y += 10;
	else if (keycode == 100)
		((t_window *)window)->map_image.position.x += 10;
	else if (keycode == 122 || keycode == 120)
		change_zoom(keycode, window);
	else
		return (0);
	return (1);
}

int	keyboard_hook(int keycode, void *window)
{
	if (position_key_event(keycode, window))
		return (0);
	else if (keycode == 65361)
		((t_window *)window)->map_image.rotation.x -= 0.02f;
	else if (keycode == 65363)
		((t_window *)window)->map_image.rotation.x += 0.02f;
	else if (keycode == 65362)
		((t_window *)window)->map_image.rotation.y += 0.02f;
	else if (keycode == 65364)
		((t_window *)window)->map_image.rotation.y -= 0.02f;
	else if (keycode == 53 || keycode == 65307)
		return (mlx_loop_end(((t_window *)window)->mlx));
	return (0);
}

static void	change_zoom(int keycode, t_window *window)
{
	if (keycode == 122 && window->map_image.zoom < 27)
		window->map_image.zoom++;
	else if (keycode == 120 && window->map_image.zoom > 1)
		window->map_image.zoom--;
}
