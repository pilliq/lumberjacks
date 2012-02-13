#ifndef SHELL_H
#define SHELL_H

#include "util.h"

void run(char** cmd);
void execute(Commands c);
void acceptUserInput();
void acceptFileInput();
#endif
