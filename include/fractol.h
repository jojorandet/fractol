/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:31:28 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/29 19:27:12 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include <mlx.h>
# include <stdio.h>
# include <math.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 800 //to do: check why this does not update
# define SCALE 4

typedef struct s_complex
{
	double real;
	double im;
}	t_complex;

typedef struct s_view
{
	int		center_x;
	int		center_y;
	double	scale;
	double	pixel_to_view;
	double	view_to_pixel;

}	t_view;

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bitspp; // how many bits per pixel
	int		bytespp; // how many bytes per pixel, 8 bits in 1 byte, 32/8 = 4
	int		total_bytes;
	int		pixels_per_line;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr; //a void pointer that contains the base_address returned by mlx_init() 
	void	*win;
	t_img	image;
	t_view	view;
	t_complex z;
	
}	t_data;

void	init_data(t_data *data);
void	init_img(t_data *data);
void	test_draw_square(t_data *data, int x, int y, int color);
void	put_pixel_to_image(t_data *data, int x, int y, int color);
void	view_init(t_data *data);
void	view_draw(t_data *data, int x, int y);
void	draw_grid(t_data *data);
//void	get_color(t_data *data);

int	check_limit_upper(int value, int limit_upper);
int check_limit_lower(int value, int limit_lower);


void	ft_exit_fractol(t_data *data, char *error);

#endif