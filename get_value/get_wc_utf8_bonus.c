/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wc_utf8_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:55:38 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/13 03:32:11 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

// max 4 octets UTF-8 + \0
char	*get_wchar_utf8_str(wchar_t wc, t_printf *data)
{
	size_t		len;
	char		*str;
	char		buffer[5];

	len = ft_wcrtomb(buffer, wc);
	if (len == (size_t)-1)
	{
		data->error = 1;
		return (NULL);
	}
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
	{
		data->error = 1;
		return (NULL);
	}
	ft_memcpy(str, buffer, len);
	str[len] = '\0';
	return (str);
}
