/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:04:19 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/14 17:18:37 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mouse(int mouse, int x, int y, t_data *data)
{
	(void)data;
	ft_printf("button: %d  x: %d and y : %d\n", mouse, x, y);
	

	return (0);
}