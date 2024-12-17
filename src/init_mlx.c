/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:35:48 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/17 19:15:27 by jrandet          ###   ########.fr       */
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
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->bytes_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->view.center_x = (WIN_WIDTH/2);
	data->view.center_y = (WIN_HEIGHT/2);
	data->view.scale = SCALE;
	data->view.pixel_to_view = SCALE / WIN_WIDTH;
	data->view.view_to_pixel = WIN_WIDTH / SCALE;
}
