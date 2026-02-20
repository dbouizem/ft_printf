/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 06:24:09 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/09 20:49:52 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_uint(t_printf *data)
{
	char	*str;

	str = ft_ulltoa_base((uintmax_t)va_arg(data->args, unsigned int), DIGITS);
	if (!str)
	{
		data->error = 1;
		return ;
	}
	ft_print_str(str, data);
	free(str);
}
