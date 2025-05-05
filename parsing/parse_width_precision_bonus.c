/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width_precision_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:09:55 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/05 20:57:42 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

static void	parse_width(const char **format, t_printf *data)
{
	if (**format == '*')
	{
		data->width = va_arg(data->args, int);
		if (data->width < 0)
		{
			data->minus = 1;
			data->width = -data->width;
		}
		(*format)++;
	}
	else if (ft_isdigit(**format))
	{
		data->width = 0;
		while (ft_isdigit(**format))
		{
			data->width = data->width * 10 + (**format - '0');
			(*format)++;
		}
	}
}

static void	parse_precision(const char **format, t_printf *data)
{
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			data->precision = va_arg(data->args, int);
			(*format)++;
			if (data->precision < 0)
				data->precision = -1;
		}
		else if (ft_isdigit(**format))
		{
			data->precision = 0;
			while (ft_isdigit(**format))
			{
				data->precision = data->precision * 10 + (**format - '0');
				(*format)++;
			}
		}
		else
			data->precision = 0;
	}
	else
		data->precision = -1;
}

void	parse_width_precision(const char **format, t_printf *data)
{
	parse_width(format, data);
	parse_precision(format, data);
}
/*
Problème:

--ft_printf("%5d %d", 42, 123);
Première conversion (%5d) :
data->width devient 5.
Deuxième conversion (%d) :
Si tu ne réinitialises pas data->width, il reste à 5 → bug !
=> data->whith = 0 ----------> SOLVED

--ft_printf("%.3d %.2f", 5, 3.1415);

--data->precision = 0;
ex: %.42d :
On commence à 0, puis on accumule les chiffres.
.42 → 0 * 10 + 4 = 4 → 4 * 10 + 2 = 42
ex: %.d :
printf considère que . seul équivaut à une précision de 0
*/
