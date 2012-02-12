#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void run(char ** cmd, int * ifd, int * ofd);

/* ifd = in fd, ofd = out fd */
void run(char** cmd, int* ifd, int* ofd) 
{
    int pid, status;
    switch(pid = fork()) {
        case 0: /* child */
            if (ifd != NULL) {
                dup2(ifd[0], 0);
                close(ifd[1]);
            }
            if (ofd != NULL) {
                dup2(ofd[1], 1); 
                close(ifd[0]);
            }
            execvp(cmd[0], cmd);
            perror(cmd[0]);
            break;

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

   pipe(fd);
   run(cmd1, NULL, fd);
   printf("executing cmd 2\n");
   run(cmd2, fd, NULL);
   close(fd[0]); close(fd[1]);
   while ((pid = wait(&status)) != -1) /* pick up all the dead children */
       fprintf(stderr, "child process %d exits with %d\n", pid, WEXITSTATUS(status)); 
   exit(0);
}
