/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:35:33 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/10 19:18:58 by jrandet          ###   ########.fr       */
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


int output_help()
{
	printf("-----------------------------------------------------------------------------------------------\n");
	printf("Input synthax:  ./fractol  [FRACTAL_TYPE]  [OPTIONAL_PARAMETERS]\n\n");
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
	if (argc < 2 || argc > 4)
		return (1);
	data->f.fractal_type = ft_atoi(argv[1]);
	if (data->f.fractal_type < 1 || data->f.fractal_type > 3)
		return (1);
	fractal_set(data);
	if (data->f.fractal_type == 1 && argc == 4)
	{
		data->f.c_constant.real = ft_atof(argv[2]);
		data->f.c_constant.im = ft_atof(argv[3]);
	}
	//printf("the values of c_constant.real is %f and im %f\n", data->f.c_constant.real, data->f.c_constant.im);
	return (0);
}

void	init_fractol(t_m_struct *data)
{
	init_data(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_exit_fractol(data, "Error: Mlx unitialized, SGV!\n");
	data->win = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "test");
	if (!data->win)
		ft_exit_fractol(data, "Error: Win not initialized, SGV\n!");
	init_colour(data);
	init_img(data);
}

int	main(int argc, char **argv)
{
	t_m_struct	data;

	init_fractol(&data);
	if (parse_arguments(&data, argc, argv)) //this wll execute if non zero value 
		return (output_help());
	view_init(&data);
	event_mouse_init(&data);
	events_keys_init(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
