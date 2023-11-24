/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:12:28 by iniska            #+#    #+#             */
/*   Updated: 2023/11/21 14:49:58 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_form(char specifier, va_list ap)
{
	void	*ptr;

	if (specifier == 'c')
		return (printchar(va_arg(ap, int)));
	else if (specifier == 's')
		return (printstr(va_arg(ap, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (print_digit((long)(va_arg(ap, int)), 10, specifier));
	else if (specifier == 'u')
		return (print_digit((long)(va_arg(ap, unsigned int)), 10, 'u'));
	else if (specifier == 'x' || specifier == 'X')
		return (print_digit((long)(va_arg(ap, unsigned int)), 16, specifier));
	else if (specifier == 'p')
	{
		ptr = va_arg(ap, void *);
		if (ap != NULL)
		{
			write (1, "0x", 2);
			return (2 + (print_address((unsigned long)ptr)));
		}
		else
			return (printstr("(nil)"));
	}
	else
		return (-1);
}
