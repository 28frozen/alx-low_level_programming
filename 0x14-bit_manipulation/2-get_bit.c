#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index in a decimal number.
 * @n: The decimal number to search.
 * @index: The index of the bit to retrieve (starting from 0).
 *
 * Return: The value of the bit at the specified index, or -1 if the index is
 *         out of range (greater than 63).
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}
