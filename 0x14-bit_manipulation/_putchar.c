#include "main.h"
#include <unistd.h>

/**
* _putchar - Write The Char c To stdout
* @c: The Char To Print
*
* Return: On success 1.
* On error, -1 Returned, And errno Is Set Appropriately.
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
