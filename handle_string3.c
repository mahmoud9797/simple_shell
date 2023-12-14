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
