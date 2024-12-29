/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:50:57 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/29 19:24:20 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*void	get_color(t_complex z)
{
	while ()
}*/

void	draw_grid(t_data *data)
{
	int y;
	int x;
	int space;

	space = 50;
	ft_printf("the grid function is entered\n\n");
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while(x < WIN_WIDTH)
		{
			put_pixel_to_image(data, x, y, 0xffff);
			x += space;
		}
		y++;
	}
	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			put_pixel_to_image(data, x, y, 0xffff);
			y += space;
		}
		x++;
	}
}