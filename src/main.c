/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:35:33 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/17 15:37:00 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	output_help(void)
{
	ft_putstr("\n\n====== HELP FOR EXECUTING THE FRACTOL PROGRAM: =======\n\n");
	ft_putstr("Please enter the following in the terminal:\n\n");
	ft_putstr("./fractol [type]                 (for Mandelbrot)\n");
	ft_putstr("./fractol [type] [c.real] [c.im] (for Julia)\n\n");
	ft_putstr("================= AVAILABLE FRACTALS: ================\n\n");
	ft_putstr("[1] Julia Set\n");
	ft_putstr("    - Requires complex constant (c) values of type float\n");
	ft_putstr("    - Creates different patterns based on c values entered\n\n");
	ft_putstr("[2] Mandelbrot Set\n");
	ft_putstr("    - No additional (c) values needed\n");
	ft_putstr("    - Classical fractal, no interaction\n\n");
	ft_putstr("====================== EXAMPLES: =====================\n\n");
	ft_putstr("./fractol 2              (Mandelbrot)\n");
	ft_putstr("./fractol 1 -0.4 0.6     (Julia)\n");
	ft_putstr("Julia: c values should be between -2 and 2\n\n");
	ft_putstr("====================== CONTROLS: =====================\n\n");
	ft_putstr("Mouse wheel:             Zoom in and zoom out\n");
	ft_putstr("Arrow keys:              Move up, down, right, left\n");
	ft_putstr("Key C:                   Change the colour of the fractal\n");
	ft_putstr("CTRL + Mouse movement:   Change Julia pattern.\n");
	ft_putstr("Key ESC:                 Exit Program\n\n");
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
	if ((data->f.fractal_type == 2 || data->f.fractal_type == 3) && argc > 2)
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
