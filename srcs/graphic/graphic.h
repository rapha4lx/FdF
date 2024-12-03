/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:44:00 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/02 17:32:42 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H
# include "../parse/parser.h"
# include "../hooks/hooks.h"

# define CREATE_DISPLAY_FAIL "Fail set up connection to the graphical system\n"
# define FAIL_GET_SCREEN_SIZE "Fail get screen size"
# define CREATE_WINDOW_FAIL "No Success to create window"
# define INIT_HOOK_FAIL "Init Hook Fail"

// # define MAX(a, b) (((a > b) * a) + ((a < b) * b))
// # define MAX(a, b) (a > b ? a : b)
// # define MOD(a) (((a > 0) * a) + ((a < 0) * (-a))) 
// # define MOD(a) ((a < 0) ? -a : a) 

float mod(float i);
float max(float a, float b);

typedef struct s_draw_point
{
	int x;
	int y;
}	t_draw_point;

typedef struct s_image
{
	void	*img_ptr;
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
	int		zoom;
}	t_image;

typedef struct s_window
{
	void	*mlx;
	void	*win;

	int		sizex;
	int		sizey;
	t_map	*map;
	t_mouse	mouse;
	t_image map_image;
	t_image	panel_image;
}	t_window;


void	free_pointer(void **pointer);

void	init_window(t_map *map);
int		free_window(t_window *window);


void	free_hook(t_window **window);
int		init_hook(t_window *window);

int		init_images(t_window *window);
void	free_images(t_window *window);
void	render(t_window *window);

void	apply_zoom(int *i, int zoom);









#endif