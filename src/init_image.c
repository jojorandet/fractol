/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:31:47 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/19 23:15:01 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_image(t_data *data)
{
	data->img = malloc(sizeof(data));
	if (!data->img)
	{
		ft_printf("Error in malloc of the image");
		ft_exit_fractol(data);
	}
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	// mlx new image only takes care of the raw image buffer without any additional metadata
	if (!data->img)
	{
		ft_printf("Error in creating the image");
		ft_exit_fractol(data);
	}
	data->addr = mlx_get_data_addr(
		data->img,			   // specifies the image to use
		&data->bits_per_pixel, // the number of pixels needed to represent a pixel colour
		&data->bytes_per_line,	   // the number of bytes userd to store one line of the imahe in memory
		&data->endian);
	if (!data)
	{
		ft_printf("Error: failed to get image address and set param.");
		ft_exit_fractol(data);
	}
	data->bytes_per_pixel = data->bits_per_pixel / 8;
	data->pixels_per_line = data->bytes_per_line / data->bytes_per_pixel;
	init_view(data);
}