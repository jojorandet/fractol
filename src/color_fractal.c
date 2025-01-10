/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:08:17 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/10 20:16:51 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	select_palette(t_m_struct *data)
{
	t_fractal *f;

	f = &data->f;
	if (f->magnitude < 4)
		return (data->colours.a); // white
	if (f->bailout_value < 5)
		return (data->colours.b);
	if (f->bailout_value < 20)
		return (data->colours.c);
	if (f->bailout_value < 35)
		return (data->colours.d);
	return (data->colours.e);
}

void	init_colour(t_m_struct *data)
{
	data->colours.a = 0xededf4;
	data->colours.b = 0xF3752B;
	data->colours.c = 0xf79d5c;
	data->colours.d = 0xf52f57;
	data->colours.e = 0xa20021;
}