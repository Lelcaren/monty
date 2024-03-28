#include "monty.h"

/**
 * add_stack - adds the top two elements of the stack.
 * @head: stack head
 * @line_number: line number of the opcode in the Monty file
 * Description: This function adds the top two elements of the stack.
 * Return: no return value
 */
void add_stack(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	int len = 0, result;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	result = tmp->n + tmp->next->n;
	tmp->next->n = result;
	*head = tmp->next;
	free(tmp);
}

