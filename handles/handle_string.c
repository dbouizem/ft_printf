/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:06:02 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/04 04:43:56 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#ifdef BONUS
# include "../ft_printf_bonus.h"

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
		apply_width(&str, data, ft_strlen(str));
	if (!data->error)
		ft_print_str(str, data);
	free(str);
}

#else

void	handle_string(t_printf *data)
{
	char		*str;

	str = va_arg(data->args, char *);
	if (!str)
		str = "(null)";
	ft_print_str(str, data);
}

#endif
