/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:11:27 by jrandet           #+#    #+#             */
/*   Updated: 2024/10/23 17:17:11 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rputnbr_base(unsigned long n, char *base,
		unsigned int base_len, int *count)
{
	if (*count == -1)
		return ;
	if (n >= base_len)
		ft_rputnbr_base(n / base_len, base, base_len, count);
	if (write(1, &base[n % base_len], 1) == -1)
	{
		*count = -1;
		return ;
	}
	(*count)++;
}

void	ft_putnbr_base(long n, char *base, unsigned int base_len, int *count)
{
	if (*count == -1)
		return ;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
		{
			*count = -1;
			return ;
		}
		(*count)++;
		ft_rputnbr_base(-(unsigned long)n, base, base_len, count);
	}
	else
		ft_rputnbr_base((unsigned long)n, base, base_len, count);
}
