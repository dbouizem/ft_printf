/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:23:22 by dbouizem          #+#    #+#             */
/*   Updated: 2025/04/12 19:29:35 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	handle_two_char_length(const char **format, t_printf *data)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		data->length = LENGTH_HH;
		(*format) += 2;
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		data->length = LENGTH_LL;
		(*format) += 2;
	}
}

static void	handle_one_char_length(const char **format, t_printf *data)
{
	if (**format == 'h')
	{
		data->length = LENGTH_H;
		(*format) += 1;
	}
	else if (**format == 'l')
	{
		data->length = LENGTH_L;
		(*format) += 1;
	}
	else if (**format == 'j')
	{
		data->length = LENGTH_J;
		(*format) += 1;
	}
	else if (**format == 'z')
	{
		data->length = LENGTH_Z;
		(*format) += 1;
	}
	else if (**format == 't')
	{
		data->length = LENGTH_T;
		(*format) += 1;
	}
}

void	parse_length(const char **format, t_printf *data)
{
	handle_two_char_length(format, data);
	handle_one_char_length(format, data);
}
