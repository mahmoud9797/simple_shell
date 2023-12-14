#include "unix.h"
/**
 *takeinput - to read user input
 *Return: line which hold the user input
 */
char *takeinput()
{
	size_t bufsize = 1024;
	int cmd = 0;
	char *line = NULL;

	line = malloc(bufsize * sizeof(char));
	if (line == NULL)
	{
		perror("memory error");
		return (NULL);
	}
	cmd = getline(&line, &bufsize, stdin);
	if (cmd == -1)
	{
		if (feof(stdin) || isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("error during reading");
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
