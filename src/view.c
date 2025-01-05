/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:28:10 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/04 17:43:07 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	view_draw(t_main *data) //void(*get_color)(void))
{
	int			x;
	int			y;
	t_complex	z;
	int			color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		z.im = data->view.y[y];
		x = 0;
		while (x < WIN_WIDTH)
		{
			z.real = data->view.x[x];
			color = draw_square(data, z);
			put_pixel_to_image(data, x, y, color);
			x++;
		}
		y++;
	}
}

void	view_init(t_main *data)
{
	if (!data)
		ft_exit_fractol(data, "data is NULL");
	data->view.center_x = WIN_WIDTH / 2;
	data->view.center_y = WIN_HEIGHT / 2;
	data->view.scale = SCALE;
	view_update(data);
}

void	view_update(t_main *data)
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
		view->y[i] = (i - view->center_y) * view->pixel_to_view;
		i++;
	}
	render(data);
}
