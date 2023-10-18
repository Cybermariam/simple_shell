#include "shell.h"
/**
* en_fork - creates a child process * @str: A pointer to an argument vector
* @env: A pointer to environment variables * @status: The integer value of the return status
* */
void en_fork(char **str, char **env, int *status){
pid_t myPid; int en_stat;
myPid = fork();

if (myPid == -1) {
  _free(str);  perror("Fork Error");
  exit(EXIT_FAILURE);}

if (myPid == 0)
{  execve(str[0], str, env);
  _free(str);  exit(EXIT_FAILURE);
}

wait(&en_stat);

if (en_stat != 0)  *status = 2;

else  *status = 0;
_free(str);
}
