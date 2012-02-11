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
	char* arguments = NULL;

        arguments = (char*) malloc (1024 * sizeof (char));

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
                    
         while (arguments != NULL && strcmp(arguments, "quit") != 0)
         {               
                        char **tokens;
			tokens = NULL;
                        tokens = parseWord(arguments);
                                
                        int count;
            
                        count = 0;
                            
                        while (tokens[count] != NULL)
                        {           
                                printf("%s\n", tokens[count]);
                                count++;
                        }   
                        /*printf("%s\n", tokens[1]);
                        printf("%s\n", tokens[2]);*/
			cleanArray(tokens);
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
void acceptFileInput()
{
	printf("input is coming from a file\n");		
}
/*************** (BUILT IN FUNCTIONS) **************************/
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
