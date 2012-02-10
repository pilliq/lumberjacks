#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "util.h"


char** initializeArray(char** array)
{
	int i;
	
	for(i = 0; i < 1024; i++)
	{
		array[i] = NULL;	
	}
	return array;
} 

void cleanArray(char** array)
{
	int count; 
	for (count = 0; count < 1024; count++)
	{
		if (array[count] != NULL)
		{
			free(array[count]);
			array[count] = NULL;
		}
	}
	free(array);
}
char** parseWord(char* argument)
{
	char** array;	
	array = (char**) malloc (1024 * sizeof (char*) );
	array = initializeArray(array);		
 
	int startPoint;
	int size;
	int i;

	i = 0;
	startPoint = 0;
	while (startPoint < strlen(argument))
	{
		size = 0;
		if (startPoint == strlen(argument))
		{
			break;
		}
		size = countCharacters(argument, startPoint);
				
		if (size == -1)
		{
			printf("An error has occurred here\n");
			exit(0);
		}
		else if (size > 0)
		{
			printf("Size of new word: %d\n", size);
			array[i] = createWord(argument, startPoint, size);
			size++;
			startPoint+=size;
			i++;
		}
		/* we run into a deliminator */
		else
		{
			startPoint++;
		}
	}
	
	return array;	
} 

char* createWord (char* string, int startIndex, int numberOfCharacters)
{		
	char * resultWord = (char*) malloc ((numberOfCharacters+1)* sizeof (char) );
	memcpy(resultWord, string + startIndex, numberOfCharacters);
	resultWord[numberOfCharacters] = '\0';
	return resultWord;
}

/* returns a non negative number determining the size of our word

ERROR: -1 if we run into a string that's not quoted properly
(ex. : "hello bob ) */
int countCharacters(char* string, int startPoint)
{
	/* size: number of characters we have to allocate for the new string 
		inc: simple pointer to the current index we're looking at in the 
		loop
	
		openQuotes: indicates whether or not we are in quoted string
			1 = if the string is in quotes
			0 = if the string has finally been closed of quotes or no
				quotes exist
			
			-1 = mismatching quotes
	*/
	int size;
	int inc;
	
	int openDoubleQuotes, openSingleQuotes;
	openDoubleQuotes = 0;
	openSingleQuotes = 0;
	size = 0;
	for (inc = startPoint; inc < strlen(string); inc++)
	{
		/* if the current character */
		char currentCharacter = string[inc];
		
		/* if we run into a non-alphabetical character, check if they special characters
		first. If they aren't create a new word
		
		Otherwise, keep counting characters */
		printf("Current char: %c %d\n", currentCharacter, currentCharacter); 
		if (isalpha(currentCharacter) == 0)
		{
			/* if we run into a quote character, assume either we are entering a quoted string
			or reaching the end of a quoted string */

			/* note, did not check if we run into a double quote, then a single quote. Should
			be a invalid string */
			if (currentCharacter == 39 || currentCharacter == 34)
			{
				/* if we run into a double quote character */
				if (openDoubleQuotes == 1)
				{	
					printf("Closed Quote\n");
					openDoubleQuotes = 0;
					/*printf("Make a word: %d\n", size);*/
					size++;
					return size;
				}
				else
				{	
					printf("Open Quote\n");
					openDoubleQuotes = 1;
					size++;
				}
			}
			
			else
			{
				/* if this is the pipe symbol and its the first character we're encountering when we enter the function?
				I just consider that as its own token */
				if (currentCharacter == 124 && size == 0)
				{
					size++;
					return size;
				}
				else
				{
					printf("Single %d\n", openSingleQuotes);
					printf("double %d\n", openDoubleQuotes);
					
					if (openDoubleQuotes == 0)
					{
						return size;
					}
				
					else
					{	
						size++;
					}
				}	
			}
		}
		else
		{ 
			size++;
		}
	}
	
	if (openDoubleQuotes == 1 || openSingleQuotes == 1)
	{
		return -1;
	}
	return size;
}
