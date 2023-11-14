#include "shell.h"
#include <string.h>  /* Add this line */

void read_input(void)
{
    char *input;
    size_t len = 0;

    while (1)
    {
        printf("#cisfun$ ");
        getline(&input, &len, stdin);

        /* Process the input */
        if (input)
        {
            size_t input_len = strlen(input);

            /* Remove the newline character from the input */
            if (input_len > 0 && input[input_len - 1] == '\n')
            {
                input[input_len - 1] = '\0';
            }

            execute_command(input);
        }
    }

    free(input);
}
