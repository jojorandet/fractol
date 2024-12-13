/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:35:48 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/11 21:01:29 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_memset(void	*b, int c, size_t len)
{
	unsigned char	*testpointer;

	testpointer = (unsigned char *)b;
	while (len--)
		*testpointer++ = (unsigned char)c;
	return (b);
}

void	init_data(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->img = NULL;
	data->bpp = 0;
	data->size_line = 0;
	data->endian = 0;
}

void	initialisation_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if(!data->mlx)
	{
		printf(ERROR_MLX);
		exit(EXIT_FAILURE);
	}
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Hi");
	if(!data->win)
	{
		printf(ERROR_WIN);
		exit(EXIT_FAILURE);
	}
}

