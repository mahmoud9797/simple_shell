#include "unix.h"
/**
 *_strcpy - function to copy string from d to s
 *@d: is the destenation string
 *@s: is the source
 *Return: d
 */
char *_strcpy(char *d, char *s)
{
	int i = 0;

	if (d == NULL)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

int _strncmp(char *s1, char *s2, int n)
{
	int difference = 0, index = 0;

	while ((s1[index] != '\0' && s2[index] != '\0') && index < n)
	{
		difference = s1[index] - s2[index];
		if (difference != 0)
			break;
		index++;
	}
	return (difference);
}
