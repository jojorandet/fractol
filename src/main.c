/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:35:33 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/05 19:17:35 by jrandet          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_m_struct	data;
	(void)argc;
	(void)argv;

	//if (argc < 2)
		//ft_exit_fractol(NULL, "Please enter a valid number of arguments!");
	init_fractol(&data);
	event_mouse_init(&data);
	events_keys_init(&data);
	view_init(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
