#include "main.h"

/**
* get_bit - Returning The Value Of The Bit At An Index In The Decimal Number
* @n: Numbers To Search
* @index: Index of The Bit
*
* Return: The Values Of The Bit
*/

int get_bit(unsigned long int n, unsigned int index)

{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}
