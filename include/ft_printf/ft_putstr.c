/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 23:11:43 by jrandet           #+#    #+#             */
/*   Updated: 2024/10/23 17:17:38 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_printf(char *s, int *count)
{
	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
		{
			*count = -1;
			return ;
		}
		*count += 6;
		return ;
	}
	while (*s)
	{
		if (write(1, s++, 1) == -1)
		{
			*count = -1;
			return ;
		}
		(*count)++;
	}
}
