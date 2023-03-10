#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	write_error(char *str, char *argv)
{
	while (*str)
		write(2, str++, 1);
	while (argv && *argv)
		write(2, argv++, 1);
	write(2, "\n", 1);
	return (1);
}

int	ft_exe(char **argv, int i, int temp_fd, char **envp)
{
	dup2(temp_fd, 0);
	close(temp_fd);
	argv[i]=NULL;
	execve(argv[0], argv, envp);
	return(write_error("error: cannot execute ", argv[0]));
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	int i = 0;
	int temp_fd = dup(0);
	int fd[2];
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while(argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (strcmp("cd", argv[0]) == 0)
		{
			if(i != 2)
				write_error("error: cd: bad arguments", NULL);
			else if (chdir(argv[1]) == -1)
				write_error("error: cd: cannot change directory to ", argv[1]);
		}
		else if (i != 0 && (argv[i] == NULL || strcmp(";", argv[i]) == 0))
		{
			if(!fork())
			{
				if(ft_exe(argv, i, temp_fd, envp))
					return (1);
			}
			else
			{
				close(temp_fd);
				waitpid(-1, NULL, WUNTRACED);
				temp_fd = dup(0);
			}
		}
		else if (i != 0 && strcmp("|", argv[i]) == 0)
		{
			pipe(fd);
			if(!fork())
			{
				dup2(fd[1], 1);
				close(fd[0]);
				if (ft_exe(argv, i, temp_fd, envp))
					return (1);
			}
			else
			{
				close(temp_fd);
				close(fd[1]);
				waitpid(-1, NULL, WUNTRACED);
				temp_fd = fd[0];
			}
		}
	}
	close(temp_fd);
	return (1);
}