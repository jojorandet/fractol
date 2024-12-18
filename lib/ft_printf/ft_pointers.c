/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:18:08 by jrandet           #+#    #+#             */
/*   Updated: 2024/10/23 17:12:35 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointers(unsigned long ptr, char *base,
		unsigned int base_len, int *count)
{
	if (!ptr)
	{
		if (write(1, "0x0", 3) == -1)
		{
			*count = -1;
			return ;
		}
		*count += 3;
	}
	else
	{
		if (write(1, "0x", 2) == -1)
		{
			*count = -1;
			return ;
		}
		*count += 2;
		ft_rputnbr_base(ptr, base, base_len, count);
	}
}
