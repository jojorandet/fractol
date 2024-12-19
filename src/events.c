/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:08:05 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/19 14:38:40 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setup_hooks(t_data *data)
{
	mlx_hook(data->win, 17, 0, ft_exit_fractol, data);
	/*mlx_hook(data->win, 2, 1L << 0, ft_keyboard, data);
	mlx_mouse_hook(data->win, ft_mouse, data);
	mlx_loop_hook(data->mlx, ft_redraw_frame, data);*/
}
int	ft_exit_fractol(t_data *data)
{
	cleanup(data);
	exit(EXIT_SUCCESS);
	return (0);
}

/*void	ft_keyboard(int key, t_data *data)
{
	
}*/

