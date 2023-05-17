#include "main.h"

/**
 * _myenv - Retrieves environment information.
 * @info: Pointer to the info_t struct containing relevant data.
 *
 * This function retrieves environment information using the given
 * info_t struct.
 * It performs the necessary operations to gather the required data and returns
 * the result.
 *
 * Return: An integer value representing the status of the operation.
 */

int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - Retrieves the value of an environment variable.
 * @info: Pointer to the info_t struct containing environment variables.
 * @name: Name of the environment variable to retrieve.
 *
 * Return: Pointer to the value of the environment
 * variable, or NULL if not found.
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Set environment variable.
 * @info: Pointer to the info_t struct containing necessary information.
 *
 * Description: This function sets an environment variable based on the
 *              provided information.
 *
 * Return: Always 0.
 */

int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Unsets an environment variable.
 * @info: Pointer to the info_t struct containing environment variables.
 *
 * Return: Always 0.
 */

int _myunsetenv(info_t *info)
{
	int m;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (m = 1; m <= info->argc; m++)
		_unsetenv(info, info->argv[m]);

	return (0);
}

/**
 * populate_env_list - Populates the environment list
 * @info: Pointer to the info_t struct
 *
 * This function populates the environment list in the info_t struct
 * with the environment variables from the current environment.
 * The info_t struct should be initialized before calling this function.
 *
 * Return: void
 */

int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t m;

	for (m = 0; environ[m]; m++)
		add_node_end(&node, environ[m], 0);
	info->env = node;
	return (0);
}
