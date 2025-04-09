/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 06:24:09 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/16 04:23:11 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*get_unsignedint_str(t_printf *data)
{
	char			*str;
	unsigned long	num;

	num = (unsigned long)va_arg(data->args, unsigned int);
	if (num == 0 && data->precision == 0)
		str = ft_strdup("");
	else
		str = ft_utoa(num);
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
	apply_precision(&str, data);
	if (data->error)
		return (free(str));
	apply_width(&str, data);
	if (data->error)
		return (free(str));
	ft_print_str(str, data);
	free(str);
}
