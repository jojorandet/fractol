/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:08:05 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/19 18:39:47 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	ft_exit_fractol(t_data *data)
{
	cleanup(data);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_keyboard(int key, t_data *data)
{
	
}

void	ft_mouse()
{

}


void	setup_hooks(t_data *data)
{
	mlx_hook(data->win, WINDOW_CLOSED, 0, ft_exit_fractol, data); //ml;x hook willl receivesthe pointer to the window that detects the event 
	mlx_key_hook(data->win, ft_keyboard, data);
	mlx_mouse_hook(data->win, ft_mouse, data);
	/*mlx_hook(data->win, 2, 1L << 0, ft_keyboard, data);
	mlx_loop_hook(data->mlx, ft_redraw_frame, data);*/
}