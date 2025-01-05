/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:18:38 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/04 17:35:41 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key_down(int key_code, t_main *data)
{
	printf("the key pressed is: %d", key_code);
	if (key_code == 13)
		data->view.scale *= 0.99;
	if (key_code == 1)
		data->view.scale *= 1.01;
	else if (key_code == 123)
		data->view.center_x -= 10;
	else if (key_code == 124)
		data->view.center_x += 10;
	else if (key_code == 125)
		data->view.center_y -= 10;
	else if (key_code == 126)
		data->view.center_y += 10;
	view_update(data);
	return (0);
}

void	events_keys_init(t_main *data)
{
	mlx_hook(data->win, ON_KEYDOWN, 0, handle_key_down, data);
}
