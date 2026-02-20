/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:09:11 by dbouizem          #+#    #+#             */
/*   Updated: 2026/02/20 01:21:15 by codex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

static int	is_sign_char(char c)
{
	return (c == '-' || c == '+' || c == ' ');
}

static void	fill_minus(char *new_str, char *old, int padding, size_t old_len)
{
	ft_memcpy(new_str, old, old_len);
	ft_memset(new_str + old_len, ' ', padding);
}

static void	fill_zero_sign(char *new_str, char *old,
				int padding, size_t old_len)
{
	new_str[0] = old[0];
	ft_memset(new_str + 1, '0', padding);
	ft_memcpy(new_str + 1 + padding, old + 1, old_len - 1);
}

static void	fill_default(char *new_str, char *old, int padding, char pad_char)
{
	ft_memset(new_str, pad_char, padding);
	ft_memcpy(new_str + padding, old, ft_strlen(old));
}

void	apply_width(char **str, t_printf *data, int content_len)
{
	char	*old;
	char	*new_str;
	char	pad_char;
	size_t	old_len;
	int		padding;

	if (!str || !*str || data->width <= content_len)
		return ;
	old = *str;
	old_len = ft_strlen(old);
	padding = data->width - content_len;
	pad_char = ' ';
	if (data->zero && !data->minus && data->precision == -1)
		pad_char = '0';
	new_str = ft_calloc(old_len + padding + 1, sizeof(char));
	if (!new_str)
		return ((void)(data->error = 1));
	if (data->minus)
		fill_minus(new_str, old, padding, old_len);
	else if (pad_char == '0' && is_sign_char(old[0]))
		fill_zero_sign(new_str, old, padding, old_len);
	else
		fill_default(new_str, old, padding, pad_char);
	free(old);
	*str = new_str;
}
