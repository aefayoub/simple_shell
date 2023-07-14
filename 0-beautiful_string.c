#include <stdio.h>
#include "main.h"

/**
 * print_strings - Prints an array of strings.
 * @str_array: The array of strings.
 * @num_strings: The number of strings in the array.
 */
void print_strings(const char **str_array, int num_strings)
{
	int i;

	if (str_array != NULL && num_strings > 0)
	{
		for (i = 0; i < num_strings; i++)
		{
			if (str_array[i] != NULL)
			{
				printf("%s\n", str_array[i]);
			}
		}
	}
}

