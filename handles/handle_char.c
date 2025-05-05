/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:51:52 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/04 00:35:00 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#ifdef BONUS
# include "../ft_printf_bonus.h"
#endif

static char	*get_char_str(char c)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = c;
	return (str);
}

#ifdef BONUS

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

void	handle_char(t_printf *data)
{
	char		c;
	char		*str;
	wchar_t		wc;

	if (data->length == LENGTH_L)
	{
		wc = va_arg(data->args, wchar_t);
		str = get_wchar_utf8_str(wc, data);
	}
	else
	{
		c = (char)va_arg(data->args, int);
		if (c == '\0')
		{
			print_null_char(data);
			return ;
		}
		str = get_char_str(c);
	}
	if (!str)
		return ;
	if (!data->error)
		apply_width(&str, data, 1);
	ft_print_str(str, data);
	free(str);
}

#else

void	handle_char(t_printf *data)
{
	char		*str;

	str = get_char_str((char)va_arg(data->args, int));
	if (!str)
	{
		data->error = 1;
		return ;
	}
	ft_print_str(str, data);
	free(str);
}

#endif
