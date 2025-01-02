/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:35:33 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/02 17:38:59 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit_fractol(t_data *data, char *error)
{
	if (data)
	{
		if (data->image.img)
			mlx_destroy_image(data->mlx_ptr, data->image.img);
		if (data->win)
			mlx_destroy_window(data->mlx_ptr, data->win);
	}
	if (error)
	{
		printf("Error: %s!", error);
		exit(EXIT_SUCCESS); //signifies the program exited because of an error 
	}
	exit(EXIT_SUCCESS);
}

/*void	prepare_fractol(t_data *data, int argc, char **argv)
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		data->fractal.name = "mandelbrot";
		data->fractal.max_iteration = 100;
		data->fractal.scale = SCALE;
	}
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		data->fractal.name = "julia"; //allows my fractal to render on its own 
		data->fractal.max_iteration = 150;
		data->fractal.zoom = 1.5;
	}
	else
	{
		ft_exit_fractol(data, "Invalid fractal type, please type julia or mandelbrot");
	}
	//max iteration will be changed as we go
	data->fractal.max_iterations = data->fractal.base_iteration;	
}*/

void	init_fractol(t_data *data)
{
	init_data(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_exit_fractol(data, "Error: Mlx unitialized, SGV!\n");
	data->win = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "test square");
	if(!data->win)
		ft_exit_fractol(data, "Error: Win not initialized, SGV\n!");
	init_img(data);
}
int	main(int argc, char **argv)
{
	t_data	data;
	int		color;
	int 	x;
	int 	y;
	//if (argc < 2)
		//ft_exit_fractol(NULL, "Please enter a valid number of arguments");
	init_fractol(&data);
	event_init(&data);
	view_init(&data);
	mlx_loop(data.mlx_ptr);

	return (0);
}
