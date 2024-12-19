/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:33:00 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/19 14:44:42 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//higher level rendering functions like draw, get colour etc

/*int get_colour_test_damier(t_complex z)
{
    // Get the parity of the real and imaginary parts
    int real_parity = (int)(z.real) % 2;
    int image_parity = (int)(z.imag) % 2;

    // Check if both real and imaginary parts have the same parity
    if (real_parity == image_parity)
        return (0xffffff);  // White square
    else
        return (0x000000);  // Colored square
}*/

int		get_colour_test_damier(t_complex z)
{
	int	real_parity = (int)(z.real) % 2;
	int	image_parity = (int)(z.imag) % 2;
	
	if (real_parity < 0)
		real_parity = -real_parity;
	if (image_parity < 0)
		image_parity = -image_parity;
	if (real_parity == image_parity)
	{
		if (z.real * z.imag >= 0)
			return (0);
		else
			return (0xffffff);
	}
	else 
	{
		if (z.real * z.imag >= 0)
			return (0xffffff);
		else 
			return (0);
	}
	return (0);
}


/*int	get_colour_test(t_complex z)
{
	if (z.real > 0 && z.imag > 0)
		return (0x00ff00);
	else if (z.real > 0 && z.imag < 0)
		return (0x0000ff);
	else if (z.real < 0 &&  z.imag < 0)
		return (0xffff00);
	return (0xff0000);
}*/
// this function determines the colour of a poixel based on the test logic. 
void	draw(t_data *data)
{
	view_draw(data, get_colour_test_damier);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}