/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:56:26 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/15 19:00:26 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_in_bulb(double x, double y)
{
	double	p;
	double	q;

	p = sqrt(((x - 0.25) * (x - 0.25)) + (y * y));
	q = p - (2 * (p * p)) + 0.25;
	if (x < q)
		return (1);
	if ((((x + 1) * (x + 1) + y * y)) < (1.0 / 16.0))
		return (1);
	return (0);
}

static void	calculate_iterator(t_m_struct *data, t_complex *z)
{
	t_fractal	*f;

	f = &data->f;
	if (f->fractal_type == 2 && is_in_bulb(z->real, z->im))
	{
		f->iter = MAX_ITER;
		f->magnitude = 0.0;
		return ;
	}
	f->magnitude = 0.0;
	f->iter = 0;
	f->z = *z;
	while (f->iter < MAX_ITER && (f->magnitude < 4))
	{
		f->iteration_f(data, &(f->z), z);
		f->magnitude = (f->z.real * f->z.real) + (f->z.im * f->z.im);
		f->iter++;
	}
	if (f->iter < MAX_ITER)
		f->smooth_iter = f->iter + 1.0 - log(log(f->magnitude)) / log(2.0);
	else
		f->smooth_iter = data->f.iter;
}

void	set_color(t_m_struct *data, t_complex *z)
{
	calculate_iterator(data, z);
	set_gradient(data);
}

int	render(t_m_struct *data)
{
	if (!data->request_render)
		return (0);
	data->request_render = 0;
	view_draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win, data->image.data, 0, 0);
	return (1);
}
