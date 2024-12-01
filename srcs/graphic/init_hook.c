/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:58:32 by rferro-d          #+#    #+#             */
/*   Updated: 2024/11/30 23:42:35 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse/parser.h"
#include "graphic.h"
#include "keys.h"
#include "../../imports/minilibx-linux/mlx.h"

#include <unistd.h>

// void	free_hook(void)
// {
	
// }

int		close_window(int keycode, t_window *window)
{
	(void)keycode;
	free_window(window);
	write(1,"key\n", 4);
	return (0);
}

void	init_hook(t_window *window)
{
	mlx_hook(window->win, 2, KeyPressMask, close_window, window);
}
