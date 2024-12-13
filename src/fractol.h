/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:44:01 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/13 18:10:31 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>


# define WIN_WIDTH 400
# define WIN_HEIGHT 400

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

typedef struct s_data
{
	void	*mlx; 
	// pointer of system
	void	*win;
	//pointer to the window created
	void	*img; 
	//poiter to the image created by mlx_new_image
	char	*addr;
	// address of the pixel data in the image 
	int		bpp; 
	//number of bits per pixel (32) image depth
	int		bytes_per_pixel; 
	// number of bytes per pixel (/8)
	int		line_length; 
	//number of bytes in a row of the image including padding
	int		endian;	
	//big endian or little format, especially for RGB
}	t_data;

void	my_mlx_put_pixel(t_data *data, int x, int y, int color);
void	init_image(t_data *data);
void	init_data(t_data *data);
void	initialisation_mlx(t_data *data);
void	*ft_memset(void	*b, int c, size_t len);
int		ft_exit_fractol(t_data *data);
int		ft_keyboard(int key, t_data *data);

#endif