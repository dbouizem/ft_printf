/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 06:24:09 by dbouizem          #+#    #+#             */
/*   Updated: 2025/04/13 23:37:03 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*get_unsignedint_str(t_printf *data)
{
	uintmax_t		num;
	char			*str;

	num = get_unsigned_value(data);
	if (num == 0 && data->precision == 0)
		str = ft_strdup("");
	else
		str = ft_ulltoa_base(num, DIGITS);
	if (!str)
		data->error = 1;
	return (str);
}

void	handle_uint(t_printf *data)
{
	char	*str;

	str = get_unsignedint_str(data);
	if (data->error)
		return (free(str));
	apply_precision_int(&str, data);
	if (data->error)
		return (free(str));
	apply_width(&str, data, ft_strlen(str));
	if (data->error)
		return (free(str));
	ft_print_str(str, data);
	free(str);
}
