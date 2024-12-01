/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:44:00 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/01 03:07:53 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

#include "../parse/parser.h"

#define CREATE_DISPLAY_FAIL "Fail set up connection to the graphical system\n"
#define FAIL_GET_SCREEN_SIZE "Fail get screen size"
#define CREATE_WINDOW_FAIL "No Success to create window"
#define INIT_HOOK_FAIL "Init Hook Fail"

typedef struct s_window
{
	void	*mlx;
	void	*win;

	int		sizex;
	int		sizey;
	
	t_map * map;
}	t_window;


void	free_pointer(void **pointer);

void	init_window(t_map *map);
int		free_window(t_window *window);


void	free_hook(t_window **window);
int		init_hook(t_window *window);
#endif