/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:28:10 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/29 17:40:01 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//i will go through my entire image. i will need to calculate the real and the imaginary part
	//z.real is the equivalent of x
	//z.imag is the equivalent of y

	//data I have : center_x and center_y which will serve as a base 
	// I will have to first calculate with the pixels, and then translate it back to view
	//use the view to pixel ratio
void	view_draw(t_data *data, void(*get_color)(void))
{
	//now that I have the z.real and imag

	int			x;
	int			y;
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
			color = getcolor(z); // i will get an int value, rgb which will colour the pixel
			put_pixel_to_image(data, x, y, color);
			
			//the complex coordinates are only used for the math part. 
			// pixel put to image works directly with the pixel and will colour the pixel using the offset calculation
			//the pixel will be coloured according to the calculations done in the fractal space. 
		}
	}

}



void	view_init(t_data *data)
{
	if (!data)
		ft_exit_fractol(data, "data is NULL");
	ft_printf("entering the view_init function\n\n");
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

//done for the initialization part of the view. all data is given a value the guests have arrived to the restaurant