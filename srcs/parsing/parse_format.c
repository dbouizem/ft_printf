/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:11:18 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/14 11:34:11 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_format(const char **format, t_printf *data)
{
	if (ft_strchr("cspdiuxX%", **format))
	{
		handle_dispatch_format(**format, data);
		(*format)++;
	}
	else
		handle_invalid_specifier(format, data);
}
