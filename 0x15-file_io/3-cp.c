#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * read_error - function that exits the program
 * @argv: argument
 * Return: void
 */

void read_error(char *argv)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv);
	exit(98);
}
/**
 * write_error - function that exits the program
 * @argv: argument
 * Return: void
 */

void write_error(char *argv)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv);
	exit(99);
}
/**
 * close_error - function that exits the program
 * @fd: file descriptor
 * Return: void
 */

void close_error(int fd)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
}

/**
 * main - program that copies a file into a new one
 * @argc: number of arguments passed to the program
 * @argv: strings containing the names of the two files
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	int fd_from, fd_to, read_char = 1, write_char = 1, close_from, close_to;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from < 0)
		read_error(argv[1]);

	fd_to = open(argv[2], O_CREAT | O_WRONLY, 0664);
	if (fd_to < 0)
		write_error(argv[2]);

	while (read_char > 0)
	{
		read_char = read(fd_from, buffer, 1024);
		if (read_char < 0)
			read_error(argv[1]);
		if (read_char)
			write_char = write(fd_to, buffer, read_char);
		if (write_char < 0)
			write_error(argv[2]);
	}
	close_from = close(fd_from);

	if (close_from != 0)
		close_error(fd_from);

	close_to = close(fd_to);

	if (close_to != 0)
		close_error(fd_to);
	return (0);
}
