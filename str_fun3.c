#include "main.h"

/**
 * strtow - splits a string into words using a delimiter
 * @str: the string to split
 * @d: the delimiter to use
 *
 * Return: a pointer to an array of strings (words)
 */
char **strtow(char *str, char *d)
{
	int b, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (b = 0; str[b] != '\0'; b++)
		if (!is_delim(str[b], d) && (is_delim(str[b + 1], d) || !str[b + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (b = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[b], d))
			b++;
		k = 0;
		while (!is_delim(str[b + k], d) && str[b + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[b++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * strtow2 - Splits a string into words, separated by a given delimiter.
 *
 * @str: the string to be split.
 * @d: the delimiter character.
 *
 * Return: a pointer to a newly allocated array of strings (words).
 */
char **strtow2(char *str, char d)
{
	int b, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (b = 0; str[b] != '\0'; b++)
		if ((str[b] != d && str[b + 1] == d) ||
		    (str[b] != d && !str[b + 1]) || str[b + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (b = 0, j = 0; j < numwords; j++)
	{
		while (str[b] == d && str[b] != d)
			b++;
		k = 0;
		while (str[b + k] != d && str[b + k] && str[b + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[b++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
