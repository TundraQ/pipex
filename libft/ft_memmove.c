/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:52:08 by azane             #+#    #+#             */
/*   Updated: 2021/11/12 14:22:53 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dest;
	s = src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (d);
	if (s < d)
		while (++i <= n)
			d[n - i] = s[n - i];
	else
	{
		while (n > 0)
		{
			n--;
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}
