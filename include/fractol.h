/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:31:28 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/21 19:32:38 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include <mlx.h>
#include <stdio.h>
#include <math.h>

# define WIN_WIDTH 200
# define WIN_HEIGHT 50

typedef struct s_data
{
	void	*mlx_ptr; //a void pointer that contains the address returned by mlx_init() 
	void	*win;
	void	*img;
}	t_data;

void	init_data(t_data *data);

#endif