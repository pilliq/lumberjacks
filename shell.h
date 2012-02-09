#ifndef SHELL_H
#define SHELL_H

typedef int (*FunctPointer)();
struct funct
{
	char* command;
	FunctPointer f;
};
typedef struct funct* Function;

struct map
{
	Function entries [100];
};
typedef struct map* Dictionary;

char* parseCommandLine(char* arguments);
Dictionary buildFunctionDictionary();
void addFunctionToDictionary(Function f);
Function createFunction(char* command);
#endif
