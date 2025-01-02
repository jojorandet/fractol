/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:16:39 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/02 15:03:00 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


/*void	test_draw_grid(t_data *data, int x, int x, int color)
{
	//to make it shoter, center_x is equal to data->view.center_x
	//same for center_y

	//then I do one while thing for the x lines (vertical) and one for the y (horizontal)
	//void	put_pixel_to_image(t_data *data, int x, int y, int color)
	//to draw a line, i will always have the same x for different ys and the same y for different xs

	//with x = 0
	//while x is smaller than win width, then i will send putpixel(data, int x, center_y, in this case 400 (x will be 0 and increase))
	//pixel_offset = y * img->bytes_per_line + x * img->bytespp;
	//center_y will always stay the same SO: pixel offset = center_y(400) * ??? bytesperrow but i dont know what is it
}*/

void	put_pixel_to_image(t_data *data, int x, int y, int color)
{
	char	*dst;
	long	pixel_offset;
	t_img	*img;

	img = &data->image;
	pixel_offset = y * img->size_line + x * img->bytespp;
	if (pixel_offset >= (img->total_bytes))
	{
		printf("Out of bounds. Total bytes: %d, offset: %ld, x: %d, y: %d\n", img->total_bytes, pixel_offset, x, y);
		ft_exit_fractol(data, "Error: offset larger than image buffer.\n");
	}
	dst = img->addr + pixel_offset;
	*(unsigned int*)dst = color;
}

void	init_img(t_data *data)
{
	data->image.img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT); //need to create an image which serves as the canvas for the rest
	if (!data->image.img) // img is a pointer to the img buffer. it is initialised in here 
	{
		ft_exit_fractol(data, "Error: initalise the img pointer\n");
		return ;
	}
	data->image.addr =  mlx_get_data_addr( //this is the pointer to the begining of the dimage buffer 
			data->image.img, // img is the pointer to the high level image.
			&data->image.bitspp, //tells us ehow many bits, in this case 32 are contained in one pixel, 4 bytes
			&data->image.size_line, // how many bytes per row or per line 
			&data->image.endian); //from side to side which is the least significant byte
	if (!data->image.addr)
	{
		ft_exit_fractol(data, "Error: getting the address of the image");
		return ; 
	}
	data->image.bytespp = data->image.bitspp / 8; // one byte is made of 8 bits
	data->image.pixels_per_line = data->image.size_line / data->image.bytespp;
	data->image.total_bytes = data->image.size_line * WIN_HEIGHT; //in memory represented as one singular space in memory. If a coordinate is above or below 
}
