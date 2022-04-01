/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:42:47 by azane             #+#    #+#             */
/*   Updated: 2022/03/29 23:48:39 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

typedef struct s_norm
{
	int		fifo[2][2];
	int		cur_pipe;
	int		file_in;
	int		file_out;
	int		i;
	int		pid;
	char	**tmp;
	char	*line;
	int		k;
	int		here_doc;
}	t_norm;

int	ft_here_doc(t_norm *norm, char **argv)
{
	int	result;

	result = 0;
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
	{
		result = 2;
		norm->file_in = open("here_doc", O_RDWR | O_CREAT, 0777);
		while (1)
		{
			norm->line = get_next_line(0);
			if (!ft_strncmp(norm->line, argv[2], ft_strlen(argv[2]))) 
			{
				free(norm->line);
				break ;
			}
			write(norm->file_in, norm->line, ft_strlen(norm->line));
			free(norm->line);
		}
		close(norm->file_in);
	}
	return (result);
}

void	ft_two(t_norm *norm, int argc, char **argv, char *env[])
{
	if (norm->i == 2)
		dup2(norm->file_in, 0);
	if (norm->i > 2)
	{
		dup2(norm->fifo[1 - norm->cur_pipe][0], 0);
		close(norm->fifo[1 - norm->cur_pipe][0]);
	}
	if (norm->i < argc - 2)
	{
		dup2(norm->fifo[norm->cur_pipe][1], 1);
		close(norm->fifo[norm->cur_pipe][0]);
		close(norm->fifo[norm->cur_pipe][1]);
	}
	if (norm->i + norm->here_doc == argc - 2)
		dup2(norm->file_out, 1);
	norm->tmp = (char **) ft_ec_malloc(3 * sizeof(char *));
	norm->tmp[0] = ft_strdup("./pipex");
	norm->tmp[1] = ft_strdup("-c");
	norm->tmp[2] = ft_strdup(argv[norm->i + norm->here_doc]);
	if (execve("/bin/sh", norm->tmp, env) == -1)
		ft_fatal("execve");
	norm->k = 0;
	while (norm->k != 3)
		free(norm->tmp[norm->k++]);
	free(norm->tmp);
}

void	ft_one(t_norm *norm, int argc, char **argv, char *env[])
{
	if (pipe(norm->fifo[norm->cur_pipe]))
		ft_fatal("pipe");
	norm->pid = fork();
	if (norm->pid == -1)
		ft_fatal("fork");
	if (norm->pid == 0)
		ft_two(norm, argc, argv, env);
	close(norm->fifo[1 - norm->cur_pipe][0]);
	close(norm->fifo[norm->cur_pipe][1]);
	norm->cur_pipe = 1 - norm->cur_pipe;
	norm->i++;
}


int	main(int argc, char **argv, char *env[])
{
	t_norm	norm;

	if (argc < 5)
		ft_fatal("wrong input");
	norm.i = 2;
	norm.here_doc = ft_here_doc(&norm, argv);
	if (!norm.here_doc)
		norm.file_in = open(argv[1], O_RDWR, 0777);
	norm.file_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (norm.file_in == -1 || norm.file_out == -1)
		ft_fatal("open");
	norm.fifo[0][0] = -1;
	norm.fifo[0][1] = -1;
	norm.fifo[1][0] = -1;
	norm.fifo[1][1] = -1;
	norm.cur_pipe = 0;
	while (norm.i + norm.here_doc < argc - 1)
		ft_one(&norm, argc, argv, env);
	close(norm.fifo[1 - norm.cur_pipe][0]);
	norm.i = -1;
	while (++norm.i < argc - 3 - norm.here_doc)
		wait(0);
	return (0);
}
