/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 05:19:12 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/14 01:59:42 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_int(t_printf *data)
{
	int		n;
	char	*num_str;
	char	*final_str;

	n = va_arg(data->arg, int);
	apply_flags(n, data->minus, data->plus, data->space);
	num_str = ft_itoa(n);
	if (!num_str)
	{
		data->error = 1;
		return ;
	}
	apply_presion_int(num, data->precision);
	final_str = apply_width(num, data->width, data->minus, data->zero);
	if (!final_str)
	{
		data->error = 1;
		free(num_str);
		return ;
	}
	ft_print_str(final_str, data);
	free(final_str);
}
