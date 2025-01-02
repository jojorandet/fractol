/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:28:20 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/02 19:09:41 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse_down(int mouse_down, int x, int y, t_data *data)
{
	if (mouse_down == SCROLL_FORWARD)
	{
		data->view.scale *= 0.95;
		view_update(data);
	}
	else if (mouse_down == SCROLL_BACKWARD)
	{
		data->view.scale *= 1.01;
		view_update(data);
	}
	return (0);
}

int	handle_key_down(int key_code, t_data *data)
{
	//if (key_code == 13)
		//data->view.scale *= 0.99;
	if (key_code == 1)
		data->view.scale *= 1.01;
	else if (key_code == 123)
		data->view.center_x -= 10;
	else if (key_code == 124)
		data->view.center_x += 10;
	else if (key_code == 125)
		data->view.center_y -= 10;
	else if (key_code == 126)
		data->view.center_y  += 10;
	view_update(data);
	return (0);
}

void	event_init(t_data *data)
{
	mlx_hook(data->win, ON_KEYDOWN, 0, handle_key_down, data);
	mlx_hook(data->win, ON_MOUSEDOWN, 0, handle_mouse_down, data);
}



