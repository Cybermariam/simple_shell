#include "shell_head.h"

/**
 * _putchar - print a character
 * @c: character to print
 * Return: the character
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * en_printStr - print a string
 * @my_str: the string to print
 * Return: the string count
 */
int en_printStr(char *my_str)
{
	int m;
	int counter = 0;

	for (m = 0; my_str[m]; m++)
		counter += _putchar(my_str[m]);
	return (counter);
}
