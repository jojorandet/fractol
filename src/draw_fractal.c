/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:50:57 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/15 19:42:48 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	julia(t_m_struct *data, t_complex *z, t_complex *c)
{
	double	temp;

	(void)c;
	temp = (z->real * z->real) - (z->im * z->im) + data->f.c_constant.real;
	z->im = 2.0 * (z->real * z->im) + data->f.c_constant.im;
	z->real = temp;
}

static void	mandelbrot(t_m_struct *data, t_complex *z, t_complex *c)
{
	double	temp;

	(void)data;
	temp = (z->real * z->real) - (z->im * z->im) + c->real;
	z->im = 2.0 * (z->real * z->im) + c->im;
	z->real = temp;
}

static void tricorn(t_m_struct *data, t_complex *z, t_complex *c)
{
	double temp_real;
	double temp_im;

	(void)data;
	temp_real = z->real * z->real - z->im * z->im + c->real;
	temp_im = -2.0 * z->real * z->im + c->im;  // Key difference is the negative sign here
	z->real = temp_real;
	z->im = temp_im;
}

void	fractal_set(t_m_struct *data)
{
	t_fractal	*f;

	f = &data->f;
	f->center_x = WIN_WIDTH / 2;
	f->center_y = WIN_HEIGHT / 2;
	if (f->fractal_type == 1)
	{
		f->c_constant.real = -0.78;
		f->c_constant.im = -0.105;
		f->iteration_f = julia;
	}
	if (f->fractal_type == 2)
	{
		f->center_x = 2 * (WIN_WIDTH / 3);
		f->iteration_f = mandelbrot;
	}
	if (f->fractal_type == 3)
	{
		f->center_x = WIN_WIDTH / 2;
		f->center_y = WIN_HEIGHT / 2;
		data->view.scale = SCALE * 2;
		f->iteration_f = tricorn;
	}
}
