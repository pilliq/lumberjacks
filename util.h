#ifndef UTIL_H
#define UTIL_H

struct node
{
  char** command;
  int size;
  struct node *next;
};
typedef struct node* commandNode;
 
struct list
{
        commandNode head;
        int size;
};

typedef struct list* Commands;

Commands initializeCommands();
void cleanCommands(Commands c);
char** initializeArray(int size);
void cleanArray(char** array);

char** parseWord(char* argument);
char* createWord(char* string, int startIndex, int numberOfCharacters);
int countCharacters(char* string, int startPoint);
char* getCommand(char** argument, int index);
char**  addWord(char* command, char** array);

int addCommand(Commands c, char* command, int index);
commandNode addToList(commandNode head, commandNode node);
commandNode createNode(char** commands);
void destroyNode(commandNode cn);
void printAllCommands(Commands c);
#endif
