/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:04:17 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/02 02:53:07 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

char	*ft_strfill(size_t size, char c)
{
	char	*buffer;

	buffer = malloc((size + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	ft_memset(buffer, c, size);
	buffer[size] = '\0';
	return (buffer);
}
