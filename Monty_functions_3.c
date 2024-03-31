#include "monty.h"

/**
 * monty_pchar - Prints the character at the top of the stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: Prints the character at the top of the stack,
 *              followed by a new line.
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL)
    {
        set_op_tok_error(pchar_error(line_number, "stack empty"));
        return;
    }

    if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
    {
        set_op_tok_error(pchar_error(line_number, "value out of range"));
        return;
    }

    printf("%c\n", (*stack)->next->n);
}

/**
 * monty_pstr - Prints the string starting at the top of the stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: Prints the string starting at the top of the stack,
 *              followed by a new line. Stops printing when the stack
 *              is over, the value of the element is 0, or the element
 *              is not in the ascii table.
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = (*stack)->next;

    (void)line_number;

    while (tmp && tmp->n != 0 && (tmp->n >= 0 && tmp->n <= 127))
    {
        printf("%c", tmp->n);
        tmp = tmp->next;
    }

    printf("\n");
}

/**
 * monty_rotl - Rotates the stack to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The top element of the stack becomes the last one,
 *              and the second top element of the stack becomes the
 *              first one.
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = (*stack)->next;

    (void)line_number;

    if (tmp && tmp->next)
    {
        while (tmp->next)
            tmp = tmp->next;

        tmp->next = (*stack)->next;
        (*stack)->next->prev = tmp;
        (*stack)->next = (*stack)->next->next;
        (*stack)->next->prev->next = NULL;
        (*stack)->next->prev = NULL;
    }
}

/**
 * monty_rotr - Rotates the stack to the bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The last element of the stack becomes the top one.
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = (*stack)->next;

    (void)line_number;

    if (tmp && tmp->next)
    {
        while (tmp->next)
            tmp = tmp->next;

        tmp->prev->next = NULL;
        tmp->prev = NULL;
        tmp->next = (*stack)->next;
        (*stack)->next->prev = tmp;
        (*stack)->next = tmp;
    }
}

