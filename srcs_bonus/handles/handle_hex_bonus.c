/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:00:00 by codex             #+#    #+#             */
/*   Updated: 2026/02/19 00:00:00 by codex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

static char	*get_hex_str(uintmax_t num, t_printf *data, int uppercase)
{
	char			*num_str;
	char			*base;

	base = HEXLOW;
	if (uppercase)
		base = HEXUPP;
	if (num == 0 && data->precision == 0)
		num_str = ft_strdup("");
	else
		num_str = ft_ulltoa_base(num, base);
	if (!num_str)
		data->error = 1;
	return (num_str);
}

void	handle_hex(int uppercase, t_printf *data)
{
	uintmax_t		num;
	char			*str;

	num = get_unsigned_value(data);
	if (data->error)
		return ;
	str = get_hex_str(num, data, uppercase);
	if (!str)
		return ;
	apply_precision_int(&str, data);
	if (!data->error && num != 0)
		apply_hash(&str, data, uppercase);
	if (!data->error)
		apply_width(&str, data, ft_strlen(str));
	if (!data->error)
		ft_print_str(str, data);
	free(str);
}
