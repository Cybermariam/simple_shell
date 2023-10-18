#include "shell.h"

int main(int argc, char **env){
        char *prompt = "(shell)$ ", *buffer = NULL, *path;       
       	char *arg[128], *delim = " \n";
        size_t size = 0;       
       	ssize_t numOfChar;
        pid_t en_pid;        (void)argc;
        int status, m, n, value;
        while (1)
        {                if (isatty(STDIN_FILENO) == 1)
                        en_printStr(prompt);                numOfChar = getline(&buffer, &size, stdin);
                if (numOfChar == -1)
                {                        free(buffer);
                        exit(0);  }
                m = 0;
                while (buffer[m])                {
                        if (buffer[m] == '\n')                                buffer[m] = 0;
                        m++;                }
                n = 0;                arg[n] = strtok(buffer, delim);
                while (arg[n])                {
                        arg[++n] = strtok(NULL, delim);                }
                arg[n] = NULL;                
                path = get_loc(arg[0]);
                if (path == NULL)                {
                        if (en_builtIn(arg) != 0)                                continue;
                        else                                en_printStr("command not found\n");
                        continue;                }
                en_pid = fork();                if (en_pid < 0)
                {                        en_printStr("Fork Failure");
                        free(buffer);                        exit(0);
                }                else if (en_pid == 0)
                {                        value = execve(path, arg, env);
				if (value == -1)     en_printStr("command does notnot exist\n");
                }
                else
                        wait(&status);
        }
        free(buffer);
        free(path);

        return (0);

}
