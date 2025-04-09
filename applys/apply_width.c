/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:09:11 by dbouizem          #+#    #+#             */
/*   Updated: 2025/03/02 09:33:32 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	apply_width(char **str, t_printf *data)
{
	char	*buffer;
	char	pad_char;
	int		len;

	if (!str || !*str || data->width <= ft_strlen(*str))
		return ;
	len = ft_strlen(*str);
	pad_char = ' ';
	if (data->zero && !data->minus)
		pad_char = '0';
	buffer = ft_calloc(data->width + 1, sizeof(char));
	if (!buffer)
		return ;
	if (data->minus)
	{
		ft_memcpy(buffer, *str, len);
		ft_memset((buffer + len), pad_char, (data->width - len));
	}
	else
	{
		ft_memset(buffer, pad_char, data->width - len);
		ft_memcpy(buffer + (data->width - len), *str, len);
	}
	free(*str);
	*str = buffer;
}
