/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:56:26 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/08 18:03:07 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	magnitude(t_complex z)
{
 	return(z.real * z.real) + (z.im * z.im);
}

int	calculate_fractal_color(t_m_struct *data, t_complex *z)
{
	int	color;

	color = 0;
	data->f.magnitude = 0.0;
	data->f.bailout_value = 0.0;
	data->f.z = *z;
	while ( data->f.bailout_value < MAX_ITER && (4) && (data->f.magnitude < 4))
	{
		data->f.iteration_f(data, &(data->f.z), z);
		data->f.magnitude = magnitude(data->f.z);
		data->f.bailout_value++;
	}
	if (data->f.magnitude < 4)
		color = (0x000000);
	if (data->f.magnitude > 4)
		color = (0xffffff);
	return (color);
}

int	get_color(t_m_struct *data, t_complex *z) // it might be a good idea to have the iteration in a structure so I can pass it around
{
	int		color;
	
	color = calculate_fractal_color(data, z); //bailouit value is a double in this case 
	//color = get_gradient(data);
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
