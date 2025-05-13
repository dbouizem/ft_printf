/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:23:22 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/13 03:33:31 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BONUS
#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

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
		(*format)++;
	}
	else if (**format == 'l')
	{
		data->length = LENGTH_L;
		(*format)++;
	}
	else if (**format == 'j')
	{
		data->length = LENGTH_J;
		(*format)++;
	}
	else if (**format == 'z')
	{
		data->length = LENGTH_Z;
		(*format)++;
	}
	else if (**format == 't')
	{
		data->length = LENGTH_T;
		(*format)++;
	}
}

void	parse_length(const char **format, t_printf *data)
{
	handle_two_char_length(format, data);
	handle_one_char_length(format, data);
}
