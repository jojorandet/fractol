/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:28:10 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/05 14:22:30 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	view_draw(t_m_struct *data) //void(*get_color)(void))
{
	int			x;
	int			y;
	t_complex	z;
	int			color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		z.im = data->view.y[y]; //all the values in this are the imaginary view coordinates 
		x = 0;
		while (x < WIN_WIDTH)
		{
			z.real = data->view.x[x]; //according to the ppixel where I am, I already calculated the z.real for all the xs
			color = draw_square(z); //this takes the z.real and z.imag
			put_pixel_to_image(data, x, y, color);
			x++;
		}
		y++;
	}
}

void	view_init(t_m_struct *data)
{
	if (!data)
		ft_exit_fractol(data, "data is NULL");
	data->view.center_x = WIN_WIDTH / 2;
	data->view.center_y = WIN_HEIGHT / 2;
	data->view.scale = SCALE;
	view_update(data);
}

void	view_update(t_m_struct *data)
{
	int		i;
	t_view	*view;

	view = &data->view;
	view->pixel_to_view = view->scale / data->image.pixels_per_line;
	i = 0;
	while (i < WIN_WIDTH)
	{
		view->x[i] = (i - view->center_x) * view->pixel_to_view;
		i++;
	}
	i = 0;
	while (i < WIN_HEIGHT)
	{
		view->y[i] = -(i - view->center_y) * view->pixel_to_view;
		i++;
	}
	render(data);
}
