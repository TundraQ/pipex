/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:39:10 by azane             #+#    #+#             */
/*   Updated: 2021/11/12 14:39:43 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s_len;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	s_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = (char *)malloc(s_len);
	if (p != NULL)
	{
		ft_strlcpy(p, s1, s_len);
		ft_strlcat(p, s2, s_len);
	}
	return (p);
}
