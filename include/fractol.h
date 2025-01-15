/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:31:28 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/15 16:17:51 by jrandet          ###   ########.fr       */
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
# include <time.h>



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
#	define MAX_ITER	250
#	define MIN_SCALE 1.5
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
	K_C		= 99,
	K_CTRL = 65507,
};
# endif

typedef	struct	s_hsl
{
	double hue;
	double sat;
	double light;
}	t_hsl;

typedef union
{
	int	value;
	struct
	{
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;
	};
}	t_color;


typedef	struct s_colors
{
	t_color a;
	t_color b;
	t_color c;
	t_color d;
	t_color e;
}	t_colors;

typedef struct s_complex
{
	double real;
	double im;
}	t_complex;

typedef struct s_view
{
	double	center_x;
	double 	center_y;
	double	real_coords[WIN_WIDTH];
	double	imag_coords[WIN_HEIGHT];
	double	scale;
	double	pixel_to_complex;
}	t_view;


typedef struct s_image
{
	void	*data;
	void	*addr;
	int		bitspp;
	int		bytespp;
	int		total_bytes;
	int		pixels_per_line;
	int		size_line;
	int		endian;
}	t_myimage;

typedef struct s_m_struct t_m_struct;

typedef	struct s_fractal
{
	int					fractal_type;
	double				center_x;
	double 				center_y;
	t_complex 			c_constant;
	void				(*iteration_f)(t_m_struct *data, t_complex *z, t_complex *c);
	int					iter; 
	double				magnitude;
	t_complex			z;
	double				smooth_iter;
}	t_fractal;

struct s_m_struct
{
	void		*mlx_ptr;
	void		*win;
	int 		final_color;
	int			request_render;
	int			is_control_pressed;
	t_myimage	image;
	t_view		view;
	t_fractal	f;
	t_colors	colors;
	
};

//intitialise and parse
void	fractal_set(t_m_struct *data);
void	init_img(t_m_struct *data);
void	select_palette(t_m_struct *data);
float	ft_atof(char *s);
int		ft_is_int(char *s);

//mouse
void	event_mouse_init(t_m_struct *data);
int		handle_mousemove(int x, int y, t_m_struct *data);
int		handle_mouse_down(int mouse_down, int x, int y, t_m_struct *data);

//keys
void	events_keys_init(t_m_struct *data);
int		handle_key_down(int key_code, t_m_struct *data);
int		handle_key_up(int key_code, t_m_struct *data);

//rendering
void	put_pixel_to_image(t_m_struct *data, int x, int y);
void	view_init(t_m_struct *data);
void	zoom(t_m_struct *data, int x, int y, double zoom);
void	view_update(t_m_struct *data);
int		request_render(t_m_struct *data);
int		render(t_m_struct *data);
void	view_draw(t_m_struct *data);
void	set_color(t_m_struct *data, t_complex *z);
void	set_gradient(t_m_struct *data);


void	ft_exit_fractol(t_m_struct *data, char *error);

#endif