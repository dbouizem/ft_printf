/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:14:19 by dbouizem          #+#    #+#             */
/*   Updated: 2025/04/08 13:31:16 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flags(const char **format, t_printf *data)
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

static void	parse_width_precision(const char **format, t_printf *data)
{
	if (**format == '*')
	{
		data->width = va_arg(data->args, int);
		if (data->width < 0)
		{
			data->minus = 1;
			data->width = -data->width;
		}
		(*format)++;
	}
	else if (ft_isdigit(**format))
		data->width = ft_atoi_print(format);
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			data->precision = va_arg(data->args, int);
			(*format)++;
		}
		else if (ft_isdigit(**format))
			data->precision = ft_atoi_print(format);
		if (data->precision < 0)
			data->precision = -1;
	}
}

static void	parse_length(char **format, t_printf *data)
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
	else if (**format == 'l')
	{
		data->length = LENGTH_L;
		(*format) += 1;
	}
	else if (**format == 'L')
	{
		data->length = LENGTH_BIG_L;
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

static void	dispatch_format(char specifier, t_printf *data)
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
		handle_hex(data, 0);
	else if (specifier == 'X')
		handle_hex(data, 1);
	else if (specifier == '%')
		ft_print_char('%', data);
	else
	{
		ft_print_char('%', data);
		ft_print_char(specifier, data);
	}
}

static void	parse_format(const char **format, t_printf *data)
{
	parse_flags(format, data);
	parse_width_precision(format, data);
	parse_length(format, data);
	if (ft_strchr("cspdiuxX%", **format))
	{
		dispatch_format(**format, data);
		(*format)++;
	}
	else
		handle_invalid_specifier(format, data);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_printf	data;

	va_start(ap, format);
	ft_memset(&data, 0, sizeof(t_printf));
	va_copy(data.args, ap);
	while (*format && !data.error)
	{
		if (*format == '%')
		{
			format++;
			parse_format(&format, &data);
		}
		else
			ft_print_char(*format, &data);
		format++;
	}
	va_end(ap);
	va_end(data.args);
	if (data.error)
		return (-1);
	return (data.total);
}
