/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:43:38 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/21 21:00:22 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../imports/libft/libft.h"
#include "../../imports/minilibx-linux/mlx.h"
#include "graphic.h"
#include <stdlib.h>

int	free_window(t_window *window)
{
	free_images(window);
	if (window->mlx && window->win)
	{
		mlx_destroy_window(window->mlx, window->win);
		window->win = NULL;
	}
	return (1);
}

static int	init_display(t_window *window)
{
	window->mlx = mlx_init();
	if (!window->mlx)
	{
		ft_putstr(CREATE_DISPLAY_FAIL);
		return (0);
	}
	mlx_get_screen_size(window->mlx, &window->sizex,
		&window->sizey);
	if (window->sizex == -1 && window->sizey == -1)
	{
		mlx_destroy_display(window->mlx);
		free(window->mlx);
		ft_putstr(FAIL_GET_SCREEN_SIZE);
		return (0);
	}
	return (1);
}

void	init_window(t_map *map)
{
	t_window	window;

	window.map = map;
	window.sizex = -1;
	window.sizey = -1;
	if (!init_display(&window))
		return ;
	window.win = mlx_new_window(window.mlx, window.sizex,
			window.sizey, "FdF");
	if (!window.win)
	{
		mlx_destroy_display(window.mlx);
		return (ft_putstr(CREATE_WINDOW_FAIL));
	}
	if (init_hook(&window) && init_images(&window))
		mlx_loop(window.mlx);
	else
		ft_putstr(INIT_HOOK_FAIL);
	free_window(&window);
	mlx_destroy_display(window.mlx);
	free(window.mlx);
}
