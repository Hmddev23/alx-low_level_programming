#include "main.h"

/**
  * print_error - Print an error message to the standard error.
  *
  * @message: The error message format.
  * @file: The file name or descriptor related to the error.
  *
  * Return: Nothing.
  */

void print_error(const char *message, const char *file)
{
	dprintf(STDERR_FILENO, message, file);
	exit(98);
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
	const char *file_from = argv[1];
	const char *file_to = argv[2];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}
	int fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		print_error("Error: Can't read from file %s\n", file_from);
	int fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd_to == -1)
		print_error("Error: Can't write to %s\n", file_to);
	char buffer[1024];
	ssize_t bytes_read;
	while ((bytes_read = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		ssize_t bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			print_error("Error: Can't write to %s\n", file_to);
		}
	}
	if (bytes_read == -1)
		print_error("Error: Can't read from file %s\n", file_from);

	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", errno);
		exit(100);
	}
	return (0);
}
