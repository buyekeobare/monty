#include "monty.h"

/**
 * bujo_get_opcodes - Parses the instruction with the function.
 * @input: type pointer extern var char
 * @stack: type pointer node of data struct
 * @line_number: line of instructions
 * Return: Retunr the funtion
 */
int bujo_get_opcodes(char *input, stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes_func[] = {
		{"push", bujo_push},
		{"pall", bujo_pall},
		{"pop", bujo_pop},
		{"add", bujo_add},
		{"nop", bujo_nop},
		{"sub", bujo_sub},
		{"pall", bujo_pall},
		{"pint", bujo_pint},
		{"swap", bujo_swap},
		{"mul", bujo_mul},
		{"div", bujo_div},
		{"pchar", bujo_pchar},
		{"mod", bujo_mod},
		{"\n", bujo_nop},
		{" ", bujo_nop },
		{"\t", bujo_nop },
		{"pstr", bujo_pstr },
		{"rotl", bujo_rotl },
		{"rotr", bujo_rotr },
		{"stack", bujo_stack },
		{"queue", bujo_queue },
		{NULL, NULL }
	};
	int j, indicatorFlag = 0;
	char *option = NULL;

	if (stack == NULL || input == NULL)
		return (0);
	option = input;
	for (j = 0; opcodes_func[j].opcode; j++)
	{
		if (strcmp(option, opcodes_func[j].opcode) == 0)
		{
			indicatorFlag = 1;
			opcodes_func[j].f(stack, line_number);
			break;
		}
	}
	if (indicatorFlag == 0)
		unknown_instruction_error(input, line_number);
	return (0);
}
