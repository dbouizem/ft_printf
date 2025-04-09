/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 03:10:12 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/12 23:14:17 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_str(char *str, t_printf *data)
{
	char	*content;
	char	*buffer;
	int		len_c;
	int		len_b;

	if (data->error)
		return ;
	if (!str)
	{
		str = "(null)";
		return ;
	}
	len_c = ft_strlen(str);
	if (data->precision >= 0 && len_c > data->precision)
		len_c = data->precision;
	content = ft_substr(str, 0, len_c);
	if (!content)
	{
		data->error = 1;
		return ;
	}
	len_b = len_c;
	if (data->width > len_b)
		len_b = data->width;
	buffer = ft_calloc(len_b + 1, sizeof(char));
	if (!buffer)
	{
		free(content);
		return ;
	}
	ft_memset(buffer, ' ', len);
	buffer[len_b] = '\0';
	if (data->minus)
		ft_memcpy(buffer, content, len_c);
	else
		ft_memcpy(buffer + (len_b - len_c), content, len_c);
	ft_print_str(buffer, data);
	free(content);
	free(buffer);
}
