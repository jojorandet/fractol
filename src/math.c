/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:59:52 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/04 17:33:27 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_limit_upper(int value, int limit_upper)
{
	if (value > limit_upper)
		return (limit_upper);
	return (value);
}

int	check_limit_lower(int value, int limit_lower)
{
	if (value < limit_lower)
		return (limit_lower);
	return (value);
}
