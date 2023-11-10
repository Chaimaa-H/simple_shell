#include "shell.h"

void read_input(void)
{
    char *input;
    size_t len = 0;

    while (1)
    {
        printf("#cisfun$ ");
        getline(&input, &len, stdin);
        /* Process the input */
        printf("%s", input);
    }
    free(input);
}
