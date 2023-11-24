/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:05:59 by iniska            #+#    #+#             */
/*   Updated: 2023/11/23 12:08:33 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	printchar(char c);
int	printstr(char *s);
int	print_digit(long n, int base, char specifier);
int	print_digit(long n, int base, char specifier);
int	ft_form(char specifier, va_list ap);
int	print_address(unsigned long n);

#endif
