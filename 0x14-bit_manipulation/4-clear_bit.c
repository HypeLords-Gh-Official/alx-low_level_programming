#include "main.h"

/**
* clear_bit - Seting The Value Of The Given Bit To 0
* @n: Pointer To The Number To Change
* @index: Index Of The Bit To Clear
*
* Return: 1 For Success, -1 For Failure
*/

int clear_bit(unsigned long int *n, unsigned int index)

{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
