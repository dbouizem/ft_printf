/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_signed_value_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:59:02 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/13 03:31:44 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BONUS
#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

intmax_t	get_signed_value(t_printf *data)
{
	if (data->length == LENGTH_HH)
		return ((signed char)va_arg(data->args, int));
	else if (data->length == LENGTH_H)
		return ((short)va_arg(data->args, int));
	else if (data->length == LENGTH_L)
		return (va_arg(data->args, long));
	else if (data->length == LENGTH_LL)
		return (va_arg(data->args, long long));
	else if (data->length == LENGTH_J)
		return (va_arg(data->args, intmax_t));
	else if (data->length == LENGTH_Z)
		return ((intmax_t)va_arg(data->args, size_t));
	else if (data->length == LENGTH_T)
		return (va_arg(data->args, ptrdiff_t));
	else
		return (va_arg(data->args, int));
}
