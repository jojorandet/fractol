/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:49:05 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/14 16:32:57 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parse_arguments(int argc, char **argv, t_data *data)
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
	}
	
	
	

}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	(void)argv;
	data_init(&data);
	mlx_init(&data);
	image_init(&data);

	my_mlx_put_pixel(&data, 5, 5, 0x0000ff00);
	my_mlx_put_pixel(&data, 7, 5, 0x00ff0000);

	mlx_put_image_to_window(data.mlx, data.win, data.img, WIN_WIDTH, WIN_HEIGHT);
	mlx_hook(data.win, 17, 0, ft_exit_fractol, &data);
	mlx_hook(data.win, 2, 1L << 0, ft_keyboard, &data);
	mlx_mouse_hook(data.win, mlx_mouse_hook, &data);
	mlx_loop(data.mlx);

	if (DEBUG_MODE)
		printf("mode debug enabled\n");

	return (0);
}
