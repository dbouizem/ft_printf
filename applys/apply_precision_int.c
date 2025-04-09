/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:37:04 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/14 15:36:26 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	apply_precision_int(char **str, t_printf *data)
{
	int		len_str;
	int		len_n;
	char	*zeros;

	len_str = ft_strlen(*str);
	len_n = data->precision - len_str;
	if (len_n > 0)
	{
		zeros = ft_strfill(len_n, '0');
		new = ft_strjoin(zeros, *str);
		free(*str);
		free(zeros);
		*str = new;
	}
}
