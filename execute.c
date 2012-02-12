#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
/** 
 * Returns a integer indicating whether the command provided
 * is a built in command or not. 
 * 0: Not built in command
 * 1: Built in command
 * Null: Not a command
 *
 */

int builtIn(char* command)
{
if(strcmp(command, "")==1)
{
	return null;
}
else if(strcmp(command,"cd")==1||strcmp(command,"exit")==1)
{
	return 1;
}
return 0;
}

int fork()
{	
	void runit(void);
	int pid;	/* process ID */
	switch (pid = fork()) {
	case 0:		/* a fork returns 0 to the child */
		runit();
		break;
	default:	/* a fork returns a pid to the parent */	
		sleep(5);
		printf("I'm still here!\n");
		break;										case -1:	/* something went wrong */							perror("fork");										exit(1);
	}
	exit(0);
}

void runit(void) {
	printf("About to run ls\n";
	exelp("ls","ls", "-aF", "/" , (char*)0);
	perror("execlp");
	exit(1);
}
	
