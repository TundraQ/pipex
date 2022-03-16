/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:27:39 by azane             #+#    #+#             */
/*   Updated: 2022/01/09 00:43:11 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_up_hex(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += print_up_hex(n / 16);
		if (n % 16 < 10)
			i += print_char(n % 16 + '0');
		else
			i += print_char('A' + ((n % 16) - 10));
	}
	else
	{
		if (n % 16 < 10)
			i += print_char((n % 16) + '0');
		else
			i += print_char('A' + ((n % 16) - 10));
	}
	return (i);
}

int	print_down_hex(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += print_down_hex(n / 16);
		if (n % 16 < 10)
			i += print_char(n % 16 + '0');
		else
			i += print_char('a' + ((n % 16) - 10));
	}
	else
	{
		if (n % 16 < 10)
			i += print_char((n % 16) + '0');
		else
			i += print_char('a' + ((n % 16) - 10));
	}
	return (i);
}

int	print_pointer(unsigned long long n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += print_pointer(n / 16);
		if (n % 16 < 10)
			i += print_char(n % 16 + '0');
		else
			i += print_char('a' + ((n % 16) - 10));
	}
	else
	{
		if (n % 16 < 10)
			i += print_char((n % 16) + '0');
		else
			i += print_char('a' + ((n % 16) - 10));
	}
	return (i);
}

int	ft_type(const char c, va_list ap)
{
	if (c == 'c')
		return (print_char(va_arg(ap, int)));
	if (c == 's')
		return (print_string(va_arg(ap, char *)));
	if (c == 'p')
	{
		print_string("0x");
		return (print_pointer(va_arg(ap, unsigned long long)) + 2);
	}
	if (c == 'd' || c == 'i')
		return (print_number(va_arg(ap, int)));
	if (c == 'u')
		return (print_unsigned_number(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (print_down_hex(va_arg(ap, unsigned int)));
	if (c == 'X')
		return (print_up_hex(va_arg(ap, unsigned int)));
	if (c == '%')
		return (print_char('%'));
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
		{
			print_char(*fmt++);
			count++;
			continue ;
		}
		if (*++fmt)
			count += ft_type(*fmt, ap);
		fmt++;
	}
	va_end(ap);
	return (count);
}
