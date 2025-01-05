/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:31:28 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/04 17:36:37 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
//# include "ft_printf.h"
# include <mlx.h>
# include <stdio.h>
# include <math.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 800 //to do: check why this does not update
# define SCALE 4

enum // events 
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 				4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};
enum // mouse clicks 
{
	LEFT_CLICK = 1,
	RIGHT_CLICK = 2,
	MIDDLE_CLICK = 3,
	SCROLL_BACKWARD = 4,
	SCROLL_FORWARD = 5,
};
typedef struct s_complex
{
	double real;
	double im;
}	t_complex;

typedef struct s_fractal
{
	char	*name; // name of fracta
	//int		base_iteration; //the initial number of iterations when the program is launched 
	//ensures we have enough iterations at the base level
	int		max_iterations; //max iterations will depend on the zoom level.
	double	scale;
}	t_fractal;

typedef struct s_view
{
	int		center_x;
	int		center_y;
	double	x[WIN_WIDTH];
	double	y[WIN_HEIGHT];
	double	scale;
	double	pixel_to_view;
}	t_view;

typedef struct s_image
{
	void	*data;
	void	*addr;
	int		bitspp; // how many bits per pixel
	int		bytespp; // how many bytes per pixel, 8 bits in 1 byte, 32/8 = 4
	int		total_bytes;
	int		pixels_per_line;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_main
{
	void	*mlx_ptr; //a void pointer that contains the base_address returned by mlx_init() 
	void	*win;
	t_image	image;
	t_view	view;
	t_complex z;
	t_fractal fractal;
	
}	t_main;

void	init_data(t_main *data);
void	init_img(t_main *data);

void	event_init(t_main *data);
int		handle_key_down(int key_code, t_main *data);
int		handle_mouse_down(int mouse_down, int x, int y, t_main *data);


void	put_pixel_to_image(t_main *data, int x, int y, int color);
void	view_init(t_main *data);
void	view_update(t_main *data);
void	render(t_main *data);
void	view_draw(t_main *data);
int		draw_square(t_main *data, t_complex z);


//int	check_limit_upper(int value, int limit_upper);
//int check_limit_lower(int value, int limit_lower);


void	ft_exit_fractol(t_main *data, char *error);

#endif