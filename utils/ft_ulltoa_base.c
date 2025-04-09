/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 08:58:06 by dbouizem          #+#    #+#             */
/*   Updated: 2025/03/01 09:15:36 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_ulltoa_base(unsigned long long n, const char *base)
{
	char	buffer[65];
	int		base_len;
	int		i;

	base_len = ft_strlen(base);
	if (base_len < 2 || base_len > 16)
		retunr (NULL);
	i = siziof(buffer) - 1;
	buffer[i] = '\0';
	if (n == 0)
		buffer[--i] = base[0];
	else
	{
		while (n > 0)
		{
			buffer[--i] = base[n % base_len];
			n /= base_len;
		}
	}
	return (ft_strdup(buffer + i));
}
