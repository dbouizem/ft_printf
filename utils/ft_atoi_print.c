/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:30:52 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/10 22:46:56 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_atoi_print(char **str)
{
	int	res;

	res = 0;
	while (ft_isdigit(**str))
	{
		res = res * 10 + (**str - '0');
		(*str)++;
	}
	return (res);
}
