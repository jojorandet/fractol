/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:28:10 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/20 14:28:50 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	request_render(t_m_struct *data)
{
	data->request_render = 1;
	return (0);
}

void	view_draw(t_m_struct *data)
{
	int			x;
	int			y;
	t_complex	z;
	double		real;
	double		im;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		im = data->view.imag_coords[y];
		x = 0;
		while (x < WIN_WIDTH)
		{
			real = data->view.real_coords[x];
			z.real = real;
			z.im = im;
			set_color(data, &z);
			put_pixel_to_image(data, x, y);
			x++;
		}
		y++;
	}
}

void	view_update(t_m_struct *data)
{
	int		i;
	t_view	*view;
	double	real_offset;
	double	im_offset;

	view = &data->view;
	view->pixel_to_complex = view->scale / data->image.pixels_per_line;
	real_offset = -view->center_x * view->pixel_to_complex;
	im_offset = view->center_y * view->pixel_to_complex;
	i = 0;
	while (i < WIN_WIDTH)
	{
		view->real_coords[i] = i * view->pixel_to_complex + real_offset;
		i++;
	}
	i = 0;
	while (i < WIN_HEIGHT)
	{
		view->imag_coords[i] = -i * view->pixel_to_complex + im_offset;
		i++;
	}
	request_render(data);
}

void	view_init(t_m_struct *data)
{
	data->view.center_x = data->f.center_x;
	data->view.center_y = data->f.center_y;
	data->view.scale = SCALE;
	view_update(data);
}
