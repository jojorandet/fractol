/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:33:36 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/05 18:04:34 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_m_struct *data, int x, int y, double zoom)
{
	data->view.scale *= zoom;
	data->view.center_x -= (x - data->view.center_x) * ((1 / zoom) - 1);
	data->view.center_y -= (y - data->view.center_y) * ((1 / zoom) - 1);
	view_update(data);
}