#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void push(stack_t **stack, int value, unsigned int line_number) {
    // Allocate memory for a new stack node
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    // Assign the value to the new node
    new_node->n = value;

    // Update the pointers to insert the new node at the beginning of the stack
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack != NULL) {
        (*stack)->prev = new_node;
    }

    // Update the stack pointer to point to the new node
    *stack = new_node;
}

void pall(stack_t *stack) {
    while (stack != NULL) {
        printf("%d\n", stack->n);
        stack = stack->next;
    }
}

