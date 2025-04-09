/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 04:57:50 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/09 08:54:17 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_str(char *s, t_printf *data)
{
	if (data->error || !s)
		return ;
	ft_putstr_fd(s, 1);
	data->total += ft_strlen(s);
}
