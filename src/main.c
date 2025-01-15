/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:35:33 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/15 19:14:56 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	output_help(void)
{
	ft_putstr_fd("ERROR IN INPUT!\n\n", 1);
	ft_putstr_fd("Usage: ./fractol [type] [c.real] [c.im]\n", 1);
	ft_putstr_fd("Types: [1]Julia [2]Mandelbrot\n\n", 1);
	ft_putstr_fd("Examples:\n", 1);
	ft_putstr_fd("./fractol 2          (Mandelbrot)\n", 1);
	ft_putstr_fd("./fractol 1 -0.4 0.6 (Julia)\n", 1);
	ft_putstr_fd("\nJulia: c values between -2 and 2\n", 1);
	return (0);
}

int	parse_arguments(t_m_struct *data, int argc, char **argv)
{
	int	i;

	if (argc < 2 || argc > 4)
		return (0);
	i = 1;
	while (argv[i] && i < argc)
	{
		if (!ft_is_int(argv[i]))
			return (0);
		i++;
	}
	data->f.fractal_type = ft_atoi(argv[1]);
	if (data->f.fractal_type < 1 || data->f.fractal_type > 3)
		return (0);
	if ((data->f.fractal_type == 2  || data->f.fractal_type == 3) && argc > 2)
		return (0);
	fractal_set(data);
	if (data->f.fractal_type == 1 && argc == 4)
	{
		data->f.c_constant.real = ft_atof(argv[2]);
		data->f.c_constant.im = ft_atof(argv[3]);
	}
	return (1);
}

int	init_fractol(t_m_struct *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_exit_fractol(data, "Error: Mlx unitialized, SGV!\n");
	data->win = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "test");
	if (!data->win)
		ft_exit_fractol(data, "Error: Win not initialized, SGV\n!");
	select_palette(data);
	init_img(data);
	return (1);
}

int	main(int argc, char **argv)
{
	t_m_struct	data;

	ft_bzero(&data, sizeof(t_m_struct));
	if (!parse_arguments(&data, argc, argv))
		return (output_help());
	if (!init_fractol(&data))
		ft_exit_fractol(&data, "Failed to initialise fractol.");
	view_init(&data);
	event_mouse_init(&data);
	events_keys_init(&data);
	mlx_hook(data.win, DestroyNotify, 0, handle_destroy, &data);
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
