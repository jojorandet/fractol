/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:35:33 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/14 18:30:53 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit_fractol(t_m_struct *data, char *error)
{
	if (data)
	{
		if (data->image.data)
		{
			mlx_destroy_image(data->mlx_ptr, data->image.data);
			data->image.data = NULL; // prevents double freeing 
		}
		if (data->win)
		{
			mlx_destroy_window(data->mlx_ptr, data->win);
			data->win = NULL; //prevents double freeing :-)
		}
		if (data->mlx_ptr)
		{
			mlx_destroy_display(data->mlx_ptr);
			free(data->mlx_ptr);
		}
	}
	if (error)
	{
		printf("Error: %s!", error);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

static int	handle_destroy(t_m_struct *data)
{
	ft_exit_fractol(data, NULL);
	return (0);
}

int output_help()
{
	printf("-----------------------------------------------------------------------------------------------\n");
	printf("!ERROR IN INPUT!\n\n");
	printf("Input synthax:  ./fractol  [fractal_number] [float c.real value] [float c.im value]\n\n");
	printf("All arguments must be numbers. If there is a letter, failure.\n");
	printf("Available fractal types:\n");
	printf("-----------------------------------------------------------------------------------------------\n");
	printf("  [1] - Julia Set\n");
	printf("  [2] - Mandelbrot Set\n\n");
	printf("(No need for square brakets)\n");
	sleep(1);
	printf("-----------------------------------------------------------------------------------------------\n");
	printf("For Julia Set:\n");
	printf("  ./fractol 1 [REAL] [IMAGINARY]\n");
	printf("  REAL and IMAGINARY are optional float values for the c constant.\n");
	printf("  If not provided, default values will be used.\n\n");
	sleep(1);
	printf("-----------------------------------------------------------------------------------------------\n");
	printf("Examples of input:\n");
	printf("  ./fractol 2					(Mandelbrot Set)\n");
	printf("  ./fractol 1					(Julia Set with default c)\n");
	printf("  ./fractol 1 -0.4 0.6			(Julia Set with c = -0.4 + 0.6i)\n\n");
	printf("-----------------------------------------------------------------------------------------------\n");
	printf("Tip: the Julia sets are most beautiful when the c.real and c.imag are between -2 and 2.\n");
	printf("Note: Ensure all arguments are correctly formatted to avoid errors.\n");
	printf("-----------------------------------------------------------------------------------------------\n");
	return 0;
}

int	parse_arguments(t_m_struct *data, int argc, char **argv)
{
	int i;
	int j;

	j = 0;
	if (argc < 2 || argc > 4)
		return (0);
	i = 1;
	while(argv[i] && i <= argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (i == 1)
			{
				if (!ft_isdigit(argv[i][j]))
					return (0);
			}
			else if (!ft_isdigit(argv[i][j]) && argv[i][j] != '.')
				return (0); //different check if if it not just 1 
			j++;
		}
		i++;
	}
	data->f.fractal_type = ft_atoi(argv[1]);
	if (data->f.fractal_type < 1 || data->f.fractal_type > 3)
		return (0);
	if (data->f.fractal_type == 2 && argc > 2)
		return (0);
	fractal_set(data);
	if (data->f.fractal_type == 1 && argc == 4)
	{
		data->f.c_constant.real = ft_atof(argv[2]);
		data->f.c_constant.im = ft_atof(argv[3]);
	}
	return (1);
}

int	init_fractol(t_m_struct *data) // crucial function, it lays out the work for all the rest of the program 
{
	init_data(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_exit_fractol(data, "Error: Mlx unitialized, SGV!\n");
	data->win = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "test");
	if (!data->win)
		ft_exit_fractol(data, "Error: Win not initialized, SGV\n!");
	select_palette(data);
	init_img(data);
	return (1); // means there is no error so far 
	//with the return 1 i do not need to make other checks after 
}

int	main(int argc, char **argv)
{
	t_m_struct	data;

	if (!init_fractol(&data))
		ft_exit_fractol(&data, "Failed to initialise fractol.");
	if (!parse_arguments(&data, argc, argv)) //this wll execute if non zero value 
		return (output_help());
	view_init(&data);
	event_mouse_init(&data);
	events_keys_init(&data);
	mlx_hook(data.win, DestroyNotify, 0, handle_destroy, &data);
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
