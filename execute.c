#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
/** 
 * Returns a integer indicating whether the command provided
 * is a built in command or not. 
 * 0: Not built in command
 * 1: Built in command
 * Null: Not a command
 *
 */

int builtIn(char* command)
{
if(strcmp(command, "")==1)
{
	return null;
}
else if(strcmp(command,"cd")==1||strcmp(command,"exit")==1)
{
	return 1;
}
return 0;
}
