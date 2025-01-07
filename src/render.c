/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:56:26 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/07 18:09:43 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(t_m_struct *data, t_complex *z)
{
	int color;
	
	color = 0;
	calculate_fractal_color();
	get_gradient();
	return (color);
}

void	render(t_m_struct *data)
{
	view_draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win, data->image.data, 0, 0);
}


//the colour depends on whether we are bounded or not
// if it diverges, I will give it a color according to the value. 
// i could have a table of colours
//shade1 shade2 shade3 shade4 etc/ and do a full table and accoridng to the
//amount of iterations, i will be at a certain whole i of the table 
//this will give me the colour i am looking for/ 
