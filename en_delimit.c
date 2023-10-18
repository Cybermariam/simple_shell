#include "shell_head.h"

/**
 * en_delimit - looks to see if the character is delimeter
 * @check: character of checkpoint
 * @delimit: the delimited string to be checked
 */

int en_delimit(char *delimit, char check)
{
	while(*delimit)
	{
		if(*delimit++ == c)
			return 1;
		else
			return (0);
	}

}
