#include "monty.h"

void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);

/**
 * monty_rotl - Moves the top element of
 *a stack_t linked list to the bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tops, *bottoms;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	tops = (*stack)->next;
	bottoms = (*stack)->next;
	while (bottoms->next != NULL)
		bottoms = bottoms->next;

	tops->next->prev = *stack;
	(*stack)->next = tops->next;
	bottoms->next = tops;
	tops->next = NULL;
	tops->prev = bottoms;

	(void)line_number;
}

/**
 * monty_rotr - Rotates the bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tops, *bottoms;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	tops = (*stack)->next;
	bottoms = (*stack)->next;
	while (bottoms->next != NULL)
		bottoms = bottoms->next;

	bottoms->prev->next = NULL;
	(*stack)->next = bottoms;
	bottoms->prev = *stack;
	bottoms->next = tops;
	tops->prev = bottoms;

	(void)line_number;
}

/**
 * monty_stack - Converts a queue to a stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - Converts a stack to a queue.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
