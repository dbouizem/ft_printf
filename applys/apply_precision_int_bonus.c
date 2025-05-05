/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision_int_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:37:04 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/02 02:50:27 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

void	apply_precision_int(char **str, t_printf *data)
{
	char	*num_part;
	char	*zeros;
	char	*tmp;
	char	*old_str;
	int		sign;

	sign = (**str == '-');
	num_part = *str + sign;
	if (data->precision < 0 || !str || !*str
		|| data->precision <= (int)ft_strlen(num_part))
		return ;
	old_str = *str;
	zeros = ft_strfill(data->precision - ft_strlen(num_part), '0');
	if (sign)
	{
		tmp = ft_strjoin("-", zeros);
		*str = ft_strjoin(tmp, num_part);
		free(tmp);
	}
	else
		*str = ft_strjoin(zeros, num_part);
	free(zeros);
	free(old_str);
	if (!*str)
		data->error = 1;
}
