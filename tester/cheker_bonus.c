/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 02:25:03 by codex             #+#    #+#             */
/*   Updated: 2026/02/20 02:25:03 by codex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

static void	check_bonus_flags(void)
{
	printf("\n===== BONUS FLAGS / WIDTH / PRECISION =====\n");
	ft_printf("+ flag            : [%+d]\n", 42);
	ft_printf("Space flag        : [% d]\n", 42);
	ft_printf("Zero padded       : [%05d]\n", 42);
	ft_printf("Left align        : [%-5d]\n", 42);
	ft_printf("Precision         : [%.4d]\n", 42);
	ft_printf("Width + prec      : [%8.4d]\n", 42);
	ft_printf("Zero + .0         : [%.0d]\n", 0);
	ft_printf("Zero + width .0   : [%5.0d]\n", 0);
	ft_printf("Zero padded       : [%08u]\n", 123456);
	ft_printf("Precision         : [%.5u]\n", 123);
	ft_printf("Width + prec      : [%10.5u]\n", 123);
	ft_printf("Zero with .0      : [%.0u]\n", 0);
	ft_printf("With # lower      : [%#x]\n", 255);
	ft_printf("With # upper      : [%#X]\n", 255);
	ft_printf("Zero padded       : [%08x]\n", 255);
	ft_printf("Precision         : [%.4x]\n", 255);
	ft_printf("Width + prec      : [%10.4x]\n", 255);
	ft_printf("Zero with .0      : [%.0x]\n", 0);
	ft_printf("Zero with #       : [%#x]\n", 0);
	ft_printf("Width + %%         : [%5%]\n");
	ft_printf("Left align %%      : [%-5%]\n");
}

static void	check_bonus_length_signed(void)
{
	printf("\n===== MODIFICATEURS DE LENGTH =====\n");
	ft_printf("%%hd  : [%hd]\n", (short)-32768);
	ft_printf("%%hhd : [%hhd]\n", (signed char)-128);
	ft_printf("%%ld  : [%ld]\n", 2147483648L);
	ft_printf("%%lld : [%lld]\n", 9223372036854775807LL);
}

static void	check_bonus_length_unsigned(void)
{
	ft_printf("%%hu  : [%hu]\n", (unsigned short)65535);
	ft_printf("%%hhu : [%hhu]\n", (unsigned char)255);
	ft_printf("%%lu  : [%lu]\n", 4294967295UL);
	ft_printf("%%llu : [%llu]\n", 18446744073709551615ULL);
	ft_printf("%%lx  : [%lx]\n", 4294967295UL);
	ft_printf("%%llx : [%llx]\n", 18446744073709551615ULL);
	ft_printf("%%lX  : [%lX]\n", 4294967295UL);
	ft_printf("%%llX : [%llX]\n", 18446744073709551615ULL);
}

void	run_cheker_bonus(void)
{
	check_bonus_flags();
	check_bonus_length_signed();
	check_bonus_length_unsigned();
}
