/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:35:33 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/21 19:29:40 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;
	
	(void)argc;
	(void)argv;
	int x;
	int y;

	init_data(&data);
	data.mlx_ptr = mlx_init();
	data.win = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "new_window"); 
	y = WIN_HEIGHT * 0.1;
	while (y < WIN_HEIGHT * 0.9)
	{
		x = WIN_WIDTH * 0.1;
		while (x < WIN_WIDTH * 0.9)
		{
			mlx_pixel_put(data.mlx_ptr, data.win, x, y, 0xff0000);
			x++;
		}
		y++;
	}
	//mlx_pixel_put(data.mlx_ptr, data.win, 400,400, 0xff0000);
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