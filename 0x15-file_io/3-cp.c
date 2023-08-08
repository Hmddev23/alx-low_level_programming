#include "main.h"

/**
  * print_error - Prints an error message to the standard error.
  *
  * @msg: The error message to print.
  *
  * Return: Nothing.
  */

void print_error(const char *msg)
{
	dprintf(STDERR_FILENO, "Error: %s\n", msg);
}

/**
  * main - Copy the contents of one file to another.
  *
  * @argc: Argument counter.
  * @argv: Argument values.
  *
  * Return: 0 on successful execution.
  */

int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t nread, nwritten;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		print_error("Usage: cp file_from file_to");
		return (97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		print_error("Can't read from file");
		return (98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd_to == -1)
	{
		print_error("Can't write to file");
		close(fd_from);
		return (99);
	}

	while ((nread = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		nwritten = write(fd_to, buffer, nread);
		if (nwritten == -1 || nwritten != nread)
		{
			print_error("Can't write to file");
			close(fd_from);
			close(fd_to);
			return (99);
		}
	}

	if (nread == -1)
	{
		print_error("Can't read from file");
		close(fd_from);
		close(fd_to);
		return (98);
	}

	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		print_error("Can't close fd");
		return (100);
	}

	return (0);
}
