/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:33:00 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/17 20:08:00 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_colour_test(t_complex z)
{
	if (z.real > 0 && z.imag > 0)
		return (0x00ff00);
	else if (z.real > 0 && z.imag < 0)
		return (0x0000ff);
	else if (z.real < 0 &&  z.imag < 0)
		return (0xffff00);
	return (0xff0000);
}
void	draw(t_data *data)
{
	view_draw(data, get_colour_test);
}