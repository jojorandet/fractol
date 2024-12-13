/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:44:41 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/13 23:43:26 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	add_complex(t_complex *z1, t_complex *z2)
{
	t_complex result;
	
	z1->real = z1->real + z2->real;
	z1->imag = z1->imag + z2->imag;
}

void	mult_complex(t_complex *z1, t_complex *z2)
{
	t_complex	result;

	z1->real = ((z1->real * z2->real) - (z2->imag * z2->imag));
	z1->imag = ((z1->real * z2->imag) + (z1->imag * z2->real));
}

void	add_complex(t_complex *z1)
{
	double	temp;

	temp = (z1->real * z1->real) - (z1->imag * z1->imag);
	z1->imag = 2.0 * z1->real * z1->imag;
	z1->real = temp;
}


