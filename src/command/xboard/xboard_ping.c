#include <prophet/command.h>
#include <prophet/error_codes.h>

#include <stdio.h>
#include <string.h>

/**
 * \brief Execute the xboard ping command 
 * 
 * Respond to the ping N command with a pong N.  
 *
 * \param input         the user entered input 
 * \param exit_status   Pointer to receive exit status.  A non-zero 
 *                      status indicates the program should exit.
 *
 * \return 0 on successful execution, and non-zero on failure
 */
int xboard_ping(const char* input, int* exit_status)
{
    /* verify the command */
    if (0 != strncmp("ping", input, 4))
    {
        return P4_ERROR_CMD_INCORRECT_COMMAND;
    }

    /* is the command long enough to contain an argument? */
    if (strlen(input) < 6)
    {
        return P4_ERROR_CMD_XBOARD_PING_MISSING_N;   
    }

    /* attempt to read the N parameter */
    int n;
    if (1 != sscanf(input + 5, "%d", &n))
    {
        return P4_ERROR_CMD_XBOARD_PING_MISSING_N;
    }

    printf("pong %d\n", n);
  
    *exit_status = 0;

    return 0;
}
