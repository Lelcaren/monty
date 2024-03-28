#include "monty.h"

/**
 * push_to_stack - Pushes an element onto the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
 *
 * Description: This function adds a new node to the stack with the given
 * integer value.
 */
void push_to_stack(stack_t **head, unsigned int counter)
{
	int value, i = 0, negative = 0, invalid = 0;

	if (!bus.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (bus.arg[i] == '-')
	{
		negative = 1;
		i++;
	}

	for (; bus.arg[i]; i++)
	{
		if (bus.arg[i] < '0' || bus.arg[i] > '9')
		{
			invalid = 1;
			break;
		}
	}

	if (invalid)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	value = atoi(bus.arg);
	if (negative)
		value *= -1;

	if (bus.lifo == 0)
		add_node_to_stack(head, value);
	else
		add_node_to_queue(head, value);
}

