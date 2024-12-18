/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:35:48 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/18 11:31:07 by jrandet          ###   ########.fr       */
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

