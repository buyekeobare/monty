#include "monty.h"
/**
 * bujo_interpreter - setting up everything for interpretation
 * Return: void
 */
void bujo_interpreter(void)
{
	int index = 0, indicatorFlag = 0, indicatorFlag2 = 0;
	ssize_t shows;
	size_t toshows = 0;
	char *input = NULL;
	stack_t *stack = NULL;

	shows = getline(&global_variable.buffer, &toshows, global_variable.fd);
	if (global_variable.buffer[0] == '#')
		shows = getline(&global_variable.buffer, &toshows, global_variable.fd);
	while (shows >= 0)
	{
		indicatorFlag = 0;
		indicatorFlag2 = 0;
		index++;
		input = strtok(global_variable.buffer, DELIM);
		global_variable.int_input = strtok(NULL, DELIM);
		if (input == NULL)
		{
			indicatorFlag2 = 1;
			bujo_nop(&stack, index);
		}
		if (indicatorFlag2 == 0)
		{
			if (input[0] == '#')
			{
				shows = getline(&global_variable.buffer, &toshows, global_variable.fd);
				indicatorFlag = 1;
			}
		}
		if (indicatorFlag == 0)
		{
			bujo_get_opcodes(input, &stack, index);
			shows = getline(&global_variable.buffer, &toshows, global_variable.fd);
		}
	}
	_freestack(stack);
}
