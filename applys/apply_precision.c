/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 03:28:44 by dbouizem          #+#    #+#             */
/*   Updated: 2025/03/02 09:24:21 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	apply_precision(char **str, t_printf *data)
{
	char	*new_str;
	size_t	str_len;
	size_t	precision;

	if (!str || !*str || data->precision < 0)
		return ;
	str_len = ft_strlen(*str);
	precision = (size_t)data->precision;
	if (str_len <= precision)
		return ;
	new_str = ft_substr(*str, 0, precision);
	if (!new_str)
	{
		data->error = 1;
		return ;
	}
	free(*str);
	*str = new_str;
}
