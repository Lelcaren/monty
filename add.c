#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 1024

typedef struct Stack {
    int items[STACK_SIZE];
    int top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    stack->top = -1;
    return stack;
}

void push(Stack* stack, int value) {
    if (stack->top == STACK_SIZE - 1) {
        fprintf(stderr, "Error: stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = value;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        fprintf(stderr, "Error: can't pop an empty stack\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

void add(Stack* stack) {
    if (stack->top < 1) {
        fprintf(stderr, "Error: can't add, stack too short\n");
        exit(EXIT_FAILURE);
    }
    int operand1 = pop(stack);
    int operand2 = pop(stack);
    push(stack, operand1 + operand2);
}

void pall(Stack* stack) {
    int i;
    for (i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->items[i]);
    }
}

int main(int argc, char *argv[]) {
    // Check if filename is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Initialize stack
    Stack* stack = createStack();

    // Read file line by line
    char line[256];
    int line_number = 0;
    while (fgets(line, sizeof(line), file)) {
        line_number++;

        // Tokenize line
        char *opcode = strtok(line, " \n");
        if (opcode != NULL) {
            // Execute opcode
            if (strcmp(opcode, "push") == 0) {
                char *arg = strtok(NULL, " \n");
                if (arg == NULL) {
                    fprintf(stderr, "L%d: usage: push integer\n", line_number);
                    return EXIT_FAILURE;
                }
                int value = atoi(arg);
                push(stack, value);
            } else if (strcmp(opcode, "pop") == 0) {
                pop(stack);
            } else if (strcmp(opcode, "pall") == 0) {
                pall(stack);
            } else if (strcmp(opcode, "swap") == 0) {
                swap(stack);
            } else if (strcmp(opcode, "add") == 0) {
                add(stack);
            } else {
                fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
                return EXIT_FAILURE;
            }
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}
