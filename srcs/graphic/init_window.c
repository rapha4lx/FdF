/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:43:38 by rferro-d          #+#    #+#             */
/*   Updated: 2024/11/30 23:09:07 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "../../imports/minilibx-linux/mlx.h"
#include <stdlib.h>

void	free_pointer(void **pointer)
{
	if (!(*pointer))
		return ;
	free((*pointer));
	(*pointer) = NULL;
}

void	free_window(t_window *window)
{
	mlx_clear_window(window->mlx, window->win);
	mlx_destroy_window(window->mlx, window->win);
	free_pointer(&window->win);
	mlx_destroy_display(window->mlx);
	free_pointer(&window->mlx);
}

void	init_window(void)
{
	t_window	*window;

	window = (t_window*)malloc(sizeof(t_window));
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, 300, 300, "FdF");
	init_hook(&window);
	mlx_loop(window->mlx);
}
