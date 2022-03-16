/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 00:57:20 by azane             #+#    #+#             */
/*   Updated: 2022/01/09 00:57:29 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_string(char *s)
{
	unsigned int	i;
	char			c;

	i = 0;
	if (s == NULL)
		return (print_string("(null)"));
	while (*s)
	{
		c = *s++;
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int	print_number(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (print_string("-2147483648"));
	if (n < 0)
	{
		i += print_char('-');
		i += print_number(-n);
	}
	else if (n >= 10)
	{
		i += print_number(n / 10);
		i += print_char(n % 10 + '0');
	}
	else
		i += print_char(n + '0');
	return (i);
}

int	print_unsigned_number(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += print_number(n / 10);
		i += print_char(n % 10 + '0');
	}
	else
		i += print_char(n + '0');
	return (i);
}
