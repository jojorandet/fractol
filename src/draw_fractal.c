/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:50:57 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/04 17:35:41 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*int	color_fractal(t_data *data, t_complex z)
{
	
}*/

int	draw_square(t_main *data, t_complex z)
{
	if (z.im > -1 && z.im < 1 && z.real > -1 && z.real < 1)
		return (0xff0000);
	else
		return (0x000000);
}
