/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:29:12 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/12 22:59:40 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#ifdef BONUS
# include "../ft_printf_bonus.h"

static char	*get_signedint_str(t_printf *data, intmax_t num)
{
	char		*str;
	uintmax_t	un;

	if (num == 0 && data->precision == 0)
		str = ft_strdup("");
	else
	{
		if (num < 0)
			un = (uintmax_t)(-num);
		else
			un = (uintmax_t)num;
		str = ft_itoa_print(un);
	}
	if (!str)
		data->error = 1;
	return (str);
}

void	handle_int(t_printf *data)
{
	char		*str;
	intmax_t	num;

	num = get_signed_value(data);
	if (data->error)
		return ;
	str = get_signedint_str(data, num);
	if (data->error)
	{
		free(str);
		return ;
	}
	apply_precision_int(&str, data);
	if (!data->error)
		apply_sign(&str, data, num);
	if (!data->error)
		apply_width(&str, data, ft_strlen(str));
	if (!data->error)
		ft_print_str(str, data);
	free(str);
}

#else

void	handle_int(t_printf *data)
{
	char		*str;

	str = ft_itoa_print((intmax_t)va_arg(data->args, int));
	if (!str)
	{
		data->error = 1;
		return ;
	}
	ft_print_str(str, data);
	free(str);
}

#endif
