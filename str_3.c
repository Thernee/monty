#include "monty.h"

/**
 * get_int - Converts an integer to a string.
 * @number: The number to convert.
 *
 * Return: The string representation of the number.
 */
char *get_int(int number)
{
	long num_value = 0;
	unsigned int tmp;
	int length = 0;
	char *result;

	tmp = absolute_value(number);
	length = compute_buffer_length(tmp, 10);

	if (number < 0 || num_value < 0)
		length++;
	result = malloc(length + 1);
	if (!result)
		return (NULL);

	fill_buffer(tmp, 10, result, length);
	if (number < 0 || num_value < 0)
		result[0] = '-';

	return (result);
}

/**
 * absolute_value - Computes the absolute value of an integer.
 * @num: The integer to compute the absolute value of.
 *
 * Return: The absolute value of the integer.
 */
unsigned int absolute_value(int num)
{
	if (num < 0)
		return (-(unsigned int) num);
	return ((unsigned int) num);
}

/**
 * compute_buffer_length - Computes the length of the buffer needed for an unsigned integer.
 * @num: The number to compute the length for.
 * @base: The base of the number representation used by the buffer.
 *
 * Return: The length of the buffer.
 */
int compute_buffer_length(unsigned int num, unsigned int base)
{
	int length = 1;

	while (num > base - 1)
	{
		length++;
		num /= base;
	}
	return (length);
}

/**
 * fill_buffer - Fills the buffer with numbers.
 * @num: The number to convert to a string.
 * @base: The base number.
 * @buffer: The buffer to be filled.
 * @buffer_size: The size of the buffer.
 *
 * Return: void.
 */
void fill_buffer(unsigned int num, unsigned int base, char *buffer, int buffer_size)
{
	int remainder, i = buffer_size - 1;

	buffer[buffer_size] = '\0';
	while (i >= 0)
	{
		remainder = num % base;
		if (remainder > 9)
			buffer[i] = remainder + 87;
		else
			buffer[i] = remainder + '0';
		num /= base;
		i--;
	}
}

/**
 * is_digit - Checks if a string consists of digits.
 *
 * Return: 1 if the string consists of digits, 0 otherwise.
 */
int is_digit(void)
{
	int i = 0;

	if (globalvar.token2[0] == '-' || globalvar.token2[0] == '+')
		i++;
	while (globalvar.token2[i])
	{
		if (!isdigit(globalvar.token2[i]))
			return (0);
		i++;
	}
	return (1);
}
