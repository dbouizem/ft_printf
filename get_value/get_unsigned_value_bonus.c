/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned_value_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:00:13 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/05 10:35:49 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

uintmax_t	get_unsigned_value(t_printf *data)
{
	if (data->length == LENGTH_HH)
		return ((unsigned char)va_arg(data->args, int));
	else if (data->length == LENGTH_H)
		return ((unsigned short)va_arg(data->args, int));
	else if (data->length == LENGTH_L)
		return (va_arg(data->args, unsigned long));
	else if (data->length == LENGTH_LL)
		return (va_arg(data->args, unsigned long long));
	else if (data->length == LENGTH_J)
		return (va_arg(data->args, uintmax_t));
	else if (data->length == LENGTH_Z)
		return (va_arg(data->args, size_t));
	else if (data->length == LENGTH_T)
		return ((uintmax_t)va_arg(data->args, ptrdiff_t));
	else
		return (va_arg(data->args, unsigned int));
}
