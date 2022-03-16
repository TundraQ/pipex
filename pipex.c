#include "pipex.h"

void	ft_close(int fd)
{
	if (fd< -1)
		close(fd);
}
int	main(int argc, char **argv)
{
	int	fifo[2][2];
	int	cur_pipe;
	int	file_in;
	int	file_out;
	int	i;

	file_in = open(argv[1], O_RDWR);
	file_out = open(argv[argc - 1], O_RDWR);
	if (!file_in || !file_out)
		ft_fatal("open");
	fifo[0][0] = -1;
	fifo[0][1] = -1;
	fifo[1][0] = -1;
	fifo[1][1] = -1;
	cur_pipe = 0;
	i = 2;
	while  (i < argc - 1)
	{
		if (pipe(fifo[cur_pipe]))
			ft_fatal("pipe");
		else
		{
			if (fork() == -1)
				ft_fatal("fork");
			if (i > 1)
			{
				dup2(fifo[1-cur_pipe][0], file_in);
				ft_close(fifo[1-cur_pipe][0]);
			}
			if (i < argc - 2)
			{
				dup2(fifo[cur_pipe][1], file_out);
				ft_close(fifo[cur_pipe][0]);
				ft_close(fifo[cur_pipe][1]);
			}
			if ((execlp("/bin/sh", "sh", "-c", argv[i]), 0) == -1) //!
				ft_fatal("execl");
		}
		ft_close(fifo[1 - cur_pipe][0]);
		ft_close(fifo[cur_pipe][1]);
		cur_pipe = 1 - cur_pipe;
		i++;
	}
	ft_close(fifo[1 - cur_pipe][0]);
	while (waitpid(-1, 0, 0));
	return (0);
}
