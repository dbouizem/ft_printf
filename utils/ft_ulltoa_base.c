/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:50:22 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/02 02:53:13 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

static int	ft_unumlen(uintmax_t n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_ulltoa_base(uintmax_t n, const char *base)
{
	char	*str;
	int		base_len;
	int		len;
	int		i;

	base_len = ft_strlen(base);
	len = ft_unumlen(n, base_len);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = base[0];
	i = len;
	while (n > 0)
	{
		str[--i] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}
