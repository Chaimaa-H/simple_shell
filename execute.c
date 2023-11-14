#include "shell.h"

/**
 * execute_command - Execute a command.
 * @command: The command to execute.
 */
void execute_command(char *command)
{
    pid_t pid;
    int status;

    if (access(command, F_OK) == -1)
    {
        fprintf(stderr, "%s: command not found\n", command);
        return;
    }

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        /* Child process */
        if (execlp(command, command, (char *)NULL) == -1)
        {
            perror("execlp");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* Parent process */
        waitpid(pid, &status, 0);
    }
}
