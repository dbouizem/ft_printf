/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:21:38 by dbouizem          #+#    #+#             */
/*   Updated: 2025/04/08 23:36:20 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>//Test
# include <limits.h>//Test
# include <stdint.h>//pour utiliser uintmax_t/intmax_t
# include <wchar.h>

# define DIGITS "0123456789"
# define HEXLOW "0123456789abcdef"
# define HEXUPP "0123456789ABCDEF"
# define OCTAL "01234567"

// Valeurs limites Unicode
# define UCODE_MAX	0x10FFFF
// Zone interdite (surrogates UTF-16)
# define UCODE_S_MIN	0xD800
# define UCODE_S_MAX	0xDFFF


/* Unicode Ranges */
# define UNICODE_MAX			0x10FFFF	// 65536 – 1114111	😀, 🐍
# define ASCII_MAX				0x7F		// 0 – 127			A, B, C
# define UTF8_2_BYTES_MAX		0x7FF		// 128 – 2047		é, ñ, Ω
# define UTF8_3_BYTES_MAX		0xFFFF		// 2048 – 65535		你, أ

/* UTF-16 Surrogate Range (interdite en UTF-8) */
# define UTF16_SURROGATE_MIN	0xD800
# define UTF16_SURROGATE_MAX	0xDFFF

/* UTF-8 Masks */
# define UTF8_MASK_1BYTE	0x00	// pas utilisé, 0xxxxxxx (ASCII)
# define UTF8_MASK_2BYTE	0xC0	// 110xxxxx
# define UTF8_MASK_3BYTE	0xE0	// 1110xxxx
# define UTF8_MASK_4BYTE	0xF0	// 11110xxx
# define UTF8_MASK_CONT		0x80	// 10xxxxxx (continuation byte)
# define UTF8_6BITS			0x3F	// pour extraire 6 bits (0011 1111)



/*-BN-*/
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
	LENGTH_BIG_L
}	t_length;

typedef struct s_printf
{
	int		total;
	int		error;
	//--- Bonus Flags ---
	va_list	args;
	int		width;
	int		precision;
	int		minus;
	int		zero;
	int		hash;
	int		space;
	int		plus;
}		t_printf;

/*Functions*/
int			ft_printf(const char *formant, ...);

void		handle_char(t_printf *data);
void		handle_string(t_printf *data);
void		handle_pointer(t_printf *data);
void		handle_hex(int uppercase, t_printf *data);
void		handle_int(t_printf *data);
void		handle_uint(t_printf *data);
/*-BN-*/
void		handle_invalid_specifier(const char **format, t_printf *data);


void		ft_print_char(char c, t_printf *data);
void		ft_print_str(char *s, t_printf *data);
void		ft_print_hex(unsigned long n, int uppercase, t_printf *data);
/*-BN-*/
//long	ft_itol(const char *str);
long		ft_atol(const char *str);
int			ft_atoi_print(char **str);
char		ft_strfill(size_t size, char c);
char		ft_utoa(unsigned int n);
char		*ft_ulltoa_base(unsigned long long n, const char *base);
intmax_t	get_signed_value(t_printf *data);
uintmax_t	get_unsigned_value(t_printf *data);

/*BN*/
void		apply_width(char **str, t_printf *data);
void		apply_precision(char **str, t_printf *data);
void		apply_precision_int(char **str, t_printf *data);
void		apply_sign(char **str, t_printf *data, int num);
void		apply_hash(char **str, t_printf *data, int base);

#endif
