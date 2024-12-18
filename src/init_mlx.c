/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:35:48 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/17 20:27:05 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if(!data->mlx)
	{
		printf(ERROR_MLX);
		exit(EXIT_FAILURE);
	}
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Hi");
	if(!data->win)
	{
		printf(ERROR_WIN);
		exit(EXIT_FAILURE);
	}
}

void	init_data(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->view.center_x = (WIN_WIDTH/2);
	data->view.center_y = (WIN_HEIGHT/2);
	data->view.scale = SCALE;
	data->view.pixel_to_view = data->view.scale / WIN_WIDTH;
	data->view.view_to_pixel = WIN_WIDTH / data->view.scale;
	printf("init_data is %d\n", SCALE);
	printf("init_data is %d\n", WIN_WIDTH);
	printf("init_data is %f\n", data->view.pixel_to_view);
}
