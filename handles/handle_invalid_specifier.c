/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_invalid_specifier.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:16:15 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/13 00:00:01 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_invalid_specifier(const char **format, t_printf *data)
{
	ft_print_char('%', data);
	if (**format)
	{
		ft_print_char(**format, data);
		(*format)++;
	}
}
