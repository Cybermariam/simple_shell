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
 * en_printStr - function that print a string
 * @my_str: the string to print
 * Return: the string count
 */
int en_printStr(char *my_str)
{
	int m;
	int counter;

	counter = 0;
	m = 0;
	while (my_str[m] != '\0')
	{
		_putchar(my_str[m]);
		counter++;
		m++;
	}
	return (counter);
}
