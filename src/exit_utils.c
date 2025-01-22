/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:48:47 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/22 13:36:28 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit_fractol(t_m_struct *data, char *error)
{
	if (data)
	{
		if (data->image.data)
		{
			mlx_destroy_image(data->mlx_ptr, data->image.data);
			data->image.data = NULL;
		}
		if (data->win)
		{
			mlx_destroy_window(data->mlx_ptr, data->win);
			data->win = NULL;
		}
		#ifdef __linux__
		if (data->mlx_ptr)
		{
			mlx_destroy_display(data->mlx_ptr);
			free(data->mlx_ptr);
		}
		#elif __APPLE__
		if (data->mlx_ptr)
		{
			free(data->mlx_ptr);
		}
		#endif
	}
	if (error)
	{
		ft_printf("%s\n", error);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

int	handle_destroy(t_m_struct *data)
{
	ft_exit_fractol(data, NULL);
	return (0);
}
