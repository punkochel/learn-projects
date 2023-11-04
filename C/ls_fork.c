#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    __pid_t p;
    p = fork();
    if(p == -1) { /* if fuilure */
        perror("fork");
        return 1;
    }
    if(p == 0) { /* child process */
        execlp("ls", "ls", "-a", "-l", "/var", NULL);
        perror("ls");
        exit(1);
    }
    wait(NULL);
    printf("Child process completed\n");
    return 0;
}
