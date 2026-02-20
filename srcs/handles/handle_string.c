/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:06:02 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/04 04:43:56 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_string(t_printf *data)
{
	char		*str;

	str = va_arg(data->args, char *);
	if (!str)
		str = "(null)";
	ft_print_str(str, data);
}
