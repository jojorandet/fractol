/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:46:58 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/05 18:14:31 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	ft_atof(char *s)
{
	int		before;
	int		after;
	int		sign;
	int		count_decimal;
	
	before = 0;
	sign = 1;
	while (*s && ((9 <= *s && *s <= 13) || *s == ' '))
		s++;
	while (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	before = ft_atoi(s);
	after = 0;
	if (*s == '.')
		s++;
	count_decimal = ft_strlen(s);
	after = ft_atoi(s);
	return (sign * (before + ((float)after * pow(10, -count_decimal))));
}
