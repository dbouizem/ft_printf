/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_reset_data_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:22:28 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/13 03:33:04 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BONUS
#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

void	handle_reset_printf_data(t_printf *data)
{
	data->minus = 0;
	data->zero = 0;
	data->hash = 0;
	data->space = 0;
	data->plus = 0;
	data->width = 0;
	data->precision = -1;
	data->length = 0;
}
