/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:33:36 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/05 14:58:30 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_m_struct *data, int x, int y, double zoom) // refactored the zooming in
{
	data->view.scale *= zoom;
	data->view.center_x -= (x - data->view.center_x) * ((1 / zoom) - 1);
	data->view.center_y -= (y - data->view.center_y) * ((1 / zoom) - 1);
	view_update(data);
}
