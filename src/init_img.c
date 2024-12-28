/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:16:39 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/28 20:16:24 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	test_draw_square(t_data *data, int x, int y, int color)
{
	int square_end_x;
	int square_end_y;
	int	start_x;
	int square_size;

	square_size = 50;
	square_end_x = check_limit_upper(x + square_size, WIN_WIDTH);
	square_end_y = check_limit_upper(y + square_size, WIN_HEIGHT);
	while (y < square_end_y)
	{
		start_x = x;
		while (start_x < square_end_x)
		{
			put_pixel_to_image(data, start_x, y, color);
			start_x++;
		}
		y++;
	}
}

void	put_pixel_to_image(t_data *data, int x, int y, int color)
{
	char	*dst;
	long	pixel_offset;
	t_img	*img;

	img = &data->image; //img will replace this (shorter, line too long)
	pixel_offset = y * img->bytes_per_row + x * img->bytespp; //transfer from 2d to 1d, for example y = 3 and x = 5: (4*100 + 5*4 = 420)
	if (pixel_offset >= (img->total_bytes))
	{
		ft_printf("Out of bounds. Total bytes: %d, offset: %d, x: %d, y: %d", img->total_bytes, pixel_offset, x, y);
		ft_exit_fractol(data, "Error: offset larger than image buffer.");
	}
	dst = img->addr + pixel_offset; //move the dest pointer in the 1 d array from 0 to the 420th address
	*(unsigned int*)dst = color; // Write the color value to the pixel's memory location
}

void	init_img(t_data *data)
{
	data->image.img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT); //need to create an image which serves as the canvas for the rest
	if (!data->image.img) // img is a pointer to the img buffer. it is initialised in here 
	{
		ft_exit_fractol(data, "Error: initalise the img pointer");
		return ;
	}
	data->image.addr =  mlx_get_data_addr( //this is the pointer to the begining of the dimage buffer 
			data->image.img, // img is the pointer to the high level image.
			&data->image.bitspp, //tells us ehow many bits, in this case 32 are contained in one pixel, 4 bytes
			&data->image.bytes_per_row, // how many bytes per row or per line 
			&data->image.endian); //from side to side which is the least significant byte
	if (!data->image.addr)
	{
		ft_exit_fractol(data, "Error: getting the address of the image");
		return ; 
	}
	data->image.bytespp = data->image.bitspp / 8; // one byte is made of 8 bits
	data->image.pixels_per_line = data->image.bytes_per_row / data->image.bytespp;
	data->image.total_bytes = data->image.bytes_per_row * WIN_HEIGHT; //in memory represented as one singular space in memory. If a coordinate is above or below 
	//the allocated memory, there is an error. it would be a memory error. 
}

//each dot represents a byte, so a pixel. 
/*--------------------------*/
/*                          */
/*---------------------------*/