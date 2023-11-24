/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:04:09 by iniska            #+#    #+#             */
/*   Updated: 2023/11/20 12:41:19 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		totals;
	va_list	ap;

	totals = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*(++format) == '%')
				totals += printchar('%');
			else
				totals += ft_form(*(format), ap);
		}
		else
		{
			write(1, format, 1);
			totals ++;
		}
		format++;
	}
	va_end(ap);
	return (totals);
}
