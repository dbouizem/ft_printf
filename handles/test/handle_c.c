/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:46:47 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/12 23:48:13 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_char(char c, t_printf *data)
{
	char	*buffer;
	int		size;

	if (data->error)
		return ;
	if (data->width <= 1)
	{
		ft_print_char(c, data);
		return ;
	}
	size = data->width;
	buffer = ft_calloc(size + 1, sizeof(char));
	if (!buffer)
	{
		data->error = 1;
		return ;
	}
	ft_memset(buffer, ' ', size);
	buffer[size] = '\0';
	if (data->minus)
		buffer[0] = c;
	else
		buffer[size - 1] = c;
	ft_print_str(buffer, data);
	free(buffer);
}
