/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:57:03 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/07 16:56:25 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h" // I need to initialise my structure before doing this 

void	init_data(t_m_struct *data)
{
	if (!data)
		return ;
	ft_bzero(data, sizeof(t_m_struct));
}
//(*data).
//data->
//sizet is the result of the sizeof operator 
//check if the data pointer is not NULL. else segmentation fault.
//there is no need to explicitely call everything individually 