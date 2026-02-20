/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 02:24:36 by codex             #+#    #+#             */
/*   Updated: 2026/02/20 02:24:36 by codex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

static void	check_char_string(void)
{
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
	ft_printf("NULL string       : [%s]\n", (char *) NULL);
	ft_printf("NULL str width    : [%10s]\n", (char *) NULL);
	ft_printf("NULL str prec     : [%.3s]\n", (char *) NULL);
}

static void	check_ptr_and_numbers(void)
{
	int			x;
	long long	over_max;
	long long	under_min;

	x = 42;
	over_max = (long long)INT_MAX + 1LL;
	under_min = (long long)INT_MIN - 1LL;
	printf("\n===== SPECIFIER: %%p =====\n");
	ft_printf("Pointer address   : [%p]\n", &x);
	ft_printf("NULL pointer      : [%p]\n", NULL);
	printf("\n===== SPECIFIER: %%d / %%i =====\n");
	ft_printf("Int simple        : [%d]\n", 42);
	ft_printf("Negative int      : [%i]\n", -42);
	ft_printf("Int max           : [%d]\n", INT_MAX);
	ft_printf("Int min           : [%d]\n", INT_MIN);
	ft_printf("Cast > INT_MAX    : [%d]\n", (int)over_max);
	ft_printf("Cast < INT_MIN    : [%d]\n", (int)under_min);
}

static void	check_uint_hex_percent(void)
{
	printf("\n===== SPECIFIER: %%u =====\n");
	ft_printf("Unsigned          : [%u]\n", 123456);
	ft_printf("\n===== SPECIFIER: %%x / %%X =====\n");
	ft_printf("Hex lower         : [%x]\n", 255);
	ft_printf("Hex upper         : [%X]\n", 255);
	ft_printf("\n===== SPECIFIER: %% =====\n");
	ft_printf("Percent literal   : [%%]\n");
}

void	run_cheker(void)
{
	check_char_string();
	check_ptr_and_numbers();
	check_uint_hex_percent();
}
