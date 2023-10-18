#include "shell.h"

/**
 * en_builtIn- used to 
 * @argv: a pointer to a character
 */

int en_builtIn(char **argv){
        if (strcmp(argv[0], "exit") == 0)
		{
                en_printStr("Exit Shell...\n");               
       		exit(0);
      		 } 
       	else if (strcmp(argv[0], "cd") == 0)
       			 {       
       				if (argv[1] == NULL)
               			chdir(getenv("HOME"));       
			       
			       	else
		                chdir(argv[1]);       
			 }
        return (0);
} 
