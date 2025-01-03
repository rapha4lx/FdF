/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:55:13 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/21 21:06:17 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

typedef struct s_mouse
{
	int		button_one;
	int		button_two;
	int		mouse_pos_x;
	int		mouse_pos_y;
}	t_mouse;

int		set_mouse_down(int code, int x, int y, void *window);
int		set_mouse_up(int code, int x, int y, void *window);
int		set_mouse_move_event(int x, int y, void *window);

int		keyboard_hook(int keycode, void *window);

#endif