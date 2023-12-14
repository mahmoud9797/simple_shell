#include "unix.h"
/**
 *get_path - function to get vaild path of unix command
 *@command: is linux command
 *Return: command in path
 */
char *get_path(char *command)
{
	char *envp = NULL, *token = NULL;
	char *full_path = NULL, *env_cpy = NULL;
	int len_command;
	char *path_d = ":";
	struct stat info;

	len_command = _strlen(command);
	envp = _getenv("PATH");
	if (envp != NULL)
	{
		env_cpy = _strdup(envp);
		token = strtok(env_cpy, path_d);
		while (token != NULL)
		{
			full_path = malloc(len_command + _strlen(token) + 2);
			path_append(full_path, token, command);
			if (stat(full_path, &info) == 0)
			{
				free(env_cpy);
				return (full_path);
			}
			else
			{
				free(full_path);
				token = strtok(NULL, path_d);
			}
		}
		free(env_cpy);
		if (stat(command, &info) == 0)
		{
			return (command);
		}
		else
		{
			return (NULL);
		}
	}
	return (NULL);
}
/**
 *path_append - function to append path with command
 *@full_path: it is a pointer to a full path
 *@dir: it is a program directory
 *@command: it is a linux command
 */
void path_append(char *full_path, char *dir, char *command)
{
	_strcpy(full_path, dir);
	_strcat(full_path, "/");
	_strcat(full_path, command);
	_strcat(full_path, "\0");
}
