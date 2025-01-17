/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:28:20 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/17 10:38:33 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_move(int x, int y, t_m_struct *data)
{
	t_fractal	*f;

	f = &data->f;
	if (data->is_control_pressed)
	{
		f->c_constant.real = ((x - WIN_WIDTH / 2.0) / (WIN_WIDTH / 3.0));
		f->c_constant.im = ((y - WIN_HEIGHT / 2.0) / (WIN_HEIGHT / 3.0));
		request_render(data);
	}
	return (0);
}

int	mouse_down(int mouse_down, int x, int y, t_m_struct *data)
{
	if (mouse_down == M_SCROLL_FORWARD)
	{
		zoom(data, x, y, 1 + ZOOM);
		return (0);
	}
	else if (mouse_down == M_SCROLL_BACKWARD)
	{
		zoom(data, x, y, 1 - ZOOM);
		return (0);
	}
	return (0);
}

void	event_mouse_init(t_m_struct *data)
{
	mlx_hook(data->win, ON_MOUSEDOWN, ButtonPressMask, mouse_down, data);
	mlx_hook(data->win, ON_MOUSEMOVE, PointerMotionMask, mouse_move, data);
}
