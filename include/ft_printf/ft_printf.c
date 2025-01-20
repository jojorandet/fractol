/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:51:15 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/20 14:18:21 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	tests(int *count, const char *s, va_list args)
{	
	if (*s == 'c')
		ft_putchar_printf(va_arg(args, int), count);
	else if (*s == 's')
		ft_putstr_printf(va_arg(args, char *), count);
	else if (*s == 'p')
		ft_pointers(va_arg(args, unsigned long), B_HEX_LOWER, 16, count);
	else if (*s == 'd' || *s == 'i')
		ft_putnbr_base(va_arg(args, int), B_DECIMAL, 10, count);
	else if (*s == 'u')
		ft_rputnbr_base(va_arg(args, unsigned int), B_DECIMAL, 10, count);
	else if (*s == 'x')
		ft_rputnbr_base(va_arg(args, unsigned int), B_HEX_LOWER, 16, count);
	else if (*s == 'X')
		ft_rputnbr_base(va_arg(args, unsigned int), B_HEX_UPPER, 16, count);
	else if (*s == '%')
	{
		if (write(1, "%%", 1) == -1)
		{
			*count = -1;
			return ;
		}
		*count += 1;
	}
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			count;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			tests(&count, s, args);
			if (count == -1)
			{
				va_end(args);
				return (-1);
			}
		}
		else if (s)
			count += write(1, s, 1);
		s++;
	}
	va_end(args);
	return (count);
}
