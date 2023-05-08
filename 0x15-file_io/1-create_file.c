#include "main.h"

/**
* create_file - Creates the FILE.
* @filename: is A Pointer To The NAME Of The FILE To Create.
* @text_content: Is A Pointer To The String To Write To The FILE.
*
* Return: If THE Function FAILS - -1.
*         OTHERWISE - 1.
*/

int create_file(const char *filename, char *text_content)

{
	int fd, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(fd, text_content, len);

	if (fd == -1 || w == -1)
		return (-1);

	close(fd);

	return (1);
}
