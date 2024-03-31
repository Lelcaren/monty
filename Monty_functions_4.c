#include "monty.h"

/**
 * monty_add - Adds the top two elements of the stack.
 * @stack: Pointer to the top node of the stack
 * @line_number: Current line number being executed
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_number, "add"));
        return;
    }

    (*stack)->next->n += (*stack)->n;
    tmp = (*stack)->next;
    monty_pop(stack, line_number);
    *stack = tmp;
}

/**
 * monty_sub - Subtracts the top element of the stack from the second top element.
 * @stack: Pointer to the top node of the stack
 * @line_number: Current line number being executed
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_number, "sub"));
        return;
    }

    (*stack)->next->n -= (*stack)->n;
    tmp = (*stack)->next;
    monty_pop(stack, line_number);
    *stack = tmp;
}

/**
 * monty_div - Divides the second top element of the stack by the top element.
 * @stack: Pointer to the top node of the stack
 * @line_number: Current line number being executed
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_number, "div"));
        return;
    }

    if ((*stack)->n == 0)
    {
        set_op_tok_error(div_error(line_number));
        return;
    }

    (*stack)->next->n /= (*stack)->n;
    tmp = (*stack)->next;
    monty_pop(stack, line_number);
    *stack = tmp;
}

/**
 * monty_mul - Multiplies the top two elements of the stack.
 * @stack: Pointer to the top node of the stack
 * @line_number: Current line number being executed
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_number, "mul"));
        return;
    }

    (*stack)->next->n *= (*stack)->n;
    tmp = (*stack)->next;
    monty_pop(stack, line_number);
    *stack = tmp;
}

/**
 * monty_mod - Computes the remainder of the division of the
 * second top element of the stack by the top element.
 * @stack: Pointer to the top node of the stack
 * @line_number: Current line number being executed
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_number, "mod"));
        return;
    }

    if ((*stack)->n == 0)
    {
        set_op_tok_error(div_error(line_number));
        return;
    }

    (*stack)->next->n %= (*stack)->n;
    tmp = (*stack)->next;
    monty_pop(stack, line_number);
    *stack = tmp;
}
