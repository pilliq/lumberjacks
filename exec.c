/* Phillip Quiza, Gregory Job, Mark Jarrell, Gordon Arnold */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

#include "util.h"

void exec(Commands c) {
    commandNode ptr;

    while (ptr = c->head) {
        char* argptr; 
        while (argptr =
        printf("Command: %s\n", ptr->command);
    }
}
