#include "unix.h"
char **split_cmd(char *cmd)
{
    char **arr_tokens = NULL;
    char *str_cpy = NULL;
    char *token = NULL;
    int i;
    int c = 0;
    char *tok_d = " \n";
    int j;

    str_cpy = _strdup(cmd);
    if (str_cpy == NULL)
    {
        return NULL;
    }

    token = strtok(str_cpy, tok_d);
    while (token != NULL)
    {
        c++;
        token = strtok(NULL, tok_d);
    }

    arr_tokens = (char **)malloc((c + 1) * sizeof(char *));
    if (arr_tokens == NULL)
    {
        free(str_cpy);
        return NULL;
    }

    token = strtok(cmd, tok_d);
    for (i = 0; token != NULL; i++)
    {
        arr_tokens[i] = _strdup(token);
        if (arr_tokens[i] == NULL)
        {
            for (j = 0; j < i; j++)
            {
                free(arr_tokens[j]);
            }
            free(arr_tokens);
            free(str_cpy);
            return NULL;
        }
        token = strtok(NULL, tok_d);
    }

    arr_tokens[i] = NULL;
    free(str_cpy);
    return arr_tokens;
}
