#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void execute_command(char *command)
{
    pid_t pid;
    int status;

    if (access(command, F_OK) == -1)
    {
        fprintf(stderr, "Command not found: %s\n", command);
        return;
    }

    pid = fork();

    if (pid == 0)
    {
        /* Child process */
        char *args[2];
        args[0] = command;
        args[1] = NULL;
        execvp(command, args);
        perror("Error executing command");
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("Error forking");
    }
    else
    {
        /* Parent process */
        waitpid(pid, &status, 0);
    }
}
