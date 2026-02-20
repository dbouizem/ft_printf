/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 05:15:02 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/09 21:00:22 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_hex(int uppercase, t_printf *data)
{
	unsigned int	n;

	n = va_arg(data->args, unsigned int);
	ft_print_hex((unsigned long)n, uppercase, data);
}
