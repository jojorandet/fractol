/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:49:05 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/17 19:15:45 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*void	parse_arguments(int argc, char **argv, t_data *data)
{
	if (argc < 2)
	{
		ft_putendl_fd("Not enough arguments", 1);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1], "mandel", 6) == 0)
		data->fractal_type = 1;
	if (ft_strncmp(argv[1], "julia", 5))
	{
		if (argc < 4)
		{
			ft_putendl_fd("Not enough arguments: include julia, real part, complex part", 1);
			exit(EXIT_FAILURE);
		}
		data->fractal_type = 2;
	}
}*/

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	(void)argv;
	init_data(&data);
	init_mlx(&data);
	init_image(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, WIN_WIDTH, WIN_HEIGHT);
	setup_hooks(&data);
	mlx_loop(data.mlx);

	if (DEBUG_MODE)
		printf("mode debug enabled\n");
	return (0);
}
