#include "shell_head.h"

/**
 * main - Entry point
 * @argc: is the argument count
 * @env: is an array of strings
 * Return: Always 0 Success
 */
int main(int argc, char **env)
{
	int status, n; 
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
			free(buffer);
			break;
		}
		n = 0;
		en_token = strtok(buffer, delim); 
		while (en_token && n < 256)
		{
			arg[n] = en_token;
			n++;
			en_token = strtok(NULL, delim);
		}
		arg[n] = NULL;
		en_fork(arg, env, &status);
		
	free(buffer);
	}

	return (0);
}
