/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:56:26 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/10 20:17:20 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	magnitude(t_complex z)
{
 	return(z.real * z.real) + (z.im * z.im);
}

static void	calculate_iterator(t_m_struct *data, t_complex *z)
{
	data->f.magnitude = 0.0;
	data->f.bailout_value = 0.0;
	data->f.z = *z;
	while ( data->f.bailout_value < MAX_ITER && (data->f.magnitude < 4))
	{
		data->f.iteration_f(data, &(data->f.z), z);
		data->f.magnitude = magnitude(data->f.z);
		data->f.bailout_value++;
	}
}

int	get_color(t_m_struct *data, t_complex *z) // it might be a good idea to have the iteration in a structure so I can pass it around
{
	int		color;
	
	calculate_iterator(data, z); //bailouit value is a double in this case 
	color = select_palette(data);
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
