/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dispatch_format_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 02:06:28 by codex             #+#    #+#             */
/*   Updated: 2026/02/20 02:06:28 by codex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

static void	dispatch_percent(t_printf *data)
{
	ft_print_char('%', data);
}

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
		dispatch_percent(data);
	else
	{
		ft_print_char('%', data);
		ft_print_char(specifier, data);
	}
}
