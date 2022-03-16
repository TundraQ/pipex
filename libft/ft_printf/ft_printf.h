/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:04:31 by azane             #+#    #+#             */
/*   Updated: 2022/01/08 23:25:15 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *fmt, ...);
int	ft_type(const char c, va_list ap);
int	print_char(char c);
int	print_string(char *s);
int	print_number(int n);
int	print_unsigned_number(unsigned int n);
int	print_pointer(unsigned long long dig);
int	print_down_hex(unsigned int n);
int	print_up_hex(unsigned int n);

#endif
