#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "shell.h"
#include "util.h"
#define DELIMINATORS "\t "


/*************** (BUILT IN FUNCTIONS) **************************/

int CD (char* command)
{
	return chdir(command);
}

/*
char* parseCommandLine(char* arguments)
{
	int size = 0;
	
	char* commandLine = (char*) malloc (257 * sizeof (char));
	commandLine[256] = '\0';
	
	char* token = NULL;
    token = strtok(arguments, "| ");
    
	while (token != NULL)
    {
		commandLine[size] = token;
		size++;          
        token = strtok(NULL, "| ");
    } 
	return commandLine;	
}

Dictionary buildFunctionDictionary()
{
		
Function createFunction(char* command)
{
	if (strcmp(command, "cd") == 0)
	{
		Function function = malloc (sizeof (struct funct));
		function -> command = strdup(command);
		function -> f = CD; 	

}

*/
int main(int argc, char **argv)
{
	char* arguments = NULL;
	
	arguments = (char*) malloc (257 * sizeof (char));
	/* some code taken here: http://www.daniweb.com/software-development/c/tutorials/45806 */
	fputs("$ ", stdout);
	fflush(stdout);
	fgets(arguments, 1024, stdin);
	/*printf("%s\n", arguments);
	printf("%d\n", strlen(arguments));
	*/
	
	/* fix bug where when you press enter after typing command, you get a newline character
	at the end of your string. Add terminator character to the end */ 
	if (arguments[ (strlen(arguments) -1)] == '\n')
	{
		arguments[ (strlen(arguments) -1)] = '\0';
		
	}
	
	/* figure out way to handle tokens within single / double quotes */
	
	while (arguments != NULL && strcmp(arguments, "quit") != 0)
	{	
		char** tokens = NULL;
		tokens = parseWord(arguments);
		printf("%s\n", tokens[0]);
		free(tokens);	
		free(arguments);
		arguments = (char*) malloc (257 * sizeof (char));
		fputs("$ ", stdout);
        fflush(stdout);
        fgets(arguments, 1024, stdin);
		/* printf("%d:%s\n", strlen(arguments), arguments); */
        
		if (arguments[ (strlen(arguments) -1)] == '\n')
        {
			arguments[ (strlen(arguments) -1)] = '\0';
	    }
	}

	return 1;
} 
