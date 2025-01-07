/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:31:28 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/07 18:08:42 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
//# include "ft_printf.h
# include <stdio.h>
# include <math.h>



# ifdef __APPLE__ // if it detects we are on mac
# include <mlx.h>
# define WIN_WIDTH 800
# define WIN_HEIGHT 800 //to do: check why this does not update
# define SCALE 4

enum // events for macos 
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};
enum // mouse clicks for macos 
{
	LEFT_CLICK = 1,
	RIGHT_CLICK = 2,
	MIDDLE_CLICK = 3,
	SCROLL_BACKWARD = 4,
	SCROLL_FORWARD = 5,
};
enum
{
	K_W = 13,
	K_S = 1,
	K_LEFT = 124,
	K_UP = 125
	K_RIGHT = 123,
	K_DOWN = 126,
};



# elif __linux__ 
#	include <mlx.h>
#	include <X11/X.h>
#	define WIN_WIDTH 800
#	define WIN_HEIGHT 800
#	define SCALE 4
#	define ZOOM 0.2
#	define COL_TAB_SIZE 16
#	define PI 3.1432

enum // events for macos 
{
	ON_KEYDOWN		= KeyPress,
	ON_KEYUP		= KeyRelease,
	ON_MOUSEDOWN	= ButtonPress,
	ON_MOUSEUP		= ButtonRelease,
	ON_MOUSEMOVE	= MotionNotify,
	ON_EXPOSE		= Expose,
	ON_DESTROY		= DestroyNotify,
};

enum // mouse clicks for macos 
{
	M_LEFT_CLICK		= 1,
	M_RIGHT_CLICK		= 2,
	M_MIDDLE_CLICK		= 3,
	M_SCROLL_BACKWARD	= 4,
	M_SCROLL_FORWARD	= 5,
};

enum
{
	K_W		= 119,
	K_S		= 115,
	K_LEFT	= 65361,
	K_UP	= 65362,
	K_RIGHT	= 65363,
	K_DOWN	= 65364,
	K_ESCP	= 65307,
};
# endif




typedef struct s_complex
{
	double real;
	double im;
}	t_complex;


typedef struct s_view
{
	int		center_x;
	int		center_y;
	double	real_coords[WIN_WIDTH];
	double	imag_coords[WIN_HEIGHT];
	double	scale;
	double	pixel_to_complex;
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
}	t_myimage;


typedef	struct s_fractal
{
	int			fractal_type;
	t_complex	c_center;
	t_complex 	c_julia;
	int			iter_limit;
	double		bailout_value;
	void		(*iteration)(t_complex *z, t_complex *c); // function pointer for the rest of the fractal 
}	t_fractal;


typedef struct s_m_struct
{
	void		*mlx_ptr; //a void pointer that contains the base_address returned by mlx_init() 
	void		*win;
	t_myimage	image;
	t_view		view;
	t_fractal	f;
	
}	t_m_struct;

void	fractal_set(t_m_struct *data);
void	init_data(t_m_struct *data);
void	init_img(t_m_struct *data);

void	event_mouse_init(t_m_struct *data);
void	events_keys_init(t_m_struct *data);
int		handle_mouse_down(int mouse_down, int x, int y, t_m_struct *data);
int		handle_key_down(int key_code, t_m_struct *data);

void	put_pixel_to_image(t_m_struct *data, int x, int y, int color);
void	view_init(t_m_struct *data);
void	view_update(t_m_struct *data);
void	render(t_m_struct *data);
void	view_draw(t_m_struct *data);
int		draw_square(t_complex z);

void	zoom(t_m_struct *data, int x, int y, double zoom);


//int	check_limit_upper(int value, int limit_upper);
//int check_limit_lower(int value, int limit_lower);
float	ft_atof(char *s);

void	ft_exit_fractol(t_m_struct *data, char *error);



#endif