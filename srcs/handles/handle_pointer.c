/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 04:03:41 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/09 20:24:11 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_pointer(t_printf *data)
{
	uintptr_t	ptr;

	ptr = (uintptr_t)va_arg(data->args, void *);
	if (ptr == 0)
	{
		ft_print_str("(nil)", data);
		return ;
	}
	ft_print_str("0x", data);
	ft_print_hex(ptr, 0, data);
}
