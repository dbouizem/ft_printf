/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:09:07 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/13 03:33:23 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

void	parse_flags(const char **format, t_printf *data)
{
	if (data->error || !format || !*format)
		return ;
	while (ft_strchr("-0# +", **format))
	{
		if (**format == '-')
		{
			data->minus = 1;
			data->zero = 0;
		}
		else if (**format == '0' && !data->minus)
			data->zero = 1;
		else if (**format == '#')
			data->hash = 1;
		else if (**format == ' ' && !data->plus)
			data->space = 1;
		else if (**format == '+')
		{
			data->plus = 1;
			data->space = 0;
		}
		(*format)++;
	}
}
