#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
* create_buffer - Allocates 1024 BYTES For The BUFFER.
* @file: The NAME Of The FILE BUFFER Is Storing CHARACTERS For.
*
* Return: Is A Pointer To The newly-allocated BUFFER.
*/

char *create_buffer(char *file)

{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
* close_file - Closes The FILE Descriptors.
* @fd: The FILE Descriptor To Be CLOSED.
*/

void close_file(int fd)

{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
* main - Copies The CONTENTS Of THE FILE To Another FILE.
* @argc: The NUMBER Of Arguments Supplied To The Program.
* @argv: is An ARRAY Of Pointers For The Arguments.
*
* Return: 0 on success.
*
* Description: IF The Argument COUNT Is INCORRECT - exit code 97.
* If file_from does Not EXIST Or Can Not Be READ - exit code 98.
* If file_to cannot Be CREATED Or WRITTEN to - exit code 99.
* If file_to or file_from Can Not Be CLOSED - exit code 100.
*/

int main(int argc, char *argv[])

{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
