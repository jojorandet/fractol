/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:18:32 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/17 19:24:57 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cleanup(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win); //automatically takes care of freeing the resources associated with window
		data->win = NULL;
	}
	/*if (data->mlx)
	{
		mlx_destroy_display(data->mlx); //destroys the connectin to the server
		data->mlx = NULL;
	}*/
	exit(EXIT_SUCCESS);
}
