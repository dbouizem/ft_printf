/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:11:18 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/11 19:15:42 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"
#ifdef BONUS
# include "../ft_printf_bonus.h"

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

#else

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

#endif
