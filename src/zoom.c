/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:33:36 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/15 19:01:32 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_m_struct *data, int x, int y, double zoom)
{
	double	zoom_factor;

	zoom_factor = ((1 / zoom) - 1);
	data->view.scale *= zoom;
	data->view.center_x -= (x - data->view.center_x) * zoom_factor ;
	data->view.center_y -= (y - data->view.center_y) * zoom_factor;
	view_update(data);
}
