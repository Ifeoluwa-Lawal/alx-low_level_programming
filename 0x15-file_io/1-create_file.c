#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * Filename - create_file
 *
 * Description - Function that creates a file
 *
 * Return: Always 0
 */

int create_file(const char *filename, char *text_content)
{
	int ID = 0, wr = 0, count = 0;

	if (filename == NULL)
	{
		return (-1);
	}
	if  (text_content != NULL)
	{
		for (count = 0; text_content[count] != '\0'; count++)
		{}
	}
	ID = open(filename, 0_CREAT | 0_TRUNC | 0_WRONLY, 0600);
	if (ID == -1)
	{
		return (-1);
	}
	wr = write(ID, text_content, count);
	if (wr == -1)
	{
		return (-1);
	}
	close(ID);
	return (1);
}
