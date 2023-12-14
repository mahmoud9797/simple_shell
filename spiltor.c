#include "unix.h"
/**
 *split_cmd - function to tokenize command
 *@cmd: it is linux command
 *Return: pointer array of tokens
 */
char **split_cmd(char *cmd)
{
	char **arr_tokens = NULL;
	char *str_cpy = NULL;
	char *token = NULL;
	int i;
	int c = 0;
	char *tok_d = " \n";

	str_cpy = _strdup(cmd);
	if (str_cpy == NULL)
	{
		return (NULL);
	}
	token = strtok(str_cpy, tok_d);
	while (token != NULL)
	{
		c++;
		token = strtok(NULL, tok_d);
	}
	arr_tokens = (char **)malloc((c + 1) * sizeof(char *));
	token = strtok(cmd, tok_d);
	for (i = 0; token != NULL; i++)
	{
		arr_tokens[i] = _strdup(token);
		token = strtok(NULL, tok_d);
	}
	arr_tokens[i] = NULL;
	free(str_cpy);
	return (arr_tokens);
}
