#ifndef SHELL_HEAD_H
#define SHELL_HEAD_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stddef.h>

int en_printStr(char *my_str);
int main(int argc, char **env);
void en_prompt(void);
void en_input(char *buff, size_t size);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
char *en_location(char *pth, char *argv);
char *get_location(char *argv);
int _putchar(char c);
int en_builtIn(char **argv);
void en_fork(char **str, char **env, int *status);

#endif /*SHELL_HEAD_H*/
