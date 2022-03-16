/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:29:21 by azane             #+#    #+#             */
/*   Updated: 2021/11/12 14:29:34 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	*ret;

	p = (char *)s;
	ret = NULL;
	while (*p)
	{
		if (*p == (char)c)
			ret = p;
		p = p + 1;
	}
	if (c == '\0')
		return (p);
	return (ret);
}
