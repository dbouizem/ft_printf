/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:29:12 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/12 22:59:40 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_int(t_printf *data)
{
	char		*str;

	str = ft_itoa(va_arg(data->args, int));
	if (!str)
	{
		data->error = 1;
		return ;
	}
	ft_print_str(str, data);
	free(str);
}
