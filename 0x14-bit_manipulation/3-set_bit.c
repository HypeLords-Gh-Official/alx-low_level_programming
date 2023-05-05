#include "main.h"

/**
* set_bit - Seting The Bit At a Given Iindex To 1
* @n: Pointer To The Number To Be Changed
* @index: Index Of The Bit To Set To 1
*
* Return: 1 For Success, -1 For Failure
*/

int set_bit(unsigned long int *n, unsigned int index)

{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
