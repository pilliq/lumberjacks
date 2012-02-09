#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include <unistd.h>
#define DELIMINATORS "\t "


/*************** (BUILT IN FUNCTIONS) **************************/
int CD (char* command)
{
	return chdir(command);
}

char* parseCommandLine(char* arguments)
{
	int size = 0;
	/* assume there are 256 tokens */
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
}
int main(int argc, char **argv)
{
	int i;
	char* arguments = NULL;
	
	arguments = (char*) malloc (257 * sizeof (char));
	/* some code taken here: http://www.daniweb.com/software-development/c/tutorials/45806 */
	fputs("$ ", stdout);
	fflush(stdout);
	fgets(arguments, 257, stdin);
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
		char* token = NULL;
		token = strtok(arguments, DELIMINATORS);
		while (token != NULL)
		{	
			/* printf("%d\n", token[0]);
			printf("%d\n", token[strlen(token)-1]); */
			printf("%s\n", token );
			if (strcmp(token, "|") == 0)
			{
				printf("end of command. create new command\n");
			}
			//free(token);			
			token = strtok(NULL, DELIMINATORS);
		}	
		free(arguments);
		arguments = (char*) malloc (257 * sizeof (char));
		fputs("$ ", stdout);
        fflush(stdout);
        fgets(arguments, 257, stdin);
		/* printf("%d:%s\n", strlen(arguments), arguments); */
        
		if (arguments[ (strlen(arguments) -1)] == '\n')
        {
			arguments[ (strlen(arguments) -1)] = '\0';
	    }
	
		//printf("Freed data\n");
	}

	return 1;
} 
