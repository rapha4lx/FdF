/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:50:47 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/01 17:32:57 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphic/graphic.h"

#include <unistd.h>

int	set_mouse_down(t_mouse *mouse)
{
	write(1, "mouse press\n", 13);
	mouse->click_active = 1;
	return (1);
}

int	set_mouse_up(t_mouse *mouse)
{
	write(1, "mouse up\n", 10);
	mouse->click_active = 0;
	return (1);
}

int	mouse_move_event(void *window)
{
	t_window	*win_ptr;

	win_ptr = (t_window *)window;
	if (!win_ptr->mouse.click_active)
		return (0);
	return (1);
}