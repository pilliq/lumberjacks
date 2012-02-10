#ifndef UTIL_H
#define UTIL_H


char** initializeArray(char** array);
void cleanArray(char** array);
char** parseWord(char* argument);
char* createWord (char* string, int startIndex, int numberOfCharacters);
int countCharacters(char* string, int startPoint);   
#endif
