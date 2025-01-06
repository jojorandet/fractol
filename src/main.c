/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:35:33 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/06 18:18:11 by jrandet          ###   ########.fr       */
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

void	output_help()
{

}

int	parse_arguments(t_m_struct *data, int argc, char **argv)
{
	t_fractal	*f; //1 julia and all the rest is mandelbrot 

	f = &data->f;
	if (argc < 2 || argc > 4)
		return (1);
	f->fractal_type = ft_atoi(argv[1]);
	if (f->fractal_type < 1 || f->fractal_type > 3) // 1 2 3 
		return (1);
	if (f->fractal_type != 1 && argc > 2) // if this is not julia and I have more than 2 arguments
		return (1);
	if (f->fractal_type == 1 && argc != 4)
		return (1);
	if (f->fractal_type == 1 && argc == 4)
	{
		f->c_julia.real = ft_atof(argv[2]);
		f->c_julia.im = ft_atof(argv[3]);
	}
	set_fractal(data); 
}

int	main(int argc, char **argv)
{
	t_m_struct	data;

	if (argc < 2)
		ft_exit_fractol(NULL, "Please enter a valid number of arguments!");
	if (parse_arguments(&data, argc, argv)) //this wll execute if non zero value 
		return(output_help());
	init_fractol(&data);
	event_mouse_init(&data);
	events_keys_init(&data);
	view_init(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
