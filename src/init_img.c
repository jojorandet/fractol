/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:16:39 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/23 17:59:43 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	test_draw_square(t_data *data, int x, int y, int color)
{
	
}

void	put_pixel_to_image(t_data *data, int x, int y, int color)
{
	char	*dst;
	long	pixel_offset;
	t_img	*img;

	img = &data->image; //we assign the address ot the structure to the img pointer
	pixel_offset = (y * img->bytes_per_row + (x * img->bytespp)); //transfer from 2d to 1d
	if (pixel_offset > (img->total_bytes));
		ft_exit_fractol(data, "Error: offset larger than image buffer.");
	dst = img->addr + pixel_offset; //move the dest pointer in the 1 d array
	*(unsigned int*)dst = color; // Write the color value to the pixel's memory location
}

void	init_img(t_data *data)
{
	data->image.img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->image.img)
	{
		ft_exit_fractol(data, "Error: initalise the img pointer");
		return ;
	}
	data->image.addr =  mlx_get_data_addr(
			data->image.img,
			data->image.bitspp,
			data->image.bytes_per_row,
			data->image.endian);
	if (!data->image.addr)
	{
		ft_exit_fractol(data, "Error: getting the address of the image");
		return ; 
	}
	data->image.bytespp = data->image.bitspp / 8; // one byte is made of 8 bits
	data->image.pixels_per_line = data->image.bytes_per_row / data->image.bytespp;
	data->image.total_bytes = data->image.bytes_per_row * WIN_HEIGHT;
}
