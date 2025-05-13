/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 02:21:43 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/13 03:29:49 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

#define BONUS
# include "ft_printf.h"

// Zone interdite (surrogates UTF-16)
/*
-- Correspond à une zone spéciale de code points réservée pour
-- encoder les caractères au-delà de 0xFFFF dans UTF-16
-- Les surrogates ne sont pas des caractères valides en eux-mêmes,
-- ils servent uniquement à l’encodage. Leur présence isolée dans
-- une chaîne est généralement une erreur ou un signe de corruption
*/
# define UCODE_S_MIN	0xD800
# define UCODE_S_MAX	0xDFFF

/* Unicode Ranges */
# define UCODE_MAX				0x10FFFF	// 65536 – 1114111	😀, 🐍
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

void		handle_reset_printf_data(t_printf *data);

void		parse_flags(const char **format, t_printf *data);
void		parse_width_precision(const char **format, t_printf *data);
void		parse_length(const char **format, t_printf *data);

intmax_t	get_signed_value(t_printf *data);
uintmax_t	get_unsigned_value(t_printf *data);
char		*get_wchar_utf8_str(wchar_t wc, t_printf *data);
char		*get_wstr_utf8_str(wchar_t *wstr, t_printf *data);

void		apply_width(char **str, t_printf *data, int char_width);
void		apply_precision(char **str, t_printf *data);
void		apply_precision_int(char **str, t_printf *data);
void		apply_sign(char **str, t_printf *data, int num);
void		apply_hash(char **str, t_printf *data, int base);

char		*ft_strfill(size_t size, char c);
size_t		ft_wcrtomb(char *s, wchar_t wc);

#endif
