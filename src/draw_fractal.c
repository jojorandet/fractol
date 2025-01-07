/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:50:57 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/07 17:54:36 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*static void	julia(t_m_struct *data, t_complex *z)
{
	double temp;
	
	temp = (z->real * z->real) - (z->im * z->im) + data->f.c_julia.real;
	z->im = 2.0 * (z->real * z->im) + data->f.c_julia.im;
	z->real = temp;
}

static void	mandelbrot(t_complex *z, t_complex *c)
	double temp;

	temp = (z->real * z->real) - (z->im * z->im) + c->real;
	z->im = 2.0 * (z->real * z->im) + c->im;
	z->real = temp;
}*/

int	draw_square(t_complex z)
{
	if (z.im > -1 && z.im < 1 && z.real > -1 && z.real < 1)
		return (0xff0000);
	else
		return (0x000000); // this is black 
}

//int	fractal_bound(t_m_struct *data, )

void	fractal_set(t_m_struct *data)
{
	t_fractal *f;
	
	f = &data->f;
	if (f->fractal_type < 1 || f->fractal_type > 3)
		ft_exit_fractol(data,"fractal type invvalid");
	if (f->fractal_type == 1)
	{
		f->c_julia.real = -0.75; //these values are set in case the user does not input them 
		f->c_julia.im = 0.0;
		f->c_center.real = 0.0; //the fractal has its own center
		f->c_center.im = 0.0;
	}
	if (f->fractal_type == 2)
	{
		f->c_center.real = -0.5;
		f->c_center.im = 0.0;
	}
}
