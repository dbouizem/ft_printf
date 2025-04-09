/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 06:23:01 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/16 02:13:43 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	apply_sign(char **str, t_printf *data, int num)
{
	char	*sign;
	char	*new;

	sign = NULL;
	if (num < 0)
		sign = "-";
	else if (data->plus)
		sign = "+";
	else if (data->space)
		sign = " ";
	else
		return ;
	new = ft_strjoin(sign, *str);
	free(*str);
	*str = new;
}
