#include "main.h"

/**
* flip_bits - Counting The Number Of Bits To Change
* To Get From One Number To Another
* @n: The First Number
* @m: The Second Number
*
* Return: The Number Of Bits To Be Change
*/

unsigned int flip_bits(unsigned long int n, unsigned long int m)

{
	int i, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		current = exclusive >> i;
		if (current & 1)
			count++;
	}

	return (count);
}
