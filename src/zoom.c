/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:33:36 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/05 13:38:34 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_m_struct *data, int x, int y, int zoom) // refactored the zooming in
{
	(void)x;
	(void)y;

	if (zoom == 1)
	{
		data->view.scale *= 1.01;
		view_update(data);
	}
	if (zoom == -1)
	{
		data->view.scale *= 0.95;
		view_update(data);
	}
}