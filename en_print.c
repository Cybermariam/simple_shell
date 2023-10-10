#include "shell_head.h"

/**
 * en_print - function that print anything
 * @string: string to print
 * @desc: description
 */
void en_print(char *string, int desc)
{
	int n;

	for (n = 0; string[n]; n++)
		write(desc, &string[n], 1);
}
