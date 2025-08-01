/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wstr_utf8_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:57:12 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/13 03:32:18 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

char	*get_wstr_utf8_str(wchar_t *wstr, t_printf *data)
{
	char	*str;
	char	*tmp;
	char	*part;

	if (!wstr)
		return (ft_strdup("(null)"));
	str = ft_strdup("");
	if (!str)
		return (NULL);
	while (*wstr && !data->error)
	{
		part = get_wchar_utf8_str(*wstr++, data);
		if (!part)
		{
			free(str);
			return (NULL);
		}
		tmp = ft_strjoin(str, part);
		free(str);
		free(part);
		str = tmp;
		if (!str)
			data->error = 1;
	}
	return (str);
}
