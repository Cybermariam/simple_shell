#include "shell_head.h"

/**
 * main - Entry point
 * @argc: is the argument count
 * @env: is an array of strings
 * Return: Always 0 Success
 */
int main(int argc, char **env)
{
	int status = 0, n; 
	char *en_token;
	char *buffer = NULL;
	char *arg[256], *delim = " ";
	size_t size = 0;
	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			en_prompt();
		if (getline(&buffer, &size, stdin) == -1)
		{
			if (feof(stdin))
			{
				_putchar('\n');
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("getline");
				exit(EXIT_FAILURE);
			}
		}
		n = 0;
		en_token = strtok(buffer, delim); 
		while (en_token && n < 256)
		{
			arg[n++] = en_token;
			en_token = strtok(NULL, delim);
		}
		if (arg[0] == NULL)
		{
			free(buffer);
			continue;
		}
		en_fork(arg, env, &status);
		free(buffer);
	}
	return (0);
}
