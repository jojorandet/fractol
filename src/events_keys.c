/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:18:38 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/14 12:06:20 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key_down(int key_code, t_m_struct *data)
{
	/*if (key_code == K_W)
		zoom(data, 1 + ZOOM);
	if (key_code == K_S)
		data->view.scale *= 1.01;*/
	if (key_code == K_RIGHT)
		data->view.center_x -= WIN_WIDTH / 8;
	else if (key_code == K_LEFT)
		data->view.center_x += WIN_WIDTH / 8;
	else if (key_code == K_UP)
		data->view.center_y += WIN_HEIGHT / 8;
	else if (key_code == K_DOWN)
		data->view.center_y -= WIN_HEIGHT / 8;
	else if (key_code == K_C)
		select_palette(data);
	if (key_code == K_ESCP)
		ft_exit_fractol(data, "NO ERROR, window closed and freed");
	view_update(data);
	return (0);
}

void	events_keys_init(t_m_struct *data)
{
	mlx_hook(data->win, ON_KEYDOWN, KeyPressMask, handle_key_down, data);
}
