#include "monty.h"

/**
 * f_div - divides the second top element of the stack by the top element.
 * @head: double pointer to the head of the stack
 * @counter: line number being executed
 */
void f_div(stack_t **head, unsigned int counter)
{
    stack_t *h;
    int len = 0, aux;

    h = *head;
    
    /* Count the number of elements in the stack */
    while (h)
    {
        h = h->next;
        len++;
    }
    
    /* Check if the stack contains at least two elements */
    if (len < 2)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    
    /* Check if the top element of the stack is zero */
    if ((*head)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    
    /* Perform the division operation */
    aux = (*head)->next->n / (*head)->n;
    
    /* Update the second top element of the stack with the result */
    (*head)->next->n = aux;
    
    /* Adjust the stack pointer to remove the top element */
    h = *head;
    *head = (*head)->next;
    free(h);
}

