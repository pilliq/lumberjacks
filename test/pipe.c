#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void run(char ** cmd, int * ifd, int proc);

/* ifd = in fd, ofd = out fd */
void run(char** cmd, int* ifd, int proc) 
{
    int pid, status;
    
    switch(pid = fork()) {
        case 0: /* child */
		if(proc==0)
		{
                dup2(ifd[proc+1], proc+1);
                close(ifd[proc]);
		}
		else
		{
			dup2(ifd[proc-1],proc-1);
			close(ifd[proc]);
    		}
            execvp(cmd[0], cmd);
            perror(cmd[0]);

        default: 
            break;

        case -1:
            perror("fork");
            exit(1);
    }
}

int main (int argc, char** argv) 
{
   char *cmd1[] = { "/bin/ls", "-al", "/", 0 }; 
   char *cmd2[] = { "/usr/bin/tr", "a-z", "A-Z", 0 };
   int pid, status;
   int fd[2];
   int process=0;

   pipe(fd);
   run(cmd1, fd, process);
   process++;
   run(cmd2, fd, process);
   close(fd[0]); close(fd[1]);
   while ((pid = wait(&status)) != -1) /* pick up all the dead children */
       fprintf(stderr, "child process %d exits with %d\n", pid, WEXITSTATUS(status));
   exit(0);
}
