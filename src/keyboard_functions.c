/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:30:14 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/14 13:43:08 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_keyboard(int key, t_data *data)
{
	(void)data;
	int x;
	int y;
	int colour = 0xA42A04;

	x = 100;
	y = 100;
	if(key == KEY_A)
	{
		while (y < 300)
		{
			x = 100 + (y - 100);
			while (x < 300 - (y - 100))
			{
				mlx_pixel_put(data->mlx, data->win, x, y, colour);
				x++;
				colour++;
			}
			y++;
		}
	}
	ft_printf("KEY : %d\n", key);
	return (0);
}



/*while (x < 300)//line
{
	mlx_pixel_put(data->mlx, data->win, x, y, colour);
	x++;
	colour--;
}*/
/*while (x < 300)
{
	mlx_pixel_put(data->mlx, data->win, x, y, colour);
	x++;
	colour--;
}
while (y < 300)
{
	mlx_pixel_put(data->mlx, data->win, x, y, colour);
	y++;
	colour--;
}
while (x > 100)
{
	mlx_pixel_put(data->mlx, data->win, x, y, colour);
	x--;
	colour--;
}
while (y > 100)
{
	mlx_pixel_put(data->mlx, data->win, x, y, colour);
	y--;
	colour--;
}*/