/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:28:20 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/05 14:59:35 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse_down(int mouse_down, int x, int y, t_m_struct *data)
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
	mlx_hook(data->win, ON_MOUSEDOWN, ButtonPressMask, handle_mouse_down, data);
}
