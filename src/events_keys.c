/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:18:38 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/05 18:01:07 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key_down(int key_code, t_m_struct *data)
{
	if (key_code == K_W)
		data->view.scale *= 0.99;
	if (key_code == K_S)
		data->view.scale *= 1.01;
	else if (key_code == K_RIGHT)
		data->view.center_x += 10;
	else if (key_code == K_LEFT)
		data->view.center_x -= 10;
	else if (key_code == K_UP)
		data->view.center_y -= 10;
	else if (key_code == K_DOWN)
		data->view.center_y += 10;
	if (key_code == K_ESCP)
		ft_exit_fractol(data, "NO ERROR, window closed and freed");
	view_update(data);
	return (0);
}

void	events_keys_init(t_m_struct *data)
{
	mlx_hook(data->win, ON_KEYDOWN, KeyPressMask, handle_key_down, data);
}
