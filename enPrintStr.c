#include "shell.h"

/**
 * _putchar- prints a string
 * @c: character variable 
 */

int _putchar(char c){
        return(write(1, &c, 1));
}
int en_printStr(char *my_str)
{        int m = 0, counter = 0;
        for (m = 0; my_str[m]; m++)
        {                counter += _putchar(my_str[i]);
        }        return (counter);
}
