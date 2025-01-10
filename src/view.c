/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:28:10 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/10 17:54:18 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	view_draw(t_m_struct *data)
{
	int			x;
	int			y;
	t_complex	z;
	int			color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		z.im = data->view.imag_coords[y];
		x = 0;
		while (x < WIN_WIDTH)
		{
			z.real = data->view.real_coords[x];
			//color = draw_square(z);
			color = get_color(data, &z);
			put_pixel_to_image(data, x, y, color);
			x++;
		}
		y++;
	}
}

void	view_update(t_m_struct *data)
{
	int		i;
	t_view	*view;

	view = &data->view;
	view->pixel_to_complex = view->scale / data->image.pixels_per_line;
	i = 0;
	while (i < WIN_WIDTH)
	{
		view->real_coords[i] = (i - view->center_x) * view->pixel_to_complex;
		i++;
	}
	i = 0;
	while (i < WIN_HEIGHT)
	{
		view->imag_coords[i] = -(i - view->center_y) * view->pixel_to_complex;
		i++;
	}
	render(data);
}

void	view_init(t_m_struct *data) // view init depends on the result oif tge fractal set 
{
	if (!data)
		ft_exit_fractol(data, "data is NULL");
	data->view.center_x = data->f.center_x;
	data->view.center_y = data->f.center_y;
	data->view.scale = SCALE;
	view_update(data);
}