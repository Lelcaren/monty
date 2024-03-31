#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the Monty ByteCode file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Initialize stack
    stack_t *stack = NULL;

    // Parse and execute instructions
    parse_instructions(file, &stack);

    // Close the file
    fclose(file);

    return 0;
}

