/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:55:14 by iniska            #+#    #+#             */
/*   Updated: 2023/11/21 14:12:12 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit(long n, int base, char specifier)
{
	int		count;
	char	*symbols;

	count = 0;
	if (specifier == 'X')
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n < 0)
	{
		write (1, "-", 1);
		return (print_digit(-n, base, specifier) + 1);
	}
	else if (n < base)
		return (printchar((int)symbols[n]));
	else
	{
		count = print_digit(n / base, base, specifier);
		return (count + print_digit(n % base, base, specifier));
	}
}
