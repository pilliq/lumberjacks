#ifndef UTIL_H
#define UTIL_H

struct node
{
  /* array of strings that represent a single set of commands. 
    Should probably rename this */
  char** command;
  
  /* total number of commands (tokens) listed in this node */
  int size;
  struct node *next;
};
typedef struct node* commandNode;
 
struct list
{
        commandNode head;
      
        /* number of commands inside the list */
        int size;
};

typedef struct list* Commands;


char** initializeArray(int size);
void cleanArray(char** array);

char** parseWord(char* argument);
char* createWord(char* string, int startIndex, int numberOfCharacters);
int countCharacters(char* string, int startPoint);
char**  addWord(char* command, char** array);

/* get a command / word from an array of characters given its index */
char* getCommand(char** argument, int index);
Commands initializeCommands();
void cleanCommands(Commands c);
/* look for the "index-th" node in the list and add a command to that node */
int addCommand(Commands c, char* command, int index);
commandNode addToList(commandNode head, commandNode node);
commandNode createNode(char** commands);
void destroyNode(commandNode cn);
void printAllCommands(Commands c);
#endif
