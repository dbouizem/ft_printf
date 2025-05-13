/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:14:41 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/13 03:34:39 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_numlen(uintmax_t un, int base)
{
	int	len;

	len = 0;
	if (un == 0)
		return (1);
	while (un > 0)
	{
		un /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_print(uintmax_t un)
{
	int		len;
	char	*str;

	len = ft_numlen(un, 10);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (un == 0)
		str[0] = '0';
	while (un > 0)
	{
		str[--len] = (un % 10) + '0';
		un /= 10;
	}
	return (str);
}
