/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:55:54 by dbouizem          #+#    #+#             */
/*   Updated: 2025/05/13 01:27:00 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

int main(void)
{
	int x = 42;

	printf("===== SPECIFIER: %%c =====\n");
	ft_printf("Char simple       : [%c]\n", 'A');
	ft_printf("Char with width   : [%5c]\n", 'B');
	ft_printf("Char left align   : [%-5c]\n", 'C');
	ft_printf("Char \\0           : [%c]\n", '\0');
	ft_printf("Char \\0 padded    : [%5c]\n", '\0');

	printf("\n===== SPECIFIER: %%s =====\n");
	ft_printf("String simple     : [%s]\n", "Hello");
	ft_printf("String width      : [%10s]\n", "World");
	ft_printf("String precision  : [%.3s]\n", "Truncate");
	ft_printf("Left align + prec : [%-10.5s]\n", "Align");
	ft_printf("NULL string       : [%s]\n", (char *)NULL);
	ft_printf("NULL str width    : [%10s]\n", (char *)NULL);
	ft_printf("NULL str prec     : [%.3s]\n", (char *)NULL);

	printf("\n===== SPECIFIER: %%p =====\n");
	ft_printf("Pointer address   : [%p]\n", &x);
	ft_printf("NULL pointer      : [%p]\n", NULL);

	printf("\n===== SPECIFIER: %%d / %%i =====\n");
	ft_printf("Int simple        : [%d]\n", 42);
	ft_printf("Negative int      : [%i]\n", -42);
	ft_printf("+ flag            : [%+d]\n", 42);
	ft_printf("Space flag        : [% d]\n", 42);
	ft_printf("Zero padded       : [%05d]\n", 42);
	ft_printf("Left align        : [%-5d]\n", 42);
	ft_printf("Precision         : [%.4d]\n", 42);
	ft_printf("Width + prec      : [%8.4d]\n", 42);
	ft_printf("Int max           : [%d]\n", INT_MAX);
	ft_printf("Int min           : [%d]\n", INT_MIN);
	ft_printf("Zero + .0         : [%.0d]\n", 0);
	ft_printf("Zero + width .0   : [%5.0d]\n", 0);

	printf("\n===== SPECIFIER: %%u =====\n");
	ft_printf("Unsigned          : [%u]\n", 123456);
	ft_printf("Zero padded       : [%08u]\n", 123456);
	ft_printf("Precision         : [%.5u]\n", 123);
	ft_printf("Width + prec      : [%10.5u]\n", 123);
	ft_printf("Zero with .0      : [%.0u]\n", 0);

	printf("\n===== SPECIFIER: %%x / %%X =====\n");
	ft_printf("Hex lower         : [%x]\n", 255);
	ft_printf("Hex upper         : [%X]\n", 255);
	ft_printf("With # lower      : [%#x]\n", 255);
	ft_printf("With # upper      : [%#X]\n", 255);
	ft_printf("Zero padded       : [%08x]\n", 255);
	ft_printf("Precision         : [%.4x]\n", 255);
	ft_printf("Width + prec      : [%10.4x]\n", 255);
	ft_printf("Zero hex          : [%x]\n", 0);
	ft_printf("Zero with .0      : [%.0x]\n", 0);
	ft_printf("Zero with #       : [%#x]\n", 0);

	printf("\n===== SPECIFIER: %% =====\n");
	ft_printf("Percent literal   : [%%]\n");
	ft_printf("Width + %%         : [%5%]\n");
	ft_printf("Left align %%      : [%-5%]\n");

	printf("\n===== MODIFICATEURS DE LENGTH =====\n");

	short s = -32768;
	signed char sc = -128;
	long l = 2147483648;
	long long ll = 9223372036854775807LL;
	unsigned short us = 65535;
	unsigned char uc = 255;
	unsigned long ul = 4294967295UL;
	unsigned long long ull = 18446744073709551615ULL;

	ft_printf("%%hd  : [%hd]\n", s);
	ft_printf("%%hhd : [%hhd]\n", sc);
	ft_printf("%%ld  : [%ld]\n", l);
	ft_printf("%%lld : [%lld]\n", ll);

	ft_printf("%%hu  : [%hu]\n", us);
	ft_printf("%%hhu : [%hhu]\n", uc);
	ft_printf("%%lu  : [%lu]\n", ul);
	ft_printf("%%llu : [%llu]\n", ull);

	ft_printf("%%lx  : [%lx]\n", ul);
	ft_printf("%%llx : [%llx]\n", ull);
	ft_printf("%%lX  : [%lX]\n", ul);
	ft_printf("%%llX : [%llX]\n", ull);

	return (0);
}

