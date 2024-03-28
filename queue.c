#include "monty.h"

/**
 * f_queue - Sets the queue mode (FIFO)
 * @head: Pointer to the head of the stack
 * @counter: Line number of the current operation
 * Description: Sets the queue mode to FIFO (First In, First Out)
 *              for stack operations.
 * Return: No return value
 */
void f_queue(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;
    bus.lifi = 1;
}

/**
 * addqueue - Adds a new node to the tail of the stack
 * @head: Pointer to the head of the stack
 * @n: Value to be added to the new node
 * Description: This function adds a new node to the tail of the stack.
 * Return: No return value
 */
void addqueue(stack_t **head, int n)
{
    stack_t *new_node, *aux;

    aux = *head;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    new_node->n = n;
    new_node->next = NULL;
    if (aux)
    {
        while (aux->next)
            aux = aux->next;
    }
    if (!aux)
    {
        *head = new_node;
        new_node->prev = NULL;
    }
    else
    {
        aux->next = new_node;
        new_node->prev = aux;
    }
}

