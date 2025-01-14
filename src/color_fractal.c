/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:08:17 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/14 19:36:40 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static unsigned char	gradient(unsigned char color_a, unsigned char color_b, double ratio)
{
	return (unsigned char)(color_a + ((int)color_b - (int)color_a) * ratio);
}

static int	color_interpol(t_color color_a, t_color color_b, float ratio)
{
	t_color color;

	ratio = ratio * ratio * ratio * (3 - 2 * ratio); // used the smoothstep interpolation 
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
	//t = t * t * (3 - 2 * t);
	colour_index = (int)floor(i) % 4;
	if (colour_index == 0)
		data->final_color = color_interpol(color->e, color->d, t);
	else if (colour_index == 1)
		data->final_color = color_interpol(color->d, color->c, t);
	else if (colour_index == 2)
		data->final_color = color_interpol(color->c, color->b, t);
	else
		data->final_color = color->d.value;
}

void	select_palette(t_m_struct *data)
{
	static int	colour_index = 0;

	static const t_colors palettes[5] = {
		{{0xced4da}, {0xadb5bd}, {0x6c757d}, {0x343a40}, {0x212529}},
		{{0x03071e}, {0x370617}, {0x6a040f}, {0x9d0208}, {0xd00000}},
		{{0x051923}, {0x003554}, {0x006494}, {0x0582ca}, {0x00a6fb}},
		{{0x000000}, {0xFF1493}, {0x8B008B}, {0x4B0082}, {0x800080}},
		{{0x000000}, {0xDF73FF}, {0x8A2BE2}, {0x4169E1}, {0x7B68EE}}
	};

	if (colour_index == 5)
		colour_index = 0;
	data->colors = palettes[colour_index++];
}