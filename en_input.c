#include "shell_head.h"

/**
 * en_input - function that read a line of input
 * @buff: where the input is stored
 * @size: the size of buff array
 */
void en_input(char *buff, size_t size)
{
	ssize_t num_input;

	num_input = getline(&buff, &size, stdin);
	if (num_input == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}
	buff[num_input - 1] = '\0';
}
