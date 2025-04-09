/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 05:15:02 by dbouizem          #+#    #+#             */
/*   Updated: 2025/03/01 08:56:36 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*get_hex_str(t_printf *data, int uppercase)
{
	unsigned int	num;
	char			*num_str;
	char			*base;

	num = va_arg(data->args, unsigned int);
	base = HEXLOW;
	if (uppercase)
		base = HEXUPP;
	if (num == 0 && data->precision == 0)
		num_str = strdup("");
	else
		num_str = ft_ulltoa_base(num, base);
	if (!num_str)
		data->error = 1;
	return (num_str);
}

void	handle_hex(int uppercase, t_printf *data)
{
	char			*str;
	unsigned int	num;
	size_t			len;

	str = get_hex_str(data, uppercase);
	if (data->error)
		return (free(str));
	apply_precision(&str, data);
	if (data->error)
		return (free(str));
	num = ft_atol(str);
	len = ft_strlen(num);
	if (ft_strncmp(str, "0", len) != 0 && ft_strncmp(str, "", len) != 0)
		apply_hash(&str, data, uppercase);
	if (data->error)
		return (free(str));
	apply_width(&str, data);
	if (data->error)
		return (free(str));
	ft_print_str(str, data);
	if (data->error)
		return (free(str));
	free(str);
}
