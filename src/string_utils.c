/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:11:34 by jrandet           #+#    #+#             */
/*   Updated: 2024/12/25 16:20:06 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_fractol_strncmp(char *s1, char *s2, int n)
{
	if (n == 0)
		return (0);
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (n > 0 && (*s1 == *s2) && *s1 && *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*s1 - *s2);
}