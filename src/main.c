/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:35:33 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/28 20:16:53 by jrandet          ###   ########.fr       */
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
		ft_printf("Error: %s!", error);
		exit(EXIT_SUCCESS); //signifies the program exited because of an error 
	}
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		color;
	
	(void)argc;
	(void)argv;

	init_data(&data);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		ft_exit_fractol(&data, "Error: Mlx unitialized, SGV!");
	ft_printf("Win width: %d, win height: %d", WIN_WIDTH, WIN_HEIGHT);
	data.win = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "test square");
	if(!data.win)
		ft_exit_fractol(&data, "Error: Win not initialized, SGV!");
	ft_printf("window created successfully!");
	init_img(&data);
	color = 0xff0000;
	test_draw_square(&data, 100, 100, color);
	/*mouse_events(&data);
	keys_events(&data);
	colours(&data);
	view_init(&data);*/
	mlx_put_image_to_window(data.mlx_ptr, data.win, data.image.img, 0, 0);
	mlx_loop(&data.mlx_ptr);
	return (0);
}

//no need to pass the address of the pointer as the mlx is already a pointer which contains
//the address rendered mlx_init()

//win is a pointer which contains the address of the window created by mlx_new_window
//mlx window returns a void * pointer which is a pointer to the insides of the window that we do not need to see
//mlx returns a void pointer, and it can directly be assigned to the void *win pointer

//for edxample, malloc returns a void pointer because it does not know what it will be allocazed 


// to dereference a void pointer, you need to cast it a type. else it will not work. 
// for example void *ptr = &x, printf("%d", *(int *)ptr)