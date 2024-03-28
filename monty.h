#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define DELIM " \n\t\a\b"
#define STACK 0
#define QUEUE 1
typedef unsigned int ui;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct GLOBAL - struct with variable globals
 * @int_input: integer
 * @fd: points to the previous element of the stack (or queue)
 * @buffer: points to the next element of the stack (or queue)
 * @mode: checks for the mode of entry. Queue or Stack
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct GLOBAL
{
	char *int_input;
	FILE *fd;
	char *buffer;
	int mode;

} GLOBAL_VAR;

extern GLOBAL_VAR global_variable;
/* Brains of the interpreter */
void bujo_interpreter(void);

/*error functions*/
void display_usage_error(void);
void display_malloc_error(void);
void display_open_error(char *file);
void handle_push_error(unsigned int line_number);
void unknown_instruction_error(char *input, unsigned int line_number);
void bujo_op_error(unsigned int line_number, char *op_error);
void bujo_pop_error(unsigned int line_number);
void bujo_pchar_error(unsigned int line_number, char *error_msg);
void bujo_div_error(unsigned int line_number);
void bujo_pint_error(unsigned int line_number);


/*functions for the Node*/
void _freestack(stack_t *stack);
void free_global_variables(void);
int create_stack_node(stack_t **stack);
stack_t *create_nodestack_front(stack_t **head, int n);
stack_t *create_nodestack_end(stack_t **head, int n);
stack_t *add_newNode(stack_t **head, int n);

/*The bujo_op_func and other helper functions*/
int bujo_isdigit(void);
void bujo_push(stack_t **stack, unsigned int line_number);
void bujo_pall(stack_t **stack, unsigned int line_number);
void bujo_pop(stack_t **stack, unsigned int line_number);
void bujo_swap(stack_t **stack, unsigned int line_number);
void bujo_pchar(stack_t **stack, unsigned int line_number);
void bujo_mul(stack_t **stack, unsigned int line_number);
void bujo_add(stack_t **stack, unsigned int line_number);
void bujo_sub(stack_t **stack, unsigned int line_number);
void bujo_div(stack_t **stack, unsigned int line_number);
void bujo_rotl(stack_t **stack, unsigned int line_number);
void bujo_pstr(stack_t **stack, unsigned int line_number);
void bujo_mod(stack_t **stack, unsigned int line_number);
void bujo_rotr(stack_t **stack, unsigned int line_number);
int bujo_get_opcodes(char *input, stack_t **stack, unsigned int line_number);
void bujo_nop(stack_t **stack, unsigned int line_number);
void bujo_stack(stack_t **stack, unsigned int line_number);
void bujo_queue(stack_t **stack, unsigned int line_number);
void bujo_pint(stack_t **stack, unsigned int line_number);

#endif
