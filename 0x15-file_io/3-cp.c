#include "main.h"

char *create_buffer(char *filename);
void close_file(int fd);

/**
  * create_buffer - Allocate a buffer of 1024 bytes for file I/O.
  *
  * @filename: The name of the file (for error messages).
  *
  * Return: A pointer to the allocated buffer.
  */

char *create_buffer(char *filename)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
		"Error: Can't allocate buffer for %s\n", filename);
		exit(99);
	}

	return (buffer);
}

/**
  * close_file - Closes a file descriptor.
  *
  * @fd: The file descriptor to close.
  *
  * Return: Nothing.
  */

void close_file(int fd)
{
	int result;

	result = close(fd);

	if (result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
  * main - Copies the contents of one file to another.
  *
  * @argc: The number of arguments.
  * @argv: An array containing the arguments.
  *
  * Return: 0 on success, non-zero on failure.
  */

int main(int argc, char *argv[])
{
	char *buffer;
	int source_fd, dest_fd, bytes_read, bytes_written;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp source_file dest_file\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	source_fd = open(argv[1], O_RDONLY);
	bytes_read = read(source_fd, buffer, 1024);
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	while (bytes_read > 0)
	{
		bytes_written = write(dest_fd, buffer, bytes_read);
		if (dest_fd == -1 || bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		bytes_read = read(source_fd, buffer, 1024);
	}

	if (source_fd == -1 || bytes_read == -1)
	{
		dprintf(STDERR_FILENO,
		"Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(98);
	}

	free(buffer);
	close_file(source_fd);
	close_file(dest_fd);

	return (0);
}
