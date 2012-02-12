#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
if(command == "")
{
	return null;
}
else if(command == "cd"||command == "exit")
{
	return 1;
}
return 0;
}
