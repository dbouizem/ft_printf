/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:29:12 by dbouizem          #+#    #+#             */
/*   Updated: 2025/04/08 16:47:13 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_int_str(t_printf *data)
{
	intmax_t	num;
	char		*num_str;

	num = get_signed_value(data);
	if (num == 0 && data->precision == 0)
		num_str = strdup("");
	else
		num_str = ft_itoa_(num);
	if (!num_str)
		data->error = 1;
	return (num_str);
}

void	handle_int(t_printf *data)
{
	char	*str;
	long	num;

	str = get_int_str(data);
	if (data->error)
		return (free(str));
	num = ft_atol(str);
	apply_sign(&str, data, num);
	if (data->error)
		return (free(str));
	apply_precision_int(&str, data);
	if (data->error)
		return (free(str));
	apply_width(&str, data);
	if (data->error)
		return (free(str));
	ft_print_str(str, data);
	if (data->error)
		return (free(str));
	free(str);
}
