#include "shell.h"

/**
 * digit_count - Count the number of digits
 * @number: Integer
 *
 * Return: Digit count
 */
int digit_count(int number)
{
	int count;

	for (count = 1; number >= 10; count++)
	{
		number /= 10;
	}
	return (count);
}

/**
 * _power - Exponent
 * @digit_count: Digit count
 *
 * Return: 10 to digit_count power
 */
int _power(int digit_count)
{
	int count, power = 1;

	for (count = 1; digit_count > count; digit_count--)
		power *= 10;
	return (power);
}

/**
 * digit_to_char - Converts digit to character
 * @number: Integer
 *
 * Return: character
 */
int digit_to_char(int number)
{
	int c = '0' + number;

	return (c);
}

/**
 * number_to_string - Converts number to string
 * @number: Integer
 *
 * Return: String
 */
char *number_to_string(int number)
{
	int rtp, count = digit_count(number), i;
	char *array = malloc((count + 1) * sizeof(char));

	for (i = 0; count > 0; count--, i++)
	{
		int power = _power(count);

		rtp = number / power;
		number -= (power * rtp);
		array[i] = digit_to_char(rtp);
	}
	array[i] = '\0';

	return (array);
}

/**
 * string_to_number - Converts string to a number
 * @string: String
 *
 * Return: Integer
 */
int string_to_number(char *string)
{
	size_t size = strlen(string);
	size_t i, j;
	int sum = 0;
	char *result = strstr(string, "-");

	if (result != NULL)
	{
		for (i = 1, j = size - 1; i < size; i++, j--)
		{
			sum += (string[i] - '0') * _power(j);
		}
		return (sum * -1);
	}
	else
	{
		for (i = 0, j = size; i < size; i++, j--)
		{
			sum += (string[i] - '0') * _power(j);
		}
		return (sum);
	}
}
