/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 03:28:44 by dbouizem          #+#    #+#             */
/*   Updated: 2025/04/13 03:33:37 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	apply_precision(char **str, t_printf *data)
{
	char	*new_str;
	size_t	precision;
	size_t	str_len;

	if (!str || data->precision < 0)
		return ;
	precision = (size_t)data->precision;
	if (!*str)
	{
		new_str = ft_strdup("");
		free(*str);
		*str = new_str;
		return ;
	}
	str_len = ft_strlen(*str);
	if (str_len > precision)
	{
		new_str = ft_substr(*str, 0, precision);
		free(*str);
		*str = new_str;
	}
}
