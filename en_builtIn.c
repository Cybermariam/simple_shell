#include "shell_head.h"

/**
 * en_builtIn - Handles the builtin
 * @argv: an array of string
 * Return: Always 0 on Success
 */
int en_builtIn(char **argv)
{
	if (strcmp(argv[0], "exit") == 0)
	{
		en_printStr("Exiting the shell...\n");
		exit(0);
	}
	else if (strcmp(argv[0], "cd") == 0)
	{
		if (argv[1] == NULL)
			chdir(getenv("HOME"));
		else
			chdir(argv[1]);
	}
	return (0);
}
