#include "main.h"

/**
  * print_error - Print an error message to the standard error.
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
  * open_files - Open the source and destination files.
  *
  * @source: The name of the source file.
  * @destination: The name of the destination file.
  *
  * Return: Destination file on success, -1 on failure.
  */

int open_files(const char *source, const char *destination)
{
	int fd_from = open(source, O_RDONLY);

	if (fd_from == -1)
	{
		print_error("Can't read from file");
		return (-1);
	}

	int fd_to = open(destination, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

	if (fd_to == -1)
	{
		print_error("Can't write to file");
		close(fd_from);
		return (-1);
	}

	return (fd_to);
}

/**
  * copy_file_contents - Copy content from one file to another.
  *
  * @fd_from: File descriptor of the source file.
  * @fd_to: File descriptor of the destination file.
  *
  * Return: 0 on success, -1 on failure.
  */

int copy_file_contents(int fd_from, int fd_to)
{
	ssize_t nread, nwritten;
	char buffer[BUFFER_SIZE];

	while ((nread = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		nwritten = write(fd_to, buffer, nread);

		if (nwritten == -1 || nwritten != nread)
		{
			print_error("Can't write to file");
			return (-1);
		}
	}

	if (nread == -1)
	{
		print_error("Can't read from file");
		return (-1);
	}

	return (0);
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
	int fd_from = open(argv[1], O_RDONLY);
	int fd_to = open_files(argv[1], argv[2]);

	if (argc != 3)
	{
		print_error("Usage: cp file_from file_to");
		return (97);
	}

	if (fd_from == -1)
		return (98);

	if (fd_to == -1)
	{
		close(fd_from);
		return (99);
	}

	if (copy_file_contents(fd_from, fd_to) == -1)
	{
		close(fd_from);
		close(fd_to);
		return (99);
	}

	close(fd_from);
	close(fd_to);

	return (0);
}
