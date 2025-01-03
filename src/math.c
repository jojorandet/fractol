/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:59:52 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/28 20:25:15 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_limit_upper(int value, int limit_upper)
{
	if (value > limit_upper)
		return (limit_upper); //this is to put in back "in bound"
	return (value); //here it returns the value if it is smaller, then it works
}

int check_limit_lower(int value, int limit_lower)
{
	if (value < limit_lower)
		return (limit_lower);
	return (value);
}
