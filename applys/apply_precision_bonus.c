/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 03:28:44 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/13 03:31:03 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

void	apply_precision(char **str, t_printf *data)
{
	char	*new_str;
	size_t	precision;
	size_t	str_len;

	if (!str || *str == NULL || data->precision < 0)
		return ;
	precision = (size_t)data->precision;
	if (**str == '\0')
	{
		new_str = ft_strdup("");
		if (*str)
			free(*str);
		*str = new_str;
		return ;
	}
	str_len = ft_strlen(*str);
	if (str_len > precision)
	{
		new_str = ft_substr(*str, 0, precision);
		free(*str);
		*str = new_str;
	}
}
