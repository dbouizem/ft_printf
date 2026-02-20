/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:00:00 by codex             #+#    #+#             */
/*   Updated: 2026/02/19 00:00:00 by codex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

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
	if (!data->error)
	{
		if (ft_strncmp(str, "(nil)", ft_strlen("(nil)")) != 0)
		{
			if (data->zero && !data->minus && data->precision < 0
				&& data->width > (int)ft_strlen(str) + 2)
			{
				data->precision = data->width - 2;
				data->width = 0;
			}
			apply_precision_int(&str, data);
			if (!data->error)
				add_ptr_prefix(&str, data);
		}
		if (!data->error)
			apply_width(&str, data, ft_strlen(str));
		if (!data->error)
			ft_print_str(str, data);
	}
	free(str);
}
