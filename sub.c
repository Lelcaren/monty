#include "monty.h"

/**
 * subtract - Subtracts the top element of the stack from the second top element
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
 *
 * Description: This function subtracts the top element of the stack from the
 * second top element and replaces the second top element with the result.
 */
void subtract(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int result, num_nodes;

	temp = *head;
	for (num_nodes = 0; temp != NULL; num_nodes++)
		temp = temp->next;

	if (num_nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	result = temp->next->n - temp->n;
	temp->next->n = result;
	*head = temp->next;
	free(temp);
}

