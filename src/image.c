/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:11:07 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/13 22:54:28 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	init_image(t_data *data)
{
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img)
	{
		ft_printf("Error in creating the image");
		exit(EXIT_FAILURE);
	}
	data->addr = mlx_get_data_addr(
		data->img, //specifies the image to use
		&data->bpp, //the number of pixels needed to represent a pixel colour
		&data->line_length, //the number of bytes userd to store one line of the imahe in memory
		&data->endian
	);
	if (!data)
	{
		ft_printf("Error: failed to get image address and set param.");
		exit(EXIT_FAILURE);
	}
	data->bytes_per_pixel = data->bpp / 8;
}

void	my_mlx_put_pixel(t_data *data, int x, int y, int color)
{
	char	*pixel;
	long	offset;

	offset = (y * data->line_length + x * data->bytes_per_pixel);
	pixel = data->addr + offset;
	*(unsigned int*)pixel = color;
}