/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcrtomb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:04:10 by dbouizem          #+#    #+#             */
/*   Updated: 2025/04/11 02:58:23 by dbouizem         ###   ########.fr       */
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
	if (wc <= ASCII_MAX)
		s[0] = (char)wc;
	else if (wc <= UTF8_2_BYTES_MAX)
	{
		s[0] = UTF8_MASK_2BYTE | (wc >> 6);
		s[1] = UTF8_MASK_CONT | (wc & UTF8_6BITS);
	}
	else if (wc <= UTF8_3_BYTES_MAX)
	{
		s[0] = UTF8_MASK_3BYTE | (wc >> 12);
		s[1] = UTF8_MASK_CONT | ((wc >> 6) & UTF8_6BITS);
		s[2] = UTF8_MASK_CONT | (wc & UTF8_6BITS);
	}
	else if (wc <= UCODE_MAX)
	{
		s[0] = UTF8_MASK_3BYTE | ((wc >> 18) & 0x07);
		s[1] = UTF8_MASK_CONT | ((wc >> 12) & UTF8_6BITS);
		s[2] = UTF8_MASK_CONT | ((wc >> 6) & UTF8_6BITS);
		s[3] = UTF8_MASK_CONT | (wc & UTF8_6BITS);
	}
	return (1 + (wc > 0x7F) + (wc > 0x7FF) + (wc > 0xFFFF));
}
