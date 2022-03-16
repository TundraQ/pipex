/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 21:06:43 by azane             #+#    #+#             */
/*   Updated: 2021/12/24 21:07:06 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char	*get_next_line(int fd);
int		end_line(const char *buf);
char	*get_before(const char *buf);
char	*get_after(char *buf);
size_t	gnl_strlen(const char *s);
char	*gnl_strjoin(char *s1, char *s2);
void	gnl_strlcpy(char *dst, const char *src);
void	gnl_strlcat(char *dst, const char *src);

#endif
