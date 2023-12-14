#include "unix.h"
/**
 *_getenv - srearchs environment variables
 *@var_name: is the target environment var we need it
 *Return: a pointer to string of the target var
 */
char *_getenv(char *var_name)
{
	int i = 0;
	char *envo;
	int len = _strlen(var_name);
	char marker = '=';

	while (environ[i] != NULL)
	{
		envo = _strchr(environ[i], marker);
		if (envo != NULL && strncmp(environ[i], var_name, len) == 0)
		{
			envo = envo + 1;
			return (envo);
		}
		i++;
	}
	return (NULL);
}
