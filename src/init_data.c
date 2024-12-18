/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:30:39 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/18 11:30:47 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_data(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->view.center_x = (WIN_WIDTH/2);
	data->view.center_y = (WIN_HEIGHT/2);
	data->view.scale = SCALE;
	data->view.pixel_to_view = data->view.scale / WIN_WIDTH;
	data->view.view_to_pixel = WIN_WIDTH / data->view.scale;
	printf("init_data is %d\n", SCALE);
	printf("init_data is %d\n", WIN_WIDTH);
	printf("init_data is %f\n", data->view.pixel_to_view);
}