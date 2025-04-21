/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 04:03:41 by dbouizem          #+#    #+#             */
/*   Updated: 2025/04/14 02:07:11 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*get_hexptr_str(t_printf *data)
{
	char			*p_str;
	uintptr_t		ptr;

	ptr = (uintptr_t)va_arg(data->args, void *);
	if (ptr == 0)
		return (ft_strdup("(nil)"));
	p_str = ft_ulltoa_base(ptr, HEXLOW);
	if (!p_str)
		data->error = 1;
	return (p_str);
}

static void	add_ptr_prefix(char **str, t_printf *data)
{
	char	*new;

	if (data->error || !str || !*str)
		return ;
	new = ft_strjoin("0x", *str);
	if (!new)
	{
		data->error = 1;
		return ;
	}
	free(*str);
	*str = new;
}

void	handle_pointer(t_printf *data)
{
	char	*str;

	str = get_hexptr_str(data);
	if (data->error)
		return (free(str));
	if (ft_strncmp(str, "(nil)", ft_strlen("(nil)")) != 0)
	{
		apply_precision(&str, data);
		if (data->error)
			return (free(str));
		add_ptr_prefix(&str, data);
		if (data->error)
			return (free(str));
	}
	apply_width(&str, data, ft_strlen(str));
	if (data->error)
		return (free(str));
	ft_print_str(str, data);
	if (data->error)
		return (free(str));
	free(str);
}
