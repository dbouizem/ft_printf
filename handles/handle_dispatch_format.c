/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dispatch_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:30:32 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/13 02:23:05 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_dispatch_format(char specifier, t_printf *data)
{
	if (!specifier || data->error)
		return ;
	if (specifier == 'c')
		handle_char(data);
	else if (specifier == 's')
		handle_string(data);
	else if (specifier == 'p')
		handle_pointer(data);
	else if (specifier == 'd' || specifier == 'i')
		handle_int(data);
	else if (specifier == 'u')
		handle_uint(data);
	else if (specifier == 'x')
		handle_hex(0, data);
	else if (specifier == 'X')
		handle_hex(1, data);
	else if (specifier == '%')
		ft_print_char('%', data);
	else
	{
		ft_print_char('%', data);
		ft_print_char(specifier, data);
	}
}
