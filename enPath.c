#include "main.h"
char *en_location(char *pth, char *argv)
{
        char *path_copy, *path_token, *en_filePath;        char *delim = ":", *buffr;
        path_copy = strdup(pth);
        path_token = strtok(path_copy, delim);
        en_filePath = malloc(strlen(argv) + strlen(path_token) + 2);        while(path_token != NULL)
        {                strcpy(en_filePath, path_token);
                strcat(en_filePath, "/");                strcat(en_filePath, argv);
                strcat(en_filePath, "\0");
                if (access(en_filePath, X_OK) == 0)                {
                        free(path_copy);                        return (en_filePath);
                }                path_token = strtok(NULL, delim);
        }        free(en_filePath);
        free(path_copy);        
        return (NULL);}
char *get_loca(char *argv)
{        char *en_path;
                en_path = getenv("PATH");
        if (en_path)        {
                en_path = location(en_path, arg);                return (en_path);
        }        return (NULL);
}
