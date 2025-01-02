/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:28:20 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/02 18:29:15 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key_down(int key_code, t_data *data)
{
	printf("key pressed: %d\n", key_code);
	if (key_code == 13)
		data->view.scale *= 0.99;
	else if (key_code == 1)
		data->view.scale *= 1.01;
	if (key_code == 123)
		data->view.center_x -= 10;
	if (key_code == 124)
		data->view.center_x += 10;
	if (key_code == 125)
		data->view.center_y -= 10;
	if (key_code == 126)
		data->view.center_y  += 10;
	view_update(data);
	return (0);
}

void	event_init(t_data *data)
{
	mlx_hook(data->win, ON_KEYDOWN, 0, handle_key_down, data);
}



