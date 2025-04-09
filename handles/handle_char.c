/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:51:52 by dbouizem          #+#    #+#             */
/*   Updated: 2025/04/08 17:23:34 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*get_char_str(char c)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = c;
	return (str);
}

void	handle_char(t_printf *data)
{
	char		c;
	char		*str;
	wint_t		wc;

	if (data->length == LENGTH_L)
	{
		wc = va_arg(data->args, wint_t);
		str = wint_to_str(wc);
	}
	else
	{
		c = (char)va_arg(data->args, int);
		str = get_char_str(c);
	}
	if (!str)
	{
		data->error = 1;
		return ;
	}
	apply_width(&str, data);
	if (data->error)
		return (free(str));
	ft_print_str(str, data);
	free(str);
}
