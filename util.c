#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "util.h"

#define MAXCOMMANDS 50


/** Linked List operations **/
/**
 * Returns a node_ptr to the head of linked list
 * with item is added.
 *
 * Can be used to create a new linked list by passing NULL to head.
 * This way, the new linked list will have one element, item.
 */
Commands initializeCommands()
{
	Commands c;
	c = (Commands) malloc (sizeof(struct list));
	c->head = NULL;
	c->size = 0;
	return c;
}

commandNode createNode(char** commands)
{
	commandNode node;
	
	node = (commandNode) malloc(sizeof(struct node));
	node->command = commands;
	node->next = NULL;
	node->size = 1;
	return node;
}

commandNode addToList(commandNode head, commandNode node)
{
	if (head == NULL)
	{
		head = node;
		return head;
	}
	
	else if (head->next == NULL)
	{
		head->next = node;
		return head;
	}
	commandNode ptr = head;
		
	while (ptr->next == NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = node;
	
	return head;
}

int addCommand(Commands c, char* command, int index)
{
	printf("Requested Index %d\n", index);
	char** commands;
	char* newCommand; 
	commandNode ptr;
	int i;
	
	if (c == NULL)
	{
		return -1;
	}
	if (index > c->size)
	{	
		return -1;
	}

	if (c->head == NULL)
	{
		printf("Empty Head\n");
		commands = initializeArray(50);
		newCommand = createWord(command, 0, strlen(command));
		
		commands[0] = newCommand;
		printf("New Word is %s\n", newCommand);
		c->head = createNode(commands);
		c->size++;
	}
	else
	{
		printf("Moving!\n");
		ptr = c->head;
		for (i = 0; i < index; i++)
		{
			ptr = ptr->next;
		}
		if (ptr == NULL)
		{
			printf("Adding To new Node\n");
			commands = initializeArray(50);
			newCommand = createWord(command, 0, strlen(command));
			commands[0] = newCommand;
			c->head = addToList(c->head, createNode(commands));
			c->size++;
		}
		else
		{
			printf("Adding to exisiting Node\n");
			newCommand = createWord(command, 0, strlen(command));
			ptr->command[ptr->size] = newCommand;
			ptr->size++;
		}
	}
	return 1;
}

void printAllCommands(Commands c)
{
	char** commands;
	int inc;
	if (c == NULL || c->head == NULL)
	{
		printf("Empty \n");
		return;
	}
	
	commandNode ptr = c->head;
	printf("-----------BEGIN-----------\n");
	while (ptr != NULL)
	{
		commands = ptr->command;
		
		inc = 0;
		
		while (inc < 50 && ptr->command[inc] != NULL)
		{
			printf("%s\n", ptr->command[inc]);
			inc++;	
		}
		ptr = ptr -> next;
	}
	printf("----------------DONE--------------\n");
	return;
}

/****** CLEANING LINKED LIST *********/ 
void destoryNode(commandNode node)
{
	if (node != NULL)
	{
		cleanArray(node->command, node->size);
	}
}


void cleanCommands(Commands c)
{
	printf("You're supposed to clean me\n");
	
	commandNode n, prev;
	
	if (c->head == NULL)
	{
		return;
	}
	
	n = c->head->next;
	prev = c->head;
	if (n == NULL) 
	{	
		cleanArray(prev->command, prev->size);
		free(prev);
	}
	else
	{	
		cleanArray(prev->command, prev->size);
		free(prev);
		prev = NULL;
		
		while (n != NULL)
		{
			cleanArray(n->command, n->size);
			free(prev);
			prev = n;
			n = n->next;
		}
		free(prev);
	}
	c->size = 0;
	free(c); 
}



/***************** STRING ARRAY OPERATIONS *************************/
char** initializeArray(int size)
{
        char** array;
        array = (char**) malloc (size * sizeof (char*) );
      
        int i;

        for(i = 0; i < size; i++)
        {
                array[i] = NULL;
        }
        return array;
}

void cleanArray(char** array, int size)
{
	int count;
	for (count = 0; count < size; count++)
	{
		printf("count %d\n", count);
		if (array[count] == NULL)
		{
			break;
		}
		if (array[count] != NULL)
		{
			printf("Free %s\n", array[count]);
			free(array[count]);
			array[count] = NULL;    
			printf("Completed\n");
		}
	}
	free(array);
}   

/******************** WORD OPERATIONS ******************/
char** addWord(char* command, char** array)
{
	int i;
	i = 0;		
	char* newWord;
	while (i != 1024)
	{
		printf("%d\n", i);
		if (array[i] == NULL)
		{
			array[i] = createWord(command, 0, strlen(command));
			return array;
		}
		else
		{
			i++;
		}
	}
	return NULL;
}


/* assume we found a pipe command and we have to move into another set of commands */

char** parseWord(char* argument)
{
	char** array;	
	array = (char**) malloc (1024 * sizeof (char*) );
	
	array = NULL;
	array = initializeArray(1024);		
 
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
			startPoint+=size;
			printf("Starting at: %d\n", startPoint);
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
		printf("Open Double quotes: %d\n", openDoubleQuotes);
		printf("Open Single quotes: %d\n", openSingleQuotes);
 
		if (isalpha(currentCharacter) == 0)
		{
			/* if we run into a quote character, assume either we are entering a quoted string
			or reaching the end of a quoted string */

			/* note, did not check if we run into a double quote, then a single quote. Should
			be a invalid string */
			if (currentCharacter == 39 || currentCharacter == 34)
			{
				if (currentCharacter == 34)
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
					if (openDoubleQuotes == 1)
                                        {
                                                size++;
                                        }
                                        else if (openDoubleQuotes == 0)
                                        {       
						if (openSingleQuotes == 0)
						{
                                                	printf("Open Single Quote\n");
                                                	openSingleQuotes = 1;
                                                	size++;
						}
						else
						{
							printf("Closed Single Quote\n");
							openSingleQuotes = 0;
							size++;
							return size;
						} 
                                        }	
				}
		
			}
			
			else
			{
				/* if this is the pipe symbol and its the first character we're encountering when we enter the function?
				I just consider that as its own token */
				
				if (currentCharacter == 124 && size == 0)
				{

					size++;
					inc--;
					return size;
				}
				else if (currentCharacter == 45 || currentCharacter == 47)
				{
					size++;
				}	
				else
				{

					/* we encountered a deliminator */
					
					/* if there's no quotes */
					
					if (openDoubleQuotes == 0 && openSingleQuotes == 0)
					{
						return size;
					} 
					/*
					if (openDoubleQuotes == 0 && openSingleQuotes == 1)
					{
						if (currentCharacter == 124 && size > 0)
                                   		{
                                              		return size;
                                       		}
					}
					else if (openDoubleQuotes == 1 && openSingleQuotes == 0)
					{
						if (currentCharacter == 124 && size > 0)
                                                {
							return size;
                                                }
					}
					*/
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
