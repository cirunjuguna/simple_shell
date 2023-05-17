#include "main.h"

/**
 * _eputs - Prints a string to the standard error output
 * @str: Pointer to the string to be printed
 *
 * Description:
 * The _eputs function is used to print a string to the standard error output.
 * It takes a pointer to the string to be printed as a parameter.
 *
 * Return: None
 */

void _eputs(char *str)
{
	int b = 0;

	if (!str)
		return;
	while (str[b] != '\0')
	{
		_eputchar(str[b]);
		b++;
	}
}

/**
 * _eputchar - Writes a character to the standard error
 * @c: The character to be written
 *
 * Return: On success, the character written. On failure, -1.
 */

int _eputchar(char c)
{
	static int b;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || b >= WRITE_BUF_SIZE)
	{
		write(2, buf, b);
		b = 0;
	}
	if (c != BUF_FLUSH)
		buf[b++] = c;
	return (1);
}

/**
 * _putfd - Writes a character to a file descriptor
 * @c: The character to be written
 * @fd: The file descriptor to write to
 *
 * Return: On success, the number of bytes written. On error, -1 is returned.
 */

int _putfd(char c, int fd)
{
	static int b;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || b >= WRITE_BUF_SIZE)
	{
		write(fd, buf, b);
		b = 0;
	}
	if (c != BUF_FLUSH)
		buf[b++] = c;
	return (1);
}


/**
 * _putsfd - Writes a string to a file descriptor
 * @str: Pointer to the string to be written
 * @fd: File descriptor to write the string to
 *
 * Return: Number of characters written
 */
int _putsfd(char *str, int fd)
{
	int b = 0;

	if (!str)
		return (0);
	while (*str)
	{
		b += _putfd(*str++, fd);
	}
	return (b);
}
