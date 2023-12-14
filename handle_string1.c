#include "unix.h"
/**
 *_strchr - function used to search on the first occuerence of charchtr
 *@str: is the string will be searched
 *@c: is the charcteter to search for
 *Return: a pointer to the first char
 */
char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		str++;
	}
	return (NULL);
}
/**
 *_tolower - function to convert uppercase charchter if it found
 *@x: is the charcter will be converted
 *Return: the lowercase of the charcter
*/
char _tolower(char x)
{
	if (x >= 65 && x <= 90)
	{
		return (x + 97 - 65);
	}
	else
		return (x);
}

/**
 *_strlen - returns the length of a string
 *@s: the string will be calculated
 *Return: the length of string without null
*/
int _strlen(const char *s)
{
	int l = 0;

	while (*s != '\0')
	{
		l++;
		s++;
	}
	return (l);
}
