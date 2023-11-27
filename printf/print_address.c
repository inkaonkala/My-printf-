/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:12:36 by iniska            #+#    #+#             */
/*   Updated: 2023/11/23 12:08:56 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_address(unsigned long n)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 16)
	{
		if (printchar(symbols[n]) < 0)
			return (-1);
		return (1);
	}
	else
	{
		count = print_address(n / 16);
		return (count + print_address(n % 16));
	}
	return (-1);
}
