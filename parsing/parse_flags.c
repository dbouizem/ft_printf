/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:09:07 by dbouizem          #+#    #+#             */
/*   Updated: 2025/04/10 17:59:01 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	parse_flags(const char **format, t_printf *data)
{
	if (data->error || !format || !*format)
		return ;
	while (ft_strchr("-0# +", **format))
	{
		if (**format == '-')
			data->minus = 1;
		else if (**format == '0')
			data->zero = 1;
		else if (**format == '#')
			data->hash = 1;
		else if (**format == ' ')
			data->space = 1;
		else if (**format == '+')
			data->plus = 1;
		(*format)++;
	}
}
