/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:14:41 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/05 14:20:40 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
/*
static int	ft_numlen(intmax_t n, int base)
{
	int			len;
	uintmax_t	un;

	len = 0;
	if (n < 0)
	{
		len = 1;
		un = (uintmax_t)(-n);
	}
	else if (n == 0)
	{
		len = 1;
		un = 0;
	}
	else
		un = (uintmax_t)n;
	while (un > 0)
	{
		un /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_print(intmax_t nb)
{
	int			len;
	char		*str;
	uintmax_t	un;

	len = ft_numlen(nb, 10);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	un = (uintmax_t)nb;
	if (nb < 0)
	{
		un = (uintmax_t)(-nb);
		str[0] = '-';
	}
	else if (nb == 0)
		un = 0;
	if (un == 0)
		str[0] = '0';
	while (un > 0)
	{
		str[--len] = (un % 10) + '0';
		un /= 10;
	}
	return (str);
}*/

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
