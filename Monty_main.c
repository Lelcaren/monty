#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point for Monty interpreter
 * @argc: Number of arguments passed to the program
 * @argv: Array of pointers to arguments passed to the program
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int argc, char **argv)
{
    FILE *script_fd;
    int exit_code = EXIT_SUCCESS;

    if (argc != 2)
        return usage_error();

    script_fd = fopen(argv[1], "r");
    if (script_fd == NULL)
        return f_open_error(argv[1]);

    exit_code = run_monty(script_fd);

    fclose(script_fd);
    return exit_code;
}

