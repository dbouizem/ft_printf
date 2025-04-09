/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcrtomb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:04:10 by dbouizem          #+#    #+#             */
/*   Updated: 2025/04/09 12:22:09 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/* unicode to UTF-8 dans buffer s
-- returrn nombre d'octets ecrit dans s
-- return size_t - 1 si error */

size_t	ft_wcrtomb(char *s, wchar_t wc)
{
	if (wc > UCODE_MAX || (wc >= UCODE_S_MIN && wc <= UCODE_S_MAX))
		return ((size_t) - 1);
	if (wc <= 0x7F)
		s[0] = (char)wc;
	else if (wc <= 0x7FF)
	{
		s[0] = 0xC0 | (wc >> 6);
		s[1] = 0x80 | (wc & 0x3F);
	}
	else if (wc <= 0xFFFF)
	{
		s[0] = 0xE0 | (wc >> 12);
		s[1] = 0x80 | (wc >> 6) & 0x3F;
		s[2] = 0x80 | (wc & 0x3F);
	}
	else if (wc <= 0x10FFFF)
	{
		s[0] = 0xF0 | ((wc >> 18) & 0x07);
		s[1] = 0x80 | ((wc >> 12) & 0x3F);
		s[2] = 0x80 | ((wc >> 6) & 0x3F);
		s[3] = 0x80 | (wc & 0x3F);
	}
	return (1 + (wc > 0x7F) + (wc > 0x7FF) + (wc > 0xFFFF));
}
