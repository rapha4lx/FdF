/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:44:00 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/16 01:22:38 by rferro-d         ###   ########.fr       */
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

typedef struct s_point
{
	float x;
	float y;
	int z;
}	t_point;

typedef struct s_image
{
	void	*img_ptr;
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;

	int		zoom;
	int		last_zoom;
	t_point	rotation;
	t_point	position;

	t_point	last_rotation;
	t_point	last_position;
}	t_image;

typedef struct s_window
{
	void	*mlx;
	void	*win;

	int		sizex;
	int		sizey;
	t_map	*map;
	t_mouse	mouse;
	int		Key_event_count;
	t_image map_image;
}	t_window;


void	free_pointer(void **pointer);

void	init_window(t_map *map);
int		free_window(t_window *window);


void	free_hook(t_window **window);
int		init_hook(t_window *window);

int		init_images(t_window *window);
void	free_images(t_window *window);
void	render(t_window *window);
void	clear_pixels(t_window *window);



void	apply_zoom(int *i, int zoom);
void	isometric(float *x, float *y, int z);









#endif