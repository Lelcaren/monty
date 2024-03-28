#include "monty.h"

/**
 * swap_top_two - Swaps the top two elements of the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
 *
 * Description: This function swaps the top two elements of the stack.
 */
void swap_top_two(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int stack_length = 0, temp;

	current = *head;
	while (current)
	{
		current = current->next;
		stack_length++;
	}

	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
