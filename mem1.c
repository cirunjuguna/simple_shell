#include "main.h"

/**
 * bfree - Frees memory allocated to a pointer and sets it to NULL
 * @ptr: Pointer to the pointer whose memory needs to be freed
 *
 * Return: 1 if memory is freed, otherwise 0
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
