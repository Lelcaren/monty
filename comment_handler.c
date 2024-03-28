#include "monty.h"

/**
 * process_line - Process a line of input
 * @line: The line to process
 */
void process_line(char *line)
{
    char *opcode;

    /* Skip leading whitespace */
    while (isspace(*line))
        line++;

    /* Check if the line is a comment */
    if (*line == '#')
        return;  // Skip processing this line
    
    /* Extract the opcode */
    opcode = strtok(line, " \t\n");
    
    /* Process the opcode */
    if (opcode != NULL)
        execute_opcode(opcode);
}

/**
 * main - Main function
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    FILE *file;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        process_line(line);
    }

    free(line);
    fclose(file);
    return EXIT_SUCCESS;
}

