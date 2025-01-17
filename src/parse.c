/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:46:58 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/17 16:06:48 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	float	ft_decimal(char *s)
{
	float	after;
	float	decimal;

	after = 0.0;
	decimal = 0.1;
	while ('0' <= *s && *s <= '9')
	{
		after += (*s - 48) * decimal;
		decimal *= 0.1;
		s++;
	}
	return (after);
}

float	ft_atof(char *s)
{
	int		before;
	float	after;
	int		sign;

	before = 0;
	after = 0.0;
	sign = 1;
	while (*s && ((*s >= 9 && *s <= 13) || *s == ' '))
		s++;
	while (('a' <= *s && *s <= 'z') || ('A' <= *s && *s <= 'Z'))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s++ == '-')
			sign *= -1;
	}
	before = ft_atoi(s);
	while ('0' <= *s && *s <= '9' && !(('a' <= *s && *s <= 'z')
			|| ('A' <= *s && *s <= 'Z')))
		s++;
	if (*(s++) == '.')
		after = ft_decimal(s);
	return (sign * (before + after));
}

int	ft_is_int(char *s)
{
	if (!s)
		return (0);
	if (*s == '-')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s) && *s != '.')
			return (0);
		s++;
	}
	return (1);
}
