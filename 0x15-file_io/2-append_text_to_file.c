#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * Filename - append_text_to_file
 *
 * Description - function that creates a file and appends a string
 *
 * Return: 1 on success or -1 if error
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, len;
	int write_chars;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd < 0)
		return (-1);

	if (text_content == NULL)
	{
		write_chars = write(fd, "hola", 0);
		close(fd);
		if (write_chars == -1)
			return (-1);
		else
			return (1);
	}

	for (len = 0; text_content[len]; len++)
		;

	write_chars = write(fd, text_content, len);

	if (write_chars != len)
		return (-1);

	close(fd);
	return (1);
}
