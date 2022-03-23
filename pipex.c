/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:27:32 by azane             #+#    #+#             */
/*   Updated: 2022/03/23 20:14:18 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close(int fd)
{
	close(fd);
}

int	main(int argc, char **argv, char *env[])
{
	int		fifo[2][2];
	int		cur_pipe;
	int		file_in;
	int		file_out;
	int		i;
	int		pid;
	char	*tmp;

	file_in = open(argv[1], O_RDWR, 0777);
	file_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (file_in == -1 || file_out == -1)
		ft_fatal("open");
	fifo[0][0] = -1;
	fifo[0][1] = -1;
	fifo[1][0] = -1;
	fifo[1][1] = -1;
	cur_pipe = 0;
	i = 2;
	while (i < argc - 1)
	{
		if (pipe(fifo[cur_pipe]))
			ft_fatal("pipe");
		pid = fork();
		if (pid == -1)
			ft_fatal("fork");
		if (pid == 0)
		{
			if (i == 2)
				dup2(file_in, 0);
			if (i > 2)
			{
				dup2(fifo[1 - cur_pipe][0], 0);
				ft_close(fifo[1 - cur_pipe][0]);
			}
			if (i < argc - 2)
			{
				dup2(fifo[cur_pipe][1], 1);
				ft_close(fifo[cur_pipe][0]);
				ft_close(fifo[cur_pipe][1]);
			}
			if (i == argc - 2)
				dup2(file_out, 1);
			tmp[] = {"./pipex", "-c", argv[i]};
			if (execve("/bin/sh", tmp, env) == -1)
				ft_fatal("execl");
		}
		ft_close(fifo[1 - cur_pipe][0]);
		ft_close(fifo[cur_pipe][1]);
		cur_pipe = 1 - cur_pipe;
		i++;
	}
	ft_close(fifo[1 - cur_pipe][0]);
	i = -1;
	while (++i < argc - 3)
		wait(0);
	return (0);
}
