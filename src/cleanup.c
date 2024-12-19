/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:18:32 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/19 17:17:07 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cleanup(t_data *data)
{
	if (data->img)
	{
		mlx_destroy_image(data->mlx, data->img); //releases the buffer created by mlx_new_image
		data->img = NULL;
	}
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win); //automatically takes care of freeing the resources associated with window
		data->win = NULL;
	}
	if (data->mlx)
	{
		free(data->mlx); //frees the instance of the mlx to avoid the dangling poitner
		data->mlx = NULL;
	}
	free(data); //free the entire structure at the end so you clean up properlz 
	exit(EXIT_SUCCESS);
}
