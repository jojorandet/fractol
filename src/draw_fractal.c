/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:50:57 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/05 18:51:26 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	julia(t_m_struct *data, t_complex *z, t_complex *c) // z and c are eau, it is the first point you are calculatijng (first itteration)
{
	double temp;

	(void *)c; // c is not used in this case 
	z = &data->z;
	temp = (z->real * z->real) - (z->im * z->im) + data->c.real; //we take c from what was given to us (a constant)
	z->im = 2.0 * (z->real * z->im) + data->c.im;
	z->real = temp;
} // z starts at a different point for all the calculations but c is independent pf this 

static void	mandelbrot(t_m_struct *data, t_complex *z, t_complex *c) // z and c are eau, it is the first point you are calculatijng (first itteration)
{
	double temp;

	(void *)data; //
	temp = (z->real * z->real) - (z->im * z->im) + c->real; //we take c from what was given to us (a constant)
	z->im = 2.0 * (z->real * z->im) + c->im;
	z->real = temp;
}
// in julia, the c is independent of where we are starting 



int	draw_square(t_complex z)
{
	if (z.im > -1 && z.im < 1 && z.real > -1 && z.real < 1)
		return (0xff0000);
	else
		return (0x000000);
}
