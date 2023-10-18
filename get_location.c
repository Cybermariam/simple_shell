#include "shell_head.h"

/**
 * en_location - search for an executable file within a list of directories
 * @pth: string that contain a list of directories
 * @argv: string that represent the name of the executable files
 * Return: the path if successful otherwise NULL
 */
char *en_location(char *pth, char *argv)
{
	char *path_copy, *path_token, *en_filePath;
	char *delim = ":";

	path_copy = strdup(pth);
	path_token = strtok(path_copy, delim);
	en_filePath = malloc(strlen(argv) + strlen(path_token) + 2);
	while (path_token == NULL)
	{
		strcpy(en_filePath, path_token);
		strcat(en_filePath, "/");
		strcat(en_filePath, "argv");
		strcat(en_filePath, "\0");

		if (access(en_filePath, X_OK) == 0)
		{
			free(path_copy);
			return (en_filePath);
		}
		path_token = strtok(NULL, delim);
	}
	free(en_filePath);
	free(path_copy);

	return (NULL);
}

/**
 * get_location - func that is used to obtain the loc. of an exec in the path
 * @argv: specify the name of the executable
 * Return: the path otherwise NULL
 */
char *get_location(char *argv)
{
	char *en_path;

	en_path = getenv("PATH");
	if (en_path)
	{
		en_path = en_location(en_path, argv);
		return (en_path);
	}
	return (NULL);
}
