/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:00:00 by codex             #+#    #+#             */
/*   Updated: 2026/02/19 00:00:00 by codex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

static char	*get_string(t_printf *data)
{
	char	*str;

	str = va_arg(data->args, char *);
	if (!str)
	{
		if (data->precision >= 0 && (size_t)data->precision < 6)
			return (ft_strdup(""));
		return (ft_strdup("(null)"));
	}
	else
		str = ft_strdup(str);
	if (!str)
		data->error = 1;
	return (str);
}

void	handle_string(t_printf *data)
{
	char		*str;
	wchar_t		*wstr;

	if (data->length == LENGTH_L)
	{
		wstr = va_arg(data->args, wchar_t *);
		str = get_wstr_utf8_str(wstr, data);
	}
	else
		str = get_string(data);
	if (data->error || str == NULL)
	{
		free(str);
		return ;
	}
	apply_precision(&str, data);
	if (!data->error)
		data->zero = 0;
	if (!data->error)
		apply_width(&str, data, ft_strlen(str));
	if (!data->error)
		ft_print_str(str, data);
	free(str);
}
