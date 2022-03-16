/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:59:11 by azane             #+#    #+#             */
/*   Updated: 2021/11/11 19:29:42 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	ret;
	size_t	len_dst;

	i = 0;
	j = 0;
	len_dst = ft_strlen(dst);
	if (size > len_dst)
		ret = ft_strlen(src) + len_dst;
	else
		ret = ft_strlen(src) + size;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && ((len_dst++ + 1) < size))
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (ret);
}
