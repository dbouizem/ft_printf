/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:00:00 by codex             #+#    #+#             */
/*   Updated: 2026/02/19 00:00:00 by codex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

void	parse_format(const char **format, t_printf *data)
{
	parse_flags(format, data);
	parse_width_precision(format, data);
	parse_length(format, data);
	if (!ft_strchr("cspdiuxX%", **format))
		handle_invalid_specifier(format, data);
	else
	{
		handle_dispatch_format(**format, data);
		(*format)++;
	}
	handle_reset_printf_data(data);
}
