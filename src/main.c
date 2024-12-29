/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:35:33 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/29 19:17:47 by jrandet          ###   ########.fr       */
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

	printf("Pointer size: %zu bytes\n", sizeof(void *));
	init_data(&data);
	data.mlx_ptr = mlx_init();
	ft_printf("\n\n\n\n%p\n\n", data.mlx_ptr);
	if (!data.mlx_ptr)
		ft_exit_fractol(&data, "Error: Mlx unitialized, SGV!\n");
	ft_printf("Win width: %d\n win height: %d\n", WIN_WIDTH, WIN_HEIGHT);
	data.win = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "test square");
	if(!data.win)
		ft_exit_fractol(&data, "Error: Win not initialized, SGV\n!");
	ft_printf("window created successfully!\n\n");
	init_img(&data);
	draw_grid(&data);
	view_draw(&data, 100, 700);
	//draw_grid(&data);
	/*mouse_events(&data);
	keys_events(&data);
	colours(&data);
	view_init(&data);*/
	mlx_put_image_to_window(data.mlx_ptr, data.win, data.image.img, 0, 0);
	ft_printf("\n\n\n\n%p\n\n", data.mlx_ptr);

	mlx_loop(data.mlx_ptr);
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