/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 05:15:02 by dbouizem          #+#    #+#             */
/*   Updated: 2025/04/13 23:41:40 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
	if (data->error)
		return (free(str));
	apply_precision_int(&str, data);
	if (data->error)
		return (free(str));
	if (!data->error && num != 0)
		apply_hash(&str, data, uppercase);
	if (data->error)
		return (free(str));
	apply_width(&str, data, ft_strlen(str));
	if (data->error)
		return (free(str));
	ft_print_str(str, data);
	if (data->error)
		return (free(str));
	free(str);
}
