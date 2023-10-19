#include "shell_head.h"

/**
 * main - Entry point
 * @argc: is the argument counti
 * @env: is an array of strings
 * Return: Always 0 Success
 */
int main(int argc, char **env)
{
	int status, m, n, value;
	ssize_t numOfChar;
	char *prompt = "(my_shell)$ ", *buffer = NULL, *path;
	char *arg[128], *delim = " \n";
	pid_t en_pid;
	size_t size = 0;
	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			en_printStr(prompt);
		numOfChar = getline(&buffer, &size, stdin);
		if (numOfChar == -1)
		{
			free(buffer);
			exit(0);
		}
		m = 0;
		while (buffer[m])
		{
			if (buffer[m] == '\n')
				buffer[m] = 0;
			m++;
		}
		n = 0;
		arg[n] = strtok(buffer, delim);
		while (arg[n])
		{
			arg[++n] = strtok(NULL, delim);
		}
		arg[n] = NULL;
		path = get_location(arg[0]);
		if (path == NULL)
		{
			if (en_builtIn(arg) != 0)
				continue;
			else
				en_printStr("command not found\n");
			continue;
		}
		en_pid = fork();
		if (en_pid < 0)
		{
			en_printStr("Fork Failure");
			free(buffer);
			exit(0);
		}
		else if (en_pid == 0)
		{
			value = execve(path, arg, env);
			if (value == -1)
				en_printStr("command does not exist\n");
		}
		else
			wait(&status);
	}
		free(buffer);
		free(path);
	return (0);
}
