#include "shell_head.h"

/**
 * en_fork -creates a child process
 * @str: a pointer to an argument vector
 * @env: a pointer to the environment variables
 * @status: The integer value of the return status
 */
void en_fork(char **str, char **env, int *status)
{
	char *path;
	pid_t en_pid;
	int en_stat, i;

	en_pid = fork();
	if (en_pid == -1)
	{
		free(str);
		perror("Fork Error!!!");
		exit(EXIT_FAILURE);
	}
	path = get_location(str[0]);
	if (path == NULL)
	{
		if (en_builtIn(str) != 0)
			return;
		else
			en_printStr("command not found\n");
		return;
	}
	if (en_pid == 0)
	{
		execve(path, str, env);
		free(str);
		free(path);
		exit(EXIT_FAILURE);
	}
	wait(&en_stat);
	if (en_stat != 0)
		*status = 2;
	else
		*status = 0;
	i = 0;
	for (; str[i]; i++)
	{
		en_printStr(str[i]);
		_putchar('\n');
	}
	free(path);
	free(str);
}
