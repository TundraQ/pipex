/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:47:05 by azane             #+#    #+#             */
/*   Updated: 2022/03/28 23:12:40 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
}	t_norm;

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
	if (norm->i == argc - 2)
		dup2(norm->file_out, 1);
	norm->tmp = (char **) ft_ec_malloc(3 * sizeof(char *));
	norm->tmp[0] = ft_strdup("./pipex");
	norm->tmp[1] = ft_strdup("-c");
	norm->tmp[2] = ft_strdup(argv[norm->i]);
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
}

int	main(int argc, char **argv, char *env[])
{
	t_norm	norm;

	if (argc != 5)
		ft_fatal("wrong input");
	norm.i = 2;
	norm.file_in = open(argv[1], O_RDWR, 0777);
	norm.file_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (norm.file_in == -1 || norm.file_out == -1)
		ft_fatal("open");
	norm.fifo[0][0] = -1;
	norm.fifo[0][1] = -1;
	norm.fifo[1][0] = -1;
	norm.fifo[1][1] = -1;
	norm.cur_pipe = 0;
	while (norm.i < argc - 1)
	{
		ft_one(&norm, argc, argv, env);
		norm.i++;
	}
	close(norm.fifo[1 - norm.cur_pipe][0]);
	norm.i = -1;
	while (++norm.i < argc - 3)
		wait(0);
	return (0);
}
