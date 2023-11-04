#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int cp_file(char *src, char *dest);

/**
 * main - Entry point for the cp program.
 * @argc: The number of command-line arguments (should be 3).
 * @argv: An array of strings containing the program name, source file, and destination file.
 * Return: 0 on success, 97, 98, or 99 on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	return (cp_file(argv[1], argv[2]));
}

/**
 * cp_file - Copy the contents of one file to another.
 * @src: The source file path.
 * @dest: The destination file path.
 * Return: 0 on success, 97, 98, or 99 on failure.
 */
int cp_file(char *src, char *dest)
{
	int fd_src, fd_dest;
	ssize_t n;
	char buffer[1024];

	fd_src = open(src, O_RDONLY);
	if (fd_src == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		return (98);
	}

	fd_dest = open(dest, O_CREAT | O_WRONLY, 0664);
	if (fd_dest == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest);
		close(fd_src);
		return (99);
	}

	while ((n = read(fd_src, buffer, 1024)) > 0)
	{
		if (write(fd_dest, buffer, n) != n)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest);
			close(fd_src);
			close(fd_dest);
			return (99);
		}
	}

	if (n < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		close(fd_src);
		close(fd_dest);
		return (98);
	}

	if (close(fd_src) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_src);
		close(fd_dest);
		return (100);
	}

	if (close(fd_dest) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_dest);
		return (100);
	}

	return (0);
}
