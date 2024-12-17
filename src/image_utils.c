/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:11:07 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/17 19:41:01 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_image(t_data *data)
{
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img)
	{
		ft_printf("Error in creating the image");
		ft_exit_fractol(data);
	}
	data->addr = mlx_get_data_addr(
		data->img, //specifies the image to use
		&data->bits_per_pixel, //the number of pixels needed to represent a pixel colour
		&data->line_length, //the number of bytes userd to store one line of the imahe in memory
		&data->endian
	);
	if (!data)
	{
		ft_printf("Error: failed to get image address and set param.");
		ft_exit_fractol(data);
	}
	data->bytes_per_pixel = data->bits_per_pixel / 8;
}
void	my_mlx_put_pixel(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = NULL;
	if (x >= 0 && x <= WIN_WIDTH && y >= 0 && y <= WIN_HEIGHT)
		pixel = data->addr + (y * data->line_length + x * data->bytes_per_pixel); 
	*(unsigned int*)pixel = color;
}
