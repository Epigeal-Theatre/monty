#include "monty.h"
/**
 * _strcmp - this func  compares two strings
 *
 * @s1: placeholder for type str compared
 *
 * @s2: placeholder for type str compared
 *
 * Return: return 0 if s1 and s2 are equals
 *         or another value if they arent
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);

	if (s1[i] < s2[i])
		return (-1);

	return (0);
}

/**
 * _sch - this func will search if a char is inside a string
 *
 * @s: placeholder for string to review
 *
 * @c: placeholder for char to find
 *
 * Return: return 1 upon  success or otherwise 0
 */
int _sch(char *s, char c)
{
	int cont = 0;

	while (s[cont] != '\0')
	{
		if (s[cont] == c)
		{
			break;
		}
		cont++;
	}

	if (s[cont] == c)
		return (1);

	else
		return (0);
}

/**
 * _strtoky - this func tokenizes strings using delimiters
 *
 * @s: placeholder for string to cut
 *
 * @d: placeholder for delimiters
 *
 * Return: first section of string
 */
char *_strtoky(char *s, char *d)
{
	static char *ultimo;
	int i = 0, j = 0;

	if (!s)
		s = ultimo;

	while (s[i] != '\0')
	{
		if (_sch(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 0)
			i++;
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 1)
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			ultimo++;
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
