/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:08:17 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/13 14:39:36 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static unsigned char	gradient(unsigned char color_a, unsigned char color_b, double ratio)
{
	return (color_a  + (color_b - color_a) * ratio);
}

static int	color_interpol(t_color color_a, t_color color_b, float ratio)
{
	t_color color;

	color.value = 0;
	color.r = gradient(color_a.r, color_b.r, ratio);
	color.g = gradient(color_a.g, color_b.g, ratio);
	color.b = gradient(color_a.b, color_b.b, ratio);
	color.a = 0;

	return (color.value);
}

void	set_gradient(t_m_struct *data)
{
	t_fractal	*f;
	t_colors	*color;
	double		i;
	double		t;
	int			colour_index;

	f = &(data->f);
	color = &(data->colors);
	i = f->smooth_iter;
	if (f->magnitude < 4) // it will automatically color in the right color 
	{
		data->final_color = color->a.value;
		return ;
	}
	t = (i - floor(i)); // floor will calculate the largestinteger calue that is not greater than x so here we get the fractional part 
	colour_index = (int)floor(i) % 4;
	if (colour_index == 0)
		data->final_color = color_interpol(color->e, color->d, t);
	else if (colour_index == 1)
		data->final_color = color_interpol(color->d, color->c, t);
	else if (colour_index == 2)
		data->final_color = color_interpol(color->c, color->b, t);
	else
		data->final_color = color->b.value;
}
void	init_color(t_m_struct *data)
{
	data->colors.a.value = 0x19381F;
	data->colors.b.value = 0xeee82c;
	data->colors.c.value = 0x91cb3e;
	data->colors.d.value = 0x53a548;
	data->colors.e.value = 0x4c934c;
}