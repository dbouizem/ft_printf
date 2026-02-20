/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:00:00 by codex             #+#    #+#             */
/*   Updated: 2026/02/19 00:00:00 by codex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

static char	*get_unsignedint_str(t_printf *data)
{
	uintmax_t		num;
	char			*str;

	num = get_unsigned_value(data);
	if (data->error)
		return (NULL);
	if (num == 0 && data->precision == 0)
		str = ft_strdup("");
	else
		str = ft_ulltoa_base(num, DIGITS);
	if (!str)
		data->error = 1;
	return (str);
}

void	handle_uint(t_printf *data)
{
	char	*str;

	str = get_unsignedint_str(data);
	if (data->error || !str)
	{
		free(str);
		return ;
	}
	apply_precision_int(&str, data);
	if (!data->error)
		apply_width(&str, data, ft_strlen(str));
	if (!data->error)
		ft_print_str(str, data);
	free(str);
}
