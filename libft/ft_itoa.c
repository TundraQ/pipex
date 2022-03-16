/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:40:38 by azane             #+#    #+#             */
/*   Updated: 2021/11/12 14:47:56 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reverse(char *s)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
	return ;
}

int	len(int n)
{
	int	l;

	l = 0;
	if (n <= 0)
		l++;
	while (n != 0)
	{
		l++;
		n = n / 10;
	}
	return (l);
}

char	*min(char *s)
{
	ft_strlcpy(s, "-2147483648", 12);
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		sign;

	sign = n;
	i = 0;
	s = (char *)malloc(sizeof(char) * (len(n) + 1));
	if (!s)
		return (NULL);
	if (n == -2147483648)
		return (min(s));
	if (sign < 0)
		n = -n;
	s[i++] = n % 10 + '0';
	n = n / 10;
	while (n > 0)
	{
		s[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	ft_reverse(s);
	return (s);
}
