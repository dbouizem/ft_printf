/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:21:38 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/13 02:23:53 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>//Test
# include <limits.h>//Test
# include <stdint.h>//pour utiliser uintmax_t/intmax_t/uintptr_t
# include <wchar.h>//pour wchar_t
# include <stddef.h>//ptrdiff_t

# define DIGITS "0123456789"
# define HEXLOW "0123456789abcdef"
# define HEXUPP "0123456789ABCDEF"
# define OCTAL "01234567"

# ifdef BONUS

typedef enum e_length
{
	LENGTH_NONE,
	LENGTH_HH,
	LENGTH_H,
	LENGTH_L,
	LENGTH_LL,
	LENGTH_J,
	LENGTH_Z,
	LENGTH_T,
}	t_length;

typedef struct s_printf
{
	int			total;
	int			error;
	va_list		args;
	int			width;
	int			precision;
	int			minus;
	int			zero;
	int			hash;
	int			space;
	int			plus;
	t_length	length;
}		t_printf;

# else

typedef struct s_printf
{
	int			total;
	int			error;
	va_list		args;
}		t_printf;

# endif

/*Functions*/
int			ft_printf(const char *formant, ...);

void		parse_format(const char **format, t_printf *data);

void		handle_dispatch_format(char specifier, t_printf *data);
void		handle_char(t_printf *data);
void		handle_string(t_printf *data);
void		handle_pointer(t_printf *data);
void		handle_hex(int uppercase, t_printf *data);
void		handle_int(t_printf *data);
void		handle_uint(t_printf *data);
void		handle_invalid_specifier(const char **format, t_printf *data);

void		ft_print_char(char c, t_printf *data);
void		ft_print_str(char *s, t_printf *data);
void		ft_print_hex(unsigned long n, int uppercase, t_printf *data);
char		*ft_itoa_print(uintmax_t un);
char		*ft_ulltoa_base(uintmax_t n, const char *base);

#endif
