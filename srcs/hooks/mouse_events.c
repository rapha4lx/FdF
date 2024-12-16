/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:50:47 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/15 15:17:20 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphic/graphic.h"

#include <unistd.h>

#include <stdio.h>

int	set_mouse_down(int code, int x, int y, void *window)
{
	printf("buttond: %d \\ posX: %d \\ posY: %d\n",
	code, x, y);

	if (code == 1)
		((t_window*)window)->mouse.button_one = 1;
	else if (code == 1)
		((t_window*)window)->mouse.button_two = 1;
	((t_window*)window)->mouse.mouse_pos_x = x;
	((t_window*)window)->mouse.mouse_pos_y = y;	
	return (1);
}

int	set_mouse_up(int code, int x, int y, void *window)
{
	printf("up: %d \\ posX: %d \\ posY: %d\n",
	code, x, y);
	if (code == 1)
		((t_window*)window)->mouse.button_one = 0;
	else if (code == 1)
		((t_window*)window)->mouse.button_two = 0; 
	return (1);
}

static void	mouse_button_one_event(int x, int y, void *window)
{
	if (x > ((t_window*)window)->mouse.mouse_pos_x)
		((t_window*)window)->map_image.position.x += 1;
	else if (x < ((t_window*)window)->mouse.mouse_pos_x)
		((t_window*)window)->map_image.position.x -= 1;

	if (y > ((t_window*)window)->mouse.mouse_pos_y)
		((t_window*)window)->map_image.position.y += 1;
	else if (y < ((t_window*)window)->mouse.mouse_pos_y)
		((t_window*)window)->map_image.position.y -= 1;

	((t_window*)window)->mouse.mouse_pos_x = x;
	((t_window*)window)->mouse.mouse_pos_y = y;
}

static void	mouse_button_two_event(int x, int y, void *window)
{
	if (x > ((t_window*)window)->mouse.mouse_pos_x)
		((t_window*)window)->map_image.rotation.x += 1;
	else if (x < ((t_window*)window)->mouse.mouse_pos_x)
		((t_window*)window)->map_image.rotation.x -= 1;

	if (y > ((t_window*)window)->mouse.mouse_pos_y)
		((t_window*)window)->map_image.rotation.y += 1;
	else if (y < ((t_window*)window)->mouse.mouse_pos_y)
		((t_window*)window)->map_image.rotation.y -= 1;

	((t_window*)window)->mouse.mouse_pos_x = x;
	((t_window*)window)->mouse.mouse_pos_y = y;
}

int		set_mouse_move_event(int x, int y, void *window)
{
	printf("move: posX: %d \\ posY: %d\n",
	x, y);
	
	if (((t_window*)window)->mouse.button_one)
		mouse_button_one_event(x, y, window);
	else if (((t_window*)window)->mouse.button_one)
		mouse_button_two_event(x, y, window);
	return (1);
}
