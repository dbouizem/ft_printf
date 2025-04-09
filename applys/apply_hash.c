/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 03:51:10 by dbouizem          #+#    #+#             */
/*   Updated: 2025/03/02 09:42:07 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	apply_hash(char **str, t_printf *data, int base)
{
	char	*prefixe;
	char	*result;
	size_t	len;

	if (!str || !*str || !data->hash || (**str == '0' && **str != '\0'))
		return ;
	len = ft_strlen(*str);
	if (ft_strncmp(base, HEXLOW, len) == 0)
		prefix = "0x";
	else if (ft_strncmp(base, HEXUPP, len) == 0)
		prefix = "0X";
	else if (ft_strncmp(base, OCTAL, len) == 0 && **str != '0')
		prefix = "0";
	else
		return ;
	result = ft_strjoin(prefixe, *str);
	if (!result)
	{
		data->error = 1;
		return ;
	}
	free(*str);
	*str = result;
}
