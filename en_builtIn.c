#include "shell_head.h"

/**
 * en_builtIn - Handles the builtin
 * @argv: an array of string
 * Return: Always 0 on Success
 */
int en_builtIn(char **argv)
{
	const char *en_home;

	if (strcmp(argv[0], "exit") == 0)
	{
		en_printStr("Exiting the shell...\n");
		exit(0);
	}
	else if (strcmp(argv[0], "cd") == 0)
	{
		if (argv[1] == NULL)
		{
			en_home = getenv("HOME");
			if (home)
				chdir(home);
		}
		else
		{
			if (chdir(argv[1]) != 0)
				perror("cd");
		}
		return (1);
	}
	return (0);
}
