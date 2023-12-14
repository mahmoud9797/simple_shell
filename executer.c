#include "unix.h"
/**
 *execute_command - function to excute shell program
 *@command: is shell command
 *@args: array of tokenized input
 *Return: 0 in success
 */
int execute_command(char *command, char *args[])
{
	char *full_path;
	pid_t pid;
	int status;

	full_path = get_path(command);
	pid = fork();
	if (pid == -1)
	{
		return (-1);
	}
	else if (pid == 0)
	{
		execve(full_path, args, environ);
		exit(127);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			exit(WEXITSTATUS(status));
		}
	}
	free(full_path);
	return (0);
}
