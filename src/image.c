/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:11:07 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/11 21:12:18 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	init_image(t_data *data)
{
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr(
		data->img,
		&data->bpp,
		&data->size_line, 
		&data->endian);
	data->bytes_per_pixel = data->bpp / 8;
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;
	long	offset;

	offset = (y * data->size_line + x * data->bytes_per_pixel);
	dst = data->addr + offset;
	*(unsigned int*)dst = color;
}