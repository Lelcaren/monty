#include "monty.h"

/**
 * f_stack - Sets the stack mode (LIFO)
 * @head: Pointer to the head of the stack
 * @counter: Line number of the current operation
 * Description: Sets the stack mode to LIFO (Last In, First Out)
 *              for stack operations.
 * Return: No return value
 */
void f_stack(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;
    bus.lifi = 0;
}

