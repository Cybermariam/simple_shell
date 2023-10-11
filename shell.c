#include "shell_head.h"

/**
 * main - Entry point
 * Return: Always 0 Success
 */
int main(void)
{
	char en_cmd[128];

	while (1)
	{
		en_prompt();
		en_input(en_cmd, sizeof(en_cmd));
		en_execute(en_cmd);
	}
	return (0);
}
