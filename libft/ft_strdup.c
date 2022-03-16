/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:37:14 by azane             #+#    #+#             */
/*   Updated: 2021/11/12 14:38:17 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	s_len;

	s_len = ft_strlen(s) + 1;
	p = (char *)malloc(s_len);
	if (p != NULL)
		ft_strlcpy(p, s, s_len);
	return (p);
}
