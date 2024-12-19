/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:44:01 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/19 16:39:45 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "ft_printf.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>


# define WIN_WIDTH 400
# define WIN_HEIGHT 400

# define SCALE 8

# define KEY_A 97
# define KEY_B 98
# define KEY_C 99
# define KEY_D 100
# define KEY_E 101
# define KEY_F 102
# define KEY_G 103
# define KEY_H 104
# define KEY_I 105
# define KEY_J 106
# define KEY_K 107
# define KEY_L 108
# define KEY_M 109
# define KEY_N 110
# define KEY_O 111
# define KEY_P 112
# define KEY_Q 113
# define KEY_R 114
# define KEY_S 115
# define KEY_T 116
# define KEY_U 117
# define KEY_V 118
# define KEY_W 119
# define KEY_X 120
# define KEY_Y 121
# define KEY_Z 122

# define ERROR_MLX "Error creating the mlx pointer\n"
# define ERROR_WIN "Error creating the win pointer\n"

/* ************************************************************************** */
/*								DEBUG										  */
/* ************************************************************************** */

# ifndef DEBUG_MODE
#  define DEBUG_MODE 1
# endif


enum
{
	MOUSE_LEFT = 1,
	MOUSE_RIGHT = 2,
	MOUSE_MIDDLE = 3, 
	MOUSE_SCROLL_UP = 4,
	MOUSE_SCROLL_DOWN = 5,
};

enum
{
	KEY_PRESSED = 2,
	KEY_RELEASED = 3,
	MOUSE_PRESSED = 4,
	MOUSE_RELEASED = 5,
	MOUSE_MOVE = 6,
	WINDOW_CLOSED = 17,

};
typedef	struct s_viewport
{
	int			center_x;
	int			center_y;
	double		scale;
	double		view_to_pixel;	
	double		pixel_to_view;
	double		left;
	double		right;
	double		top;
	double		bottom;
}	t_viewport;

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_data
{
	int		fractal_type; // 1 = Mandelbrot 2 = Julia 3 = ship
	
	void	*mlx; 
	// pointer of system
	void	*win;
	//pointer to the window created
	void	*img; 
	//poiter to the image created by mlx_new_image
	char	*addr;
	// address of the pixel data in the image 
	int		bits_per_pixel; 
	//number of bits per pixel (32) image depth
	int		bytes_per_pixel; 
	// number of bytes per pixel (/8)
	int		line_length; 
	//number of bytes in a row of the image including padding
	int		endian;	
	//big endian or little format, especially for RGB
	t_complex	c;

	t_viewport	view;
	//complex number used for calculations
	int			max_iterations;
	//the max number of iterations for fractals 
	int			default_colour;

	int			redraw_frame;
}	t_data;


void		init_data(t_data *data);
void		*ft_memset(void	*b, int c, size_t len);
void		init_mlx(t_data *data);
void		init_image(t_data *data);
void		draw(t_data *data);
void		view_draw(t_data *data, int (*get_colour)(t_complex));
void		put_pixel_to_image(t_data *data, int x, int y, int color);
void		put_pixel_to_view(t_data *data, double x, double y, int color);
int			get_colour_test(t_complex z);
int			get_colour_test_damier(t_complex z);
t_complex	add_complex(t_complex *z1, t_complex *z2);
t_complex	mult_complex(t_complex *z1, t_complex *z2);
double		magnitude_complex(t_complex *z1);
void		setup_hooks(t_data *data);
int			ft_exit_fractol(t_data *data);
void		cleanup(t_data *data);

#endif

/*int		ft_redraw_frame(t_data *data);
void	ft_draw(t_data *data);*/