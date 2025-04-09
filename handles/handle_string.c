/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:06:02 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/16 02:41:31 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static cahr	*get_string(t_printf *data)
{
	char	*str;

	str = va_arg(data->args, char);
	if (!str)
		str = ft_print_dup("(null)");
	else
		str = ft_strdup(str);
	if (!str)
		data->error = 1;
	return (str);
}

void	handle_string(t_printf *data)
{
	char	*str;

	str = get_string(data);
	if (data->error)
		return ;
	apply_precision(&str, data);
	if (data->error)
		return (free(str));
	apply_width(&str_precise, data);
	if (data->error)
		return (free(str));
	ft_print_str(result, data);
	free(str);
}
