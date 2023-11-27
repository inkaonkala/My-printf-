/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:50:03 by iniska            #+#    #+#             */
/*   Updated: 2023/11/21 12:52:01 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (*s != '\0')
		{
			if (printchar((int)*s) < 0)
				return (-1);
			i++;
			s++;
		}
	}
	else
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		i = 6;
	}
	return (i);
}
