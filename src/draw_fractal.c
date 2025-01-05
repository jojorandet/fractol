/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:50:57 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/05 11:59:13 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*int	color_fractal(t_data *data, t_complex z)
{
	
}*/

int	draw_square(t_complex z) //t_m_struct *data)
{
	if (z.im > -1 && z.im < 1 && z.real > -1 && z.real < 1)
		return (0xff0000);
	else
		return (0x000000);
}
