#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * Filename - read_textfile
 *
 * Description - function that reads from a file and prints to std output
 *
 * Return: the number of chars printed or 0 if error
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t read_chars, write_chars;
	char *buffer;

	buffer = malloc(letters);
	if (!buffer)
		return (0);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	read_chars = read(fd, buffer, letters);

	close(fd);

	if (read_chars == -1)
		return (0);

	write_chars = write(STDOUT_FILENO, buffer, read_chars);

	if (write_chars == -1)
		return (0);

	free(buffer);

	return (write_chars);
}
