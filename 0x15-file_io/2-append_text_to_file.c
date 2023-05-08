#include "main.h"

/**
* append_text_to_file - Append The Text At The End Of The FILE.
* @filename: Is A Pointer To The NAME Of The FILE.
* @text_content: The String To ADD To The END Of The FILE.
*
* Return: If The Function FAILS or Filename Is NULL - -1.
*         If The File Does Not EXIST The User Lacks WRITE Permissions - -1.
*         OTHERWISE - 1.
*/

int append_text_to_file(const char *filename, char *text_content)

{
	int o, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	w = write(o, text_content, len);

	if (o == -1 || w == -1)
		return (-1);

	close(o);

	return (1);
}
