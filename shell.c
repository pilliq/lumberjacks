#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "shell.h"
#include "util.h"

#define DELIMINATORS "\t "

void acceptUserInput()
{
	Commands c; 
	char* arguments;
	int index;
	int count;
	char **tokens;
	
	
	
	arguments = NULL;
	arguments = (char*) malloc (1024 * sizeof (char));
	
	fputs("$ ", stdout);
	fflush(stdout);
	fgets(arguments, 1024, stdin);
	/*printf("%s\n", arguments);
	 * printf("%d\n", strlen(arguments));
	 */
	
	/* fix bug where when you press enter after typing command, you get a newline character
	 * at the end of your string. Add terminator character to the end */ 
	
	if (arguments[ (strlen(arguments) -1)] == '\n')
	{
		arguments[ (strlen(arguments) -1)] = '\0';
	}
	
	while (arguments != NULL && strcmp(arguments, "quit") != 0)
	{
		c = initializeCommands(); 
		tokens = NULL;
		tokens = parseWord(arguments);
		count = 0;
		index = count;
		while (tokens[count] != NULL)
		{
			if (strcmp(tokens[count], "|") == 0)
			{
				index++;
				printf("New Command\n");
				count++;
			}
			addCommand(c, tokens[count], index);
			printf("Print Current Commands\n");
			printAllCommands(c);
			count++;
		}
		
		/* Assuming execution of commands go here */
		cleanCommands(c);
		cleanArray(tokens, 50);
		tokens = NULL;
		free(arguments);
		arguments = (char*) malloc (1024 * sizeof (char));
		fputs("$ ", stdout);
		fflush(stdout);
		fgets(arguments, 1024, stdin);
		/* printf("%d:%s\n", strlen(arguments), arguments); */
	
		if (arguments[ (strlen(arguments) -1)] == '\n')
		{
			arguments[ (strlen(arguments) -1)] = '\0';
		}
	}
	if (arguments != NULL)
	{
		free(arguments);
	}
}

/* NOT SURE HOW TO HANDLE FILE INPUT */
void acceptFileInput()
{
	printf("input is coming from a file\n");		
}

int main(int argc, char **argv)
{
	if (isatty(stdin) != 1)
	{
		acceptUserInput();
	}
	else
	{
		acceptFileInput();
	}
	return 1;
} 
