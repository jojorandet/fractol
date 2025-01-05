/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:56:26 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/04 17:36:55 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_main *data)
{
	view_draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win, data->image.data, 0, 0);
}
