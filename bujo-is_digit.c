#include "monty.h"

/**
 * bujo_isdigit - Entry point
 *
 * Return: if is digit  or not, return 1 else 0
 */
int bujo_isdigit(void)
{
	int i = 0;

	if (global_variable.int_input[0] == '-' ||
			global_variable.int_input[0] == '+')
		i++;
	while (global_variable.int_input)
	{
		if ((global_variable.int_input[i] >= '0' &&
				       (global_variable.int_input[i + 1] >= '0'
						|| global_variable.int_input[i + 1] == '\0')) &&
				(global_variable.int_input[i] <= '9' &&
				 (global_variable.int_input[i + 1] <= '9'
						 || global_variable.int_input[i + 1] == '\0')))
			return (1);
		else
			return (0);
		i++;
	}
	return (0);
}
