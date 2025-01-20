/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:16:39 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/20 14:31:31 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_image(t_m_struct *data, int x, int y)
{
	char		*dst;
	long		pixel_offset;
	t_myimage	*img;

	img = &data->image;
	pixel_offset = y * img->size_line + x * img->bytespp;
	if (pixel_offset >= (img->total_bytes))
	{
		ft_printf("Out of bounds. Total bytes: %d, offset: %ld, x: %d, y: %d\n", \
			img->total_bytes, pixel_offset, x, y);
		ft_exit_fractol(data, "Error: offset larger than image buffer.\n");
	}
	dst = img->addr + pixel_offset;
	*(unsigned int *)dst = data->final_color;
}

void	init_img(t_m_struct *data)
{
	t_myimage	*img;

	img = &data->image;
	img->data = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->image.data)
	{
		ft_exit_fractol(data, "Error: initalise the image_data pointer\n");
		return ;
	}
	img->addr = mlx_get_data_addr(
			img->data,
			&img->bitspp,
			&img->size_line,
			&img->endian);
	if (!img->addr)
	{
		ft_exit_fractol(data, "Error: getting the address of the image");
		return ;
	}
	img->bytespp = img->bitspp / 8;
	img->pixels_per_line = img->size_line / img->bytespp;
	img->total_bytes = img->size_line * WIN_HEIGHT;
}
