/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:35:33 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/07 14:48:03 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit_fractol(t_m_struct *data, char *error)
{
	if (data)
	{
		if (data->image.data)
			mlx_destroy_image(data->mlx_ptr, data->image.data);
		if (data->win)
			mlx_destroy_window(data->mlx_ptr, data->win);
	}
	if (error)
	{
		printf("Error: %s!", error);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_SUCCESS);
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
	init_img(data);
}

int	output_help()
{
	printf("wrong value!");
	return (0);
}

int	parse_arguments(t_m_struct *data, int argc, char **argv)
{
	//t_fractal	*f;

	//f = &data->f;
	if (argc < 2 || argc > 4)
		return (1);
	data->f.fractal_type = ft_atoi(argv[1]); // i get the number of the fractal
	if (data->f.fractal_type < 1 || data->f.fractal_type > 3)
		return (1);
	fractal_set(data); // I set the fractal, amd if they do not give e arguments I do it anyways 
	if (data->f.fractal_type == 1 && argc == 4) // I come back here and if I do have values in arg3 and 4 then i update them 
	{
		printf("the value of the string argv2 is %s\n", argv[2]);
		data->f.c_julia.real = ft_atof(argv[2]);
		data->f.c_julia.im = ft_atof(argv[3]);
	}
	printf("the value of the c_julia.real is %.2f and c_imag is %.2f\n", data->f.c_julia.real, data->f.c_julia.im);
	return (0);
}

int	main(int argc, char **argv)
{
	t_m_struct	data;

	if (argc < 2)
		ft_exit_fractol(NULL, "Please enter a valid number of arguments!");
	init_fractol(&data);
	if (parse_arguments(&data, argc, argv)) //this wll execute if non zero value 
		return (output_help());
	event_mouse_init(&data);
	events_keys_init(&data);
	view_init(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
