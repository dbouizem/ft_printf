/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:09:11 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/13 03:31:31 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

static void	extract_sign(char **str, char **sign, int *padding, t_printf *data)
{
	*sign = "";
	if (data->zero && !data->minus && data->precision == -1)
	{
		if (**str == '-' || **str == '+' || **str == ' ')
		{
			*sign = ft_substr(*str, 0, 1);
			*str += 1;
			*padding = data->width - (int)ft_strlen(*str) - 1;
		}
	}
}

void	apply_width(char **str, t_printf *data, int content_len)
{
	char	pad_char;
	char	*buffer;
	char	*sign;
	int		padding;

	if (!str || !*str || data->width <= content_len)
		return ;
	pad_char = ' ';
	if (data->zero && !data->minus && data->precision == -1)
		pad_char = '0';
	padding = data->width - content_len;
	sign = "";
	extract_sign(str, &sign, &padding, data);
	buffer = ft_calloc(data->width + 1, sizeof(char));
	if (!buffer)
		return ;
	if (data->minus)
		ft_memcpy(buffer, *str, ft_strlen(*str));
	else
		ft_memset(buffer, pad_char, padding);
	if (data->minus)
		ft_memset(buffer + ft_strlen(*str), ' ', padding);
	else
		ft_memcpy((buffer + padding), *str, ft_strlen(*str));
	*str = ft_strjoin(sign, buffer);
}
