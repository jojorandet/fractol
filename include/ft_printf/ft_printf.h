/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:51:13 by jrandet           #+#    #+#             */
/*   Updated: 2024/10/23 15:58:26 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h> //for write
# include <stdlib.h> //for malloc, calloc etc.
# include <stdarg.h> //for va_start, etc.

# define B_DECIMAL "0123456789"
# define B_HEX_LOWER "0123456789abcdef"
# define B_HEX_UPPER "0123456789ABCDEF"

int		ft_printf(const char *s, ...);
void	tests(int *count, const char *c, va_list args);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_pointers(unsigned long ptr, char *base, \
		unsigned int base_len, int *count);
void	ft_rputnbr_base(unsigned long n, char *base, \
		unsigned int base_len, int *count);
void	ft_putnbr_base(long n, char *base, unsigned int base_len, int *count);
size_t	ft_strlen(const char *str);

#endif
