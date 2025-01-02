/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:28:10 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/02 15:27:25 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	view_draw(t_data *data) //void(*get_color)(void))
{
	int 		x;
	int 		y;
	int			color;
	t_complex	z;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while(x < WIN_WIDTH)
		{
			z.real = (x - data->view.center_x) * data->view.pixel_to_view;
			z.im = -(y - data->view.center_y) * data->view.pixel_to_view;
			color = draw_square(data, z);
			put_pixel_to_image(data, x, y, color);
			x++;
		}
		y++;
	}
	printf("for x: %d and y: %d, the z.real is: %f and the z.imag is %f", x, y, data->z.real, data->z.im);
}

void	view_init(t_data *data)
{
	if (!data)
		ft_exit_fractol(data, "data is NULL");
	printf("entering the view_init function\n\n");
	data->view.center_x = WIN_WIDTH / 2;
	data->view.center_y = WIN_HEIGHT / 2;
	data->view.scale = SCALE;

	data->view.view_to_pixel = data->image.pixels_per_line / data->view.scale;
	data->view.pixel_to_view = data->view.scale / data->image.pixels_per_line;

	printf("center_x: %d\n", data->view.center_x);
	printf("center_y: %d\n", data->view.center_y);
	printf("scale: %.2f\n", data->view.scale);
	printf("view_to_pixel: %.2f\n", data->view.view_to_pixel);
	printf("pixel_to_view: %.3f\n", data->view.pixel_to_view);
	printf("successfully initialised view.\n");
}
