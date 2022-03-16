/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:09:33 by azane             #+#    #+#             */
/*   Updated: 2021/11/13 20:49:57 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	get_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != c && *s != '\0')
			count++;
		while (*s != '\0' && *s != c)
			s++;
	}
	return (count);
}

char	*str_add(char const *s, char c)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	while (*s != '\0' && *s != c)
	{
		str[j] = *s;
		s++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

void	*free_split(char **split, size_t i)
{
	while (i > 0)
		free(split[i--]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	split = (char **)malloc(sizeof(char *) * (get_count(s, c) + 1));
	if (!split)
		return (NULL);
	split[get_count(s, c)] = NULL;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s == '\0')
			break ;
		split[i] = str_add(s, c);
		if (!split[i])
			return (free_split(split, i));
		i++;
		while (*s != '\0' && *s != c)
			s++;
	}
	return (split);
}
