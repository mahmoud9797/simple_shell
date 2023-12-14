#include "unix.h"
/**
 * _strcat - to concatenate to strings
 *@d: destination string
 *@s: source string
 *Return: destination string
 */
char *_strcat(char *d, char *s)
{
	int i = 0;
	int j = 0;

	while (d[i])
	{
		i++;
	}
	while (s[j])
	{
		d[i + j] = s[j];
		j++;
	}
	d[i + j] = '\0';
	return (d);
}
/**
 *_strdup - funtion to duplicate string
 *@s: is string we want to duplicate it
 *Return: d is the duplicated string
 */
char *_strdup(char *s)
{
	char *d;
	int i = 0;

	d = (char *)malloc((_strlen(s) + 1) * sizeof(char));
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
