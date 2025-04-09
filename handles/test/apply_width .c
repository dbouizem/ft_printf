/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width .c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:43:46 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/15 06:07:48 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	apply_width(char **str, t_printf *data)
{
	char	*new;
	char	*buffer;
	char	pad;
	int		len_str;
	int		len_pad;

	if (!str || !*str || data->width <= (ft_strlen(*str)))
		return ;
	len_str = ft_strlen(*str);
	len_pad = data->width - len_str;
	pad = ' ';
	if (data->zero && !data->minus)
		pad = '0';
	buffer = ft_strfill(len_pad, pad);
	if (!buffer)
		return ;
	if (data->minus)
		new = ft_strjoin(*str, buffer);
	else
		new = ft_strjoin(buffer, *str);
	free(*str);
	free(buffer);
	*str = new;
}
