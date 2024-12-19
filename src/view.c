/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:34:11 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/19 23:20:46 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


t_viewport	init_view(t_data *data)
{
	t_viewport *view;

	data->view.center_x = (WIN_WIDTH/2);
	data->view.center_y = (WIN_HEIGHT/2);
	data->view.scale = SCALE;
	data->view.pixel_to_view = data->view.scale / data->pixels_per_line; // 8 / 400 = 0.05
	data->view.view_to_pixel = data->pixels_per_line / data->view.scale; // 400/8 = 0.02
	printf("scale is %d\n", SCALE);
	printf("pixels per line is %d\n", data->pixels_per_line);
	printf("ratio from pixel to viewport is %f\n", data->view.pixel_to_view);
	
}

void	view_draw(t_data *data, int (*get_colour)(t_complex))
{
	int	x;
	int	y;
	int colour;
	t_complex z;

	y = 0;
	
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH )
		{
			z.real = (x - data->view.center_x) * data->view.pixel_to_view;
			z.imag = -(y - data->view.center_y) * data->view.pixel_to_view;
			colour = get_colour(z);
			put_pixel_to_image(data, x, y, colour);
			x++;
		}
		y++;
	}
}

/*void	put_pixel_to_view(t_data *data, double x, double y, int color)
{
	int	image_x;
	int	image_y;

	image_x = data->view.center_x + (x * data->view.view_to_pixel);
	image_y = data->view.center_y - (y * data->view.view_to_pixel);
	my_mlx_put_pixel(data,image_x, image_y, color);
}*/

