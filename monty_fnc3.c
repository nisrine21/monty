#include "monty.h"

void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);

/**
 * monty_nop - Implements a do-nothing behavior for the Monty opcode 'nop'.
 * @stack: Points to the head node of a stack_t linked list.
 * @line_number: Represents the current line number
 *in the Monty bytecodes file.
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * monty_pchar - Outputs the character stored in the top element
 * of a stack_t linked list.
 * @stack: Points to the head node of a stack_t linked list.
 * @line_number: Denotes the present line number within a Monty bytecodes file.
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->a < 0 || (*stack)->next->a > 127)
	{
		set_op_tok_error(pchar_error(line_number,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stacks)->next->a);
}

/**
 * monty_pstr - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->a != 0 && (tmp->a > 0 && tmp->a <= 127))
	{
		printf("%c", tmp->a);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_number;
}
