#ifndef SHELL_HEAD_H
#define SHELL_HEAD_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void en_print(char *string, int desc);
void en_prompt(void);
int main(int ac, char **av);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

#endif
