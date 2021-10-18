#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * Filename: read_textfile
 * Description - This file reads a text file and prints it to the POSIX standard output
 *
 * Return: Always 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int ID = 0;
	ssize_t WR = 0;
	ssize_t len = 0;
	char *buff = NULL;

	if (filename != NULL)
	{
		buff = malloc(letters);
		if (buff == NULL)
		{
			return (0);
		}

		ID = open(filename, 0_RDONLY, 0600);
		if (ID == -1)
		{
			free(buff);
			return (0);
		}
		len = read(ID, buff, letters);
		if (len == -1)
		{
			free(buff);
			return (0);
		}
		WR = write(STDOUT_FILENO, buff, len);
		if (WR == -1 || WR < len)
		{
			free(buff);
			return (0);
		}
		close(ID);
		free(buff);
		return (WR);
	}
	return (0);
}
