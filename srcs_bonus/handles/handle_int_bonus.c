/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:00:00 by codex             #+#    #+#             */
/*   Updated: 2026/02/19 00:00:00 by codex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

static char	*get_signedint_str(t_printf *data, intmax_t num)
{
	char		*str;
	uintmax_t	un;

	if (num == 0 && data->precision == 0)
		str = ft_strdup("");
	else
	{
		if (num < 0)
			un = (uintmax_t)(-(num + 1)) + 1;
		else
			un = (uintmax_t)num;
		str = ft_itoa_print(un);
	}
	if (!str)
		data->error = 1;
	return (str);
}

void	handle_int(t_printf *data)
{
	char		*str;
	intmax_t	num;

	num = get_signed_value(data);
	if (data->error)
		return ;
	str = get_signedint_str(data, num);
	if (data->error)
	{
		free(str);
		return ;
	}
	apply_precision_int(&str, data);
	if (!data->error)
		apply_sign(&str, data, num);
	if (!data->error)
		apply_width(&str, data, ft_strlen(str));
	if (!data->error)
		ft_print_str(str, data);
	free(str);
}
