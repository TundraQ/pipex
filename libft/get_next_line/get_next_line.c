/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 21:02:34 by azane             #+#    #+#             */
/*   Updated: 2022/01/05 03:09:34 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_after(char *buf)
{
	char	*str;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!buf)
		return (NULL);
	while (buf[k] != '\n' && buf[k])
		k++;
	if (!buf[k])
	{
		free(buf);
		return (NULL);
	}
	k++;
	str = (char *)malloc(sizeof(char) * (gnl_strlen(buf) - k + 1));
	if (!str)
		return (NULL);
	while (buf[k])
		str[i++] = buf[k++];
	free(buf);
	str[i] = '\0';
	return (str);
}

char	*get_before(const char *buf)
{
	char	*str;
	int		i;

	i = 0;
	if (!buf)
		return (NULL);
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		str[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

int	end_line(const char *buf)
{
	if (!buf)
		return (0);
	while (*buf)
	{
		if (*buf == '\n')
			return (1);
		buf++;
	}
	return (0);
}

char	*gnl(int fd, char *buf, char *save_line)
{
	int	flag;

	flag = 1;
	while (flag != 0 && !end_line(save_line))
	{
		flag = read(fd, buf, BUFFER_SIZE);
		if (flag < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[flag] = '\0';
		if (flag > 0)
			save_line = gnl_strjoin(save_line, buf);
	}
	free(buf);
	return (save_line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*result;
	static char	*save_line[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	save_line[fd] = gnl(fd, buf, save_line[fd]);
	if (!save_line[fd])
		return (NULL);
	result = get_before(save_line[fd]);
	save_line[fd] = get_after(save_line[fd]);
	if (!result || result[0] == '\0')
	{
		if (result)
			free(result);
		return (NULL);
	}
	return (result);
}
