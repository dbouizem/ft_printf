/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:00:00 by codex             #+#    #+#             */
/*   Updated: 2026/02/19 00:00:00 by codex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

static char	*get_char_str(char c)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = c;
	return (str);
}

static void	print_null_char(t_printf *data)
{
	int	pad;
	int	i;

	pad = data->width - 1;
	if (pad < 0)
		pad = 0;
	if (!data->minus)
	{
		i = 0;
		while (i++ < pad)
			ft_print_char(' ', data);
		ft_print_char('\0', data);
	}
	else
	{
		ft_print_char('\0', data);
		i = 0;
		while (i++ < pad)
			ft_print_char(' ', data);
	}
}

static char	*get_char_value(t_printf *data)
{
	char	c;

	if (data->length == LENGTH_L)
		return (get_wchar_utf8_str(va_arg(data->args, wchar_t), data));
	c = (char)va_arg(data->args, int);
	if (c == '\0')
	{
		print_null_char(data);
		return (NULL);
	}
	return (get_char_str(c));
}

void	handle_char(t_printf *data)
{
	char	*str;

	str = get_char_value(data);
	if (!str)
		return ;
	if (!data->error)
		data->zero = 0;
	if (!data->error)
		apply_width(&str, data, 1);
	ft_print_str(str, data);
	free(str);
}
