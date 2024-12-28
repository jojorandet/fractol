/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:28:10 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/28 21:36:40 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


/*void	view_draw(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0; //for now, then it will take coordinates
	//i had pixels, but now with my viewport, I have a 
	
	//as i go from left to right etc. I will go pixel by pixel and with a function determine if i can colour or not
	//nested while loop
	//start from the top corner (0,0)
}*/

/*void	draw_lines(t_data *data)
{
	
}*/

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