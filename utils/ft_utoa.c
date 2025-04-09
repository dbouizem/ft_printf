/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:06:43 by dbouizem          #+#    #+#             */
/*   Updated: 2025/03/01 10:35:46 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	ft_utoa(unsigned int n)
{
	char	buffer[12];
	int		i;
	char	*base;

	base = DIGITS;
	i = sizeof(buffer) - 1;
	buffer[i] = '\0';
	if (n == 0)
		buffer[--i] = '0';
	else
	{
		while (n > 0)
		{
			buffer[--i] = base[n % 10];
			n /= 10;
		}
	}
	return (ft_strdup(buffer + i));
}
