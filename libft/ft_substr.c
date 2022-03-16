/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:38:29 by azane             #+#    #+#             */
/*   Updated: 2021/11/12 14:38:58 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	s_len;

	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	s_len = ft_strlen(s + start) + 1;
	if (len + 1 < s_len)
		s_len = len + 1;
	p = (char *)malloc(s_len);
	if (p != NULL)
		ft_strlcpy(p, s + start, s_len);
	return (p);
}
