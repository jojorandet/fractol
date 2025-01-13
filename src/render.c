/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:56:26 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/13 12:10:31 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	magnitude(t_complex z) // i access drectly inside mzy strucutre i do not need to de reference it 
{
 	return(z.real * z.real) + (z.im * z.im);
}

static int	is_in_bulb(double x, double y)
{
	double	p;
	double	q;

	p = sqrt(((x - 0.25) * (x - 0.25)) + (y * y));
	q = p - (2 * (p * p)) + 0.25;
	if (x < q) // main bulb 
		return (1);
	if ((((x + 1) * (x + 1) + y * y)) < (1.0 / 16.0))
		return (1);
	return (0);
}

static void	calculate_iterator(t_m_struct *data, t_complex *z)
{
	if (data->f.fractal_type == 2 && is_in_bulb(z->real, z->im)) // i send the dereferencement of my poiter z (access the structure )
	{
		data->f.iter = MAX_ITER;
		data->f.magnitude = 0.0; //means that it will not calculate it 
		return ; // go back to the set color and the iteration gets calculated accordingly 
	}
	data->f.magnitude = 0.0;
	data->f.iter = 0;
	data->f.z = *z;
	while ( data->f.iter < MAX_ITER && (data->f.magnitude < 4))
	{
		data->f.iteration_f(data, &(data->f.z), z);
		data->f.magnitude = magnitude(data->f.z);
		data->f.iter++; // bailout value is updated un thge structure while i am below max iter and my magnitud eis below 4 
	}
}

void	set_color(t_m_struct *data, t_complex *z) // it might be a good idea to have the iteration in a structure so I can pass it around
{
	calculate_iterator(data, z); //bailouit value is a double in this case 
	set_gradient(data);
}

void	render(t_m_struct *data)
{
	view_draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win, data->image.data, 0, 0);
}


//the final_colour depends on whether we are bounded or not
// if it diverges, I will give it a color according to the value. 
// i could have a table of colours
//shade1 shade2 shade3 shade4 etc/ and do a full table and accoridng to the
//amount of iterations, i will be at a certain whole i of the table 
//this will give me the final_colour i am looking for/ 
