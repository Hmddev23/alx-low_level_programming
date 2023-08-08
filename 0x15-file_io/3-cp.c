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
  * open_source_file - Open the source file for reading.
  *
  * @file_from: The name of the source file.
  *
  * Return: The file descriptor of the opened source file.
  */

int open_source_file(const char *file_from)
{
	int fd_from = open(file_from, O_RDONLY);

	if (fd_from == -1)
	{
		print_error("Error: Can't read from file %s\n", file_from);
	}
	return (fd_from);
}

/**
  * create_dest_file - Create or truncate the destination file for writing.
  *
  * @file_to: The name of the destination file.
  *
  * Return: The file descriptor of the created/truncated destination file.
  */

int create_dest_file(const char *file_to)
{
	int fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC,
	        S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

	if (fd_to == -1)
	{
		print_error("Error: Can't write to %s\n", file_to);
	}

	return (fd_to);
}

/**
  * copy_file_content - Copy content from source file to destination file.
  *
  * @fd_from: The file descriptor of the source file.
  * @fd_to: The file descriptor of the destination file.
  *
  * Return: Nothing.
  */

void copy_file_content(int fd_from, int fd_to)
{
	char buffer[1024];
	ssize_t bytes_read;

	while ((bytes_read = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		ssize_t bytes_written = write(fd_to, buffer, bytes_read);

		if (bytes_written == -1)
		{
			print_error("Error: Can't write to destination file\n", "");
		}
	}

	if (bytes_read == -1)
	{
		print_error("Error: Can't read from source file\n", "");
	}
}

/**
  * close_files - Close file descriptors.
  *
  * @fd_from: The file descriptor of the source file.
  * @fd_to: The file descriptor of the destination file.
  *
  * Return: Nothing.
  */

void close_files(int fd_from, int fd_to)
{
	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptors\n");
		exit(100);
	}
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

	int fd_from = open_source_file(file_from);
	int fd_to = create_dest_file(file_to);

	copy_file_content(fd_from, fd_to);

	close_files(fd_from, fd_to);

	return (0);
}

