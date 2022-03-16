/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:10:07 by azane             #+#    #+#             */
/*   Updated: 2022/03/12 18:07:34 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fatal(char *message)
{
	char	error_message[100];

	ft_strlcpy(error_message, "Error", 100);
	ft_strlcat(error_message, message, 100);
	ft_printf("%s\n", error_message);
	exit(0);
}
