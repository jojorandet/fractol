/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:33:00 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/14 17:48:30 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
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
	if (!data->addr)
	{
		ft_printf("Error: failed to get image address and set param.");
		ft_exit_fractol(data);
	}
	ft_draw_fractal(&data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	ft_redraw_frame(t_data *data)
{
	if (data->redraw_frame == 1)
		ft_draw_fractal(&data);
	return (0);
}