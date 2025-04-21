/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:29:12 by dbouizem          #+#    #+#             */
/*   Updated: 2025/04/13 04:00:14 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_int(t_printf *data)
{
	char		*str;
	intmax_t	num;

	num = get_signed_value(data);
	if (data->error)
		return ;
	if (num == 0 && data->precision == 0)
		str = ft_strdup("");
	else
		str = ft_itoa_print(num);
	if (!str)
	{
		data->error = 1;
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
