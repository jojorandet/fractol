/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:26:09 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/20 14:26:13 by jrandet          ###   ########.fr       */
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
