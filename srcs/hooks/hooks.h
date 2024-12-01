/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:55:13 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/01 17:31:08 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

typedef struct s_mouse
{
	int		click_active;
	int		mouse_pos_x;
	int		mouse_pos_y;
}	t_mouse;

int		set_mouse_down(t_mouse *mouse);
int		set_mouse_up(t_mouse *mouse);
int		mouse_move_event(void *window);


#endif