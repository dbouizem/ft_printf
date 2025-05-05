/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_hash_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 03:51:10 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/02 02:50:04 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

void	apply_hash(char **str, t_printf *data, int uppercase)
{
	char	*prefixe;
	char	*result;

	if (!str || !*str || !data->hash || (**str == '0' && **str != '\0'))
		return ;
	prefixe = "0x";
	if (uppercase)
		prefixe = "0X";
	result = ft_strjoin(prefixe, *str);
	if (!result)
	{
		data->error = 1;
		return ;
	}
	free(*str);
	*str = result;
}
