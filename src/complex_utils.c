/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:44:41 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/18 16:41:21 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	add_complex(t_complex *z1, t_complex *z2)
{
	return (t_complex){
		.real = z1->real + z2->real,
		.imag = z1->imag + z2->imag,
	};
}

t_complex	mult_complex(t_complex *z1, t_complex *z2)
{
	return (t_complex){
		.real = (z1->real * z2->real) - (z1->imag * z2->imag),
		.imag = (z1->real * z2->imag) + (z1->imag * z2->real),
	};
}

double	magnitude_complex(t_complex *z1)
{
	return ((z1->real * z1->real) + (z1->imag * z1->imag));
}




