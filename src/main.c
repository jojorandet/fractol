/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:49:05 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/13 18:15:28 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	(void)av;
	init_data(&data);
	initialisation_mlx(&data);
	init_image(&data);

	my_mlx_put_pixel(&data, 5, 5, 0x0000ff00);
	my_mlx_put_pixel(&data, 7, 5, 0x00ff0000);

	mlx_put_image_to_window(data.mlx, data.win, data.img, WIN_WIDTH, WIN_HEIGHT);
	mlx_hook(data.win, 17, 0, ft_exit_fractol, &data);
	mlx_hook(data.win, 2, 1L << 0, ft_keyboard, &data);
	mlx_loop(data.mlx);

	if (DEBUG_MODE)
		printf("mode debug enabled\n");

	return (0);
}
