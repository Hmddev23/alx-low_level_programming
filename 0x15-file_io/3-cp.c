#include "main.h"

char *createBuffer(char *file);
void closeFile(int fd);

/**
  * createBuffer - Allocate a buffer of 1024 bytes for file I/O.
  *
  * @file: The name of the file (for error messages).
  *
  * Return: A pointer to the allocated buffer.
  */

char *createBuffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
  * closeFile - Closes a file descriptor.
  *
  * @fd: The file descriptor to close.
  *
  * Return: Nothing.
  */

void closeFile(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
  * main - Copies the contents of one file to another.
  *
  * @argc: Argument counter.
  * @argv: Argument values.
  *
  * Return: 0 on success, non-zero on failure.
  */

int main(int argc, char *argv[])
{
	char *buffer;
	int from, to, r, w;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = createBuffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	while (r > 0)
	{
		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		r = read(from, buffer, 1024);
	}

	if (from == -1 || r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(98);
	}
	free(buffer);
	closeFile(from);
	closeFile(to);

	return (0);
}
