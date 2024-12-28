/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:57:03 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/28 18:54:06 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_data(t_data *data)
{
	if (!data)
		return ;
	ft_bzero(data, sizeof(t_data));
}

//sizet is the result of the sizeof operator 
//check if the data pointer is not NULL. else segmentation fault.
//there is no need to explicitely call everything individually 