#include "main.h"

/**
* get_endianness - Checking If The Machine As Little Or Big endian
* Return: 0 For Big, 1 For Little
*/

int get_endianness(void)

{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}
