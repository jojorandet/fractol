/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:08:17 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/15 18:42:44 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static unsigned char	gradient(unsigned char a, unsigned char b, double r)
{
	return ((unsigned char)(a + ((int)b - (int)a) * r));
}

static int	color_interpol(t_color color_a, t_color color_b, float ratio)
{
	t_color	color;

	ratio = ratio * ratio * ratio * (3 - 2 * ratio);
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
	if (f->magnitude < 4)
	{
		data->final_color = color->a.value;
		return ;
	}
	t = (i - floor(i));
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
	static int				colour_index = 0;
	static const t_colors	palettes[5] = {
	{{0x000000}, {0xFF1493}, {0x8B008B}, {0x4B0082}, {0x800080}},
	{{0xced4da}, {0xadb5bd}, {0x6c757d}, {0x343a40}, {0x212529}},
	{{0x03071e}, {0x370617}, {0x6a040f}, {0xd00000}, {0x9d0208}},
	{{0x051923}, {0x003554}, {0x006494}, {0x00a6fb}, {0x0582ca}},
	{{0x000000}, {0x4169E1}, {0xDF73FF}, {0x8A2BE2}, {0x7B68EE}}
	};

	if (colour_index == 5)
		colour_index = 0;
	data->colors = palettes[colour_index++];
}
